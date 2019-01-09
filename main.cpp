#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QElapsedTimer>
#include "layergroup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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
    w.show();
    screen.finish(&w);

    return a.exec();
}
