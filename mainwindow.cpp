#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget* p = takeCentralWidget();
    if(p)
        delete p;
    setDockNestingEnabled(true);
    setCentralWidget(ui->dock_center);
    addDockWidget(Qt::LeftDockWidgetArea, ui->dock_paint);
    addDockWidget(Qt::RightDockWidgetArea, ui->dock_geometry);
    addDockWidget(Qt::RightDockWidgetArea, ui->dock_special);
    addDockWidget(Qt::RightDockWidgetArea, ui->dock_layer);
    splitDockWidget(ui->dock_paint, ui->dock_center, Qt::Horizontal);     // 水平
    splitDockWidget(ui->dock_geometry, ui->dock_layer, Qt::Vertical);      // 垂直

    // 合并窗口
    tabifyDockWidget(ui->dock_geometry, ui->dock_special);

    ui->dock_geometry->raise();             //指定窗口置于最前

    ConnectFile();

    InitImage();        // 初始化图像QLabel

    InitLayerView();
    ConnectAction();    // Initialize the action connection

    //皮肤！
    QFile styleSheet("./qss/main.qss");
    if (!styleSheet.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    ui->dock_geometry->setStyleSheet(styleSheet.readAll());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ConnectFile()
{
    connect(ui->action_new, SIGNAL(triggered()), this, SLOT(NewFile()));
    connect(ui->action_open, SIGNAL(triggered()), this, SLOT(OpenFile()));
    connect(ui->action_save, SIGNAL(triggered()), this, SLOT(SaveFile()));
    connect(ui->action_exit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->action_saveas, SIGNAL(triggered()), this, SLOT(SaveasFile()));
}
void MainWindow::ConnectAction(){
    connect(ui->pushButton_choose,SIGNAL(clicked()),this,SLOT(SetActionDrag()));
    connect(imgLabel,SIGNAL(dragged(QPoint,QPoint)),this,SLOT(DragSlot(QPoint,QPoint)));
//    connect(*current_layer_,SIGNAL(dragged(QPoint,QPoint)),this,SLOT(DragSlot(QPoint,QPoint)));
    connect(ui->pushButton_line,SIGNAL(clicked()),this,SLOT(Lines()));
}
void MainWindow::SetActionDrag(){
    if (action_mode_!=DRAG_PREVIEW) action_mode_ = DRAG_PREVIEW;
    else action_mode_ = NO_ACTION;
}
//初始化
void MainWindow::InitImage()
{
    imgLabel = new ImageQLabel(ui->dock_center);
    imgLabel->setScaledContents(true);  // 设置QLabel自动适应图像大小
    //滚动条
    scroll_area_ = new QScrollArea(this);
    scroll_area_->setBackgroundRole(QPalette::Dark);
    scroll_area_->setAlignment(Qt::AlignCenter);
    scroll_area_->setWidget(imgLabel);
    ui->dock_center->setWidget(scroll_area_);
}

void MainWindow::InitLayerView(){
    layer_group_ = new LayerGroup();
    layer_table_ = new LayerTableView(&layer_group_->get_vec_layer());
    ui->dock_layer->setWidget(layer_table_);
}
//新建
void MainWindow::NewFile()
{
    if (layer_group_!=nullptr) delete layer_group_;
    layer_group_ = new LayerGroup;
    MainWindow::RefreshView();
}
//打开
void MainWindow::OpenFile()
{
    QString path = QFileDialog::getOpenFileName(this, "选择图像", ".", "Images(*.jpg *.png *.bmp)");                            // 文件选择框
    if (!path.isEmpty())
    {
        qDebug()<<path<<endl;
        Layer layer(path.toStdString(),"Untitiled Layer",OPAQUE,true,0,0);
        if (layer_group_ == nullptr) {
            layer_group_ = new LayerGroup(layer.get_height(),layer.get_width());
        }
        layer_group_->insert(layer);
        current_layer_ = layer_group_->get_vec_layer()[1];
        qDebug()<<"Insert layer OK\n";
    }
    MainWindow::RefreshView();
}
//保存
void MainWindow::SaveFile()
{
    //判断新建or打开
    if (current_path_.isEmpty())
    {
        QString path = QFileDialog::getSaveFileName(this, "Save", ".", "Images(*.jpg *.png *.bmp)");
        if (!path.isEmpty())
            current_path_ = path;
    }
    //读取
    QImage img = imgLabel->pixmap()->toImage();
    img.save(current_path_);
}
//另存为
void MainWindow::SaveasFile()
{

    QString path = QFileDialog::getSaveFileName(this,"SaveAs", ".", "Images(*.jpg *.png *.bmp)");
    if (!path.isEmpty())
    {
        QImage img = imgLabel->pixmap()->toImage();
        img.save(path);
        current_path_ = path;
    }
}
void MainWindow::RefreshView()
{
    if (layer_group_==nullptr) imgLabel->clear();
    else {
        QImage preview = layer_group_->get_preview();
        imgLabel->SetPreview(QPixmap::fromImage(preview));
        imgLabel->RefreshView();
    }
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (QApplication::keyboardModifiers()==Qt::ControlModifier){
        qreal delta_level = event->angleDelta().y();
        delta_level/=8*360;
        imgLabel->SetZoomLevel(delta_level);
    }
}
void MainWindow::DragSlot(QPoint startpoint,QPoint endpoint)
{
    QPoint delta = endpoint - startpoint;
    Point s,e;
    s.x=startpoint.x();
    s.y=startpoint.y();
    e.x=endpoint.x();
    e.y=endpoint.y();
    double zoom_level = imgLabel->GetZoomLevel();
    s/=zoom_level;
    e/=zoom_level;
    switch (action_mode_)
    {
    case DRAG_PREVIEW:
        Scroll(delta);
        break;
    case DRAW_LINES:
        DrawType.layerLine(*current_layer_,s,e,Scalar(0,0,0),1,1,8,0);
        RefreshView();
        break;
    default:
        break;
    }
}
void MainWindow::Scroll(QPoint delta)
{
    QScrollBar* h_bar = scroll_area_->horizontalScrollBar();
    QScrollBar* v_bar = scroll_area_->verticalScrollBar();
    qDebug()<<"h_bar: "<<h_bar->value()<<",v_bar: "<<v_bar->value()<<"delta: "<<delta<<endl;
    h_bar->setValue(h_bar->value()-delta.x());
    v_bar->setValue(v_bar->value()-delta.y());
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if (event->key()==Qt::Key_0&&QApplication::keyboardModifiers()==Qt::ControlModifier){
        imgLabel->ResetZoom();
    }
}

void MainWindow::Lines()
{
    if (action_mode_!=DRAW_LINES) action_mode_ = DRAW_LINES;
    else action_mode_ = NO_ACTION;
}
