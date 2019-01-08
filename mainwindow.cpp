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

    connect(ui->pushButton_line,SIGNAL(clicked()),this,SLOT(Lines()));
    connect(ui->pushButton_ciecle,SIGNAL(clicked()),this,SLOT(Circles()));
    connect(ui->pushButton_rectangle,SIGNAL(clicked()),this,SLOT(Rect()));
    connect(ui->pushButton_cut,SIGNAL(clicked()),this,SLOT(Tailor()));
    connect(ui->pushButton_mosaic,SIGNAL(clicked()),this,SLOT(Erase()));
    connect(ui->confirm_filter_2,SIGNAL(clicked()),this,SLOT(Blur()));
    connect(ui->pushButton_histogram,SIGNAL(clicked()),this,SLOT(Hist()));
    connect(ui->clockwise_90,SIGNAL(clicked()),this,SLOT(Rotate90()));
    connect(ui->anticlockwise_90,SIGNAL(clicked()),this,SLOT(AntiRotate90()));
    connect(ui->confirm_rotate,SIGNAL(clicked()),this,SLOT(Rotate()));
    connect(ui->confrim_size,SIGNAL(clicked()),this,SLOT(Resize()));
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
    int mid,height,weight;

    s.x=startpoint.x();
    s.y=startpoint.y();
    e.x=endpoint.x();
    e.y=endpoint.y();
    double zoom_level = imgLabel->GetZoomLevel();
    s/=zoom_level;
    e/=zoom_level;
    if(s.x>e.x)
    {
        rect.x=e.x;
    }
    else
    {
        rect.x=s.x;
    }
    if(s.y<e.y)
    {
        rect.y=s.y;
    }
    else
    {
        rect.y=e.y;
    }
    rect.height=abs(s.y-e.y);
    rect.width=abs(e.x-s.x);


    switch (action_mode_)
    {
    case DRAG_PREVIEW:
        Scroll(delta);
        break;
    case DRAW_LINES:
        DrawType.layerLine(*current_layer_,s,e,Scalar(0,0,0));
        RefreshView();
        break;
    case DRAW_CIRCLE:
        DrawType.layerCircle(*current_layer_,s,(int)sqrt((s.x-e.x)*(s.x-e.x)+(s.y-e.y)*(s.y-e.y)), Scalar(0,0,0));
        RefreshView();
        break;
    case DRAW_RECT:
        DrawType.layerRect(*current_layer_, rect, Scalar(0,0,0));
        RefreshView();
        break;
    case TAILOR:
        DrawType.layerTailoring(*current_layer_, rect);
        RefreshView();
        break;
    case ERASE:
        DrawType.layerLine(*current_layer_,s,e,Scalar(255),0,20);
        RefreshView();
        break;
    case ERASE_RECT:
        DrawType.layerRect(*current_layer_,rect,Scalar(255),0);
        RefreshView();
        break;
    case ERASE_CIRCLE:
        DrawType.layerCircle(*current_layer_,s,(int)sqrt((s.x-e.x)*(s.x-e.x)+(s.y-e.y)*(s.y-e.y)), Scalar(255),0);
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

//直线
void MainWindow::Lines()
{
    if (action_mode_!=DRAW_LINES) action_mode_ = DRAW_LINES;
    else action_mode_ = NO_ACTION;
}

//圆
void MainWindow::Circles()
{
    if(action_mode_==ERASE)
    {
        action_mode_ = ERASE_CIRCLE;
        cout<<"erase_circle"<<endl;
    }
    else if (action_mode_!=DRAW_CIRCLE) action_mode_ = DRAW_CIRCLE;
    else action_mode_ = NO_ACTION;
}

//方形
void MainWindow::Rect()
{   if(action_mode_==ERASE)
    {
        action_mode_ = ERASE_RECT;
        cout<<"erase_rect"<<endl;
    }
    else if (action_mode_!=DRAW_RECT) action_mode_ = DRAW_RECT;
    else action_mode_ = NO_ACTION;
}

//裁剪
void MainWindow::Tailor()
{
    if (action_mode_!=TAILOR) action_mode_ = TAILOR;
    else action_mode_ = NO_ACTION;
}

//橡皮
void MainWindow::Erase()
{
    if (action_mode_!=ERASE) action_mode_ = ERASE;
    else action_mode_ = NO_ACTION;
}

//滤波
void MainWindow::Blur()
{   if(ui->comboBox__filter_2->currentIndex()==-1)
    {
        DrawType.layerBlur(*current_layer_);
    }
    else if(ui->comboBox__filter_2->currentIndex()==0)
    {
        DrawType.layerGaussBlur(*current_layer_);
    }
    else if(ui->comboBox__filter_2->currentIndex()==1)
    {
        DrawType.layerMedianBlur(*current_layer_);
    }
    else if(ui->comboBox__filter_2->currentIndex()==2)
    {
        DrawType.layerMedianBlur(*current_layer_);
    }
    RefreshView();
}

//直方图
void MainWindow::Hist()
{
    DrawType.layerShowHist(*current_layer_);
    RefreshView();
}

//旋转
void MainWindow::Rotate90()
{
    DrawType.layerRotate(*current_layer_,-90);
    RefreshView();
}

void MainWindow::AntiRotate90()
{
    DrawType.layerRotate(*current_layer_,90);
    RefreshView();
}

void MainWindow::Rotate()
{
    QString str = ui->lineEdit_degree->text();
    double num = str.toDouble();
    if(ui->comboBox_direction->currentIndex()==-1)
    {
        DrawType.layerRotate(*current_layer_,num);
    }
    else if(ui->comboBox_direction->currentIndex()==0)
    {
        DrawType.layerRotate(*current_layer_,-num);
    }
    RefreshView();
}

//缩放
void MainWindow::Resize()
{
    QString str = ui->lineEdit_length->text();
    double fx = str.toDouble();
    str = ui->lineEdit_width->text();
    double fy = str.toDouble();
    DrawType.layerResize(*current_layer_,fx/100,fy/100);
    RefreshView();
}
