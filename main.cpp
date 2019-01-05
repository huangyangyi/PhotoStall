#include "mainwindow.h"
#include <QApplication>
#include "layergroup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //皮肤！
    QFile qss(":/main.qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());

    MainWindow w;
    w.show();

    return a.exec();
}
