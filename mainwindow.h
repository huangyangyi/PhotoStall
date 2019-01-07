#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <QScrollArea>
#include <QTextStream>
#include <QKeyEvent>
#include <QWheelEvent>
#include<qscrollbar.h>
#include<QPoint>
#include "layergroup.h"
#include "imageqlabel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    enum ACTION_TYPE {//different action modes
        NO_ACTION,//doing nothing
        DRAG_PREVIEW//drag preview image
    };
    QScrollArea *scroll_area_;
    ACTION_TYPE action_mode_;
    Ui::MainWindow *ui;
    LayerGroup *layer_group_=nullptr;//当前处理的图层组
    Layer *current_layer_=nullptr;//当前处理的图层
    //打开文件
    QDockWidget *dock_center;
    QString current_path_;
    ImageQLabel *imgLabel;
    qreal zoom_level_=1.0;
    void InitImage();
    void ConnectFile();
    void ConnectAction();
    virtual void wheelEvent(QWheelEvent * event);
    virtual void keyPressEvent(QKeyEvent * event);
private slots:
    void NewFile();
    void OpenFile();
    void SaveFile();
    void SaveasFile();
    void RefreshView();
    void Scroll(QPoint delta);
    void SetActionDrag();
    void DragSlot(QPoint startpoint,QPoint endpoint);
};

#endif // MAINWINDOW_H
