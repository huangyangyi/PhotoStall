#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QElapsedTimer>
#include <QTranslator>
#include "layergroup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator; //新建翻译类
    translator.load("PhotoStall_zh_CN"); //导入生成的文件
    a.installTranslator(&translator); //装入
    //皮肤！
    QFile qss(":/main.qss");
    //加载动画hhh
    QPixmap pixmap("loading.png");
        QSplashScreen screen(pixmap);
        screen.show();
        int delayTime = 5;
        QElapsedTimer timer;
        timer.start();
        while(timer.elapsed() < (delayTime * 1000))
        {
             a.processEvents();
        }

    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());

    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    screen.finish(&w);

    return a.exec();
}
