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
//初始化
void MainWindow::InitImage()
{
    imgLabel = new QLabel(ui->dock_center);
    imgLabel->setScaledContents(true);  // 设置QLabel自动适应图像大小
    //滚动条
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(imgLabel);
    ui->dock_center->setWidget(scrollArea);
}
//新建
void MainWindow::NewFile()
{
    if (layergroup!=nullptr) delete layergroup;
    layergroup = new LayerGroup;
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
        if (layergroup == nullptr) {
            layergroup = new LayerGroup(layer.get_height(),layer.get_width());
        }
        layergroup->insert(layer);
        qDebug()<<"Insert layer OK\n";
    }
    MainWindow::RefreshView();
}
//保存
void MainWindow::SaveFile()
{
    //判断新建or打开
    if (currentPath.isEmpty())
    {
        QString path = QFileDialog::getSaveFileName(this, "Save", ".", "Images(*.jpg *.png *.bmp)");
        if (!path.isEmpty())
        currentPath = path;
    }
    //读取
    QImage img = imgLabel->pixmap()->toImage();
    img.save(currentPath);
}
//另存为
void MainWindow::SaveasFile()
{

    QString path = QFileDialog::getSaveFileName(this,"SaveAs", ".", "Images(*.jpg *.png *.bmp)");
    if (!path.isEmpty())
    {
        QImage img = imgLabel->pixmap()->toImage();
        img.save(path);
        currentPath = path;
    }
}
void MainWindow::RefreshView()
{
    if (layergroup==nullptr) imgLabel->clear();
    else {
        QImage preview = layergroup->get_preview();
        imgLabel->setPixmap(QPixmap::fromImage(preview));
        imgLabel->resize(preview.width(),preview.height());
    }
}
