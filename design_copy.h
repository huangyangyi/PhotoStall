#ifndef DESIGN_H
#define DESIGN_H
/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_4;
    QAction *action_5;
    QAction *action_7;
    QAction *action_8;
    QAction *action_9;
    QAction *actionj;
    QAction *actiont;
    QAction *actionhui;
    QAction *action_3;
    QAction *action_6;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu21;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dock_layer;
    QWidget *dockWidgetContents_9;
    QLabel *label_9;
    QLabel *label_10;
    QDockWidget *dock_paint;
    QWidget *dockWidgetContents_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QDockWidget *dock_geometry;
    QWidget *dockWidgetContents_8;
    QLabel *label_25;
    QLabel *label_26;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QComboBox *comboBox_7;
    QSpinBox *spinBox_4;
    QLabel *label_30;
    QComboBox *comboBox_8;
    QLabel *label_31;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QLabel *label_32;
    QDockWidget *dock_center;
    QWidget *dockWidgetContents;
    QDockWidget *dock_special;
    QWidget *dockWidgetContents_3;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton;
    QLabel *label_13;
    QLabel *label_14;
    QSlider *horizontalSlider;
    QComboBox *comboBox_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 900);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\346\226\207\344\273\266\345\244\271-\345\261\225\345\274\200.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\346\267\273\345\212\240.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon1);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/\344\277\235\345\255\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_4->setIcon(icon2);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/\345\217\246\345\255\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_5->setIcon(icon3);
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QStringLiteral("action_7"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/\345\205\263\351\227\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_7->setIcon(icon4);
        action_8 = new QAction(MainWindow);
        action_8->setObjectName(QStringLiteral("action_8"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/\346\222\244\351\224\200.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_8->setIcon(icon5);
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QStringLiteral("action_9"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/\350\277\224\345\233\236.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_9->setIcon(icon6);
        actionj = new QAction(MainWindow);
        actionj->setObjectName(QStringLiteral("actionj"));
        actiont = new QAction(MainWindow);
        actiont->setObjectName(QStringLiteral("actiont"));
        actionhui = new QAction(MainWindow);
        actionhui->setObjectName(QStringLiteral("actionhui"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 17));
        menu21 = new QMenu(menuBar);
        menu21->setObjectName(QStringLiteral("menu21"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dock_layer = new QDockWidget(MainWindow);
        dock_layer->setObjectName(QStringLiteral("dock_layer"));
        dock_layer->setMaximumSize(QSize(900, 600));
        dock_layer->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        dockWidgetContents_9 = new QWidget();
        dockWidgetContents_9->setObjectName(QStringLiteral("dockWidgetContents_9"));
        label_9 = new QLabel(dockWidgetContents_9);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 10, 51, 21));
        label_10 = new QLabel(dockWidgetContents_9);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 10, 91, 21));
        dock_layer->setWidget(dockWidgetContents_9);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dock_layer);
        dock_paint = new QDockWidget(MainWindow);
        dock_paint->setObjectName(QStringLiteral("dock_paint"));
        dock_paint->setAutoFillBackground(false);
        dock_paint->setStyleSheet(QStringLiteral("background-color:rgb(244, 244, 244)"));
        dock_paint->setFloating(false);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        pushButton_4 = new QPushButton(dockWidgetContents_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 10, 51, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("image: url(:/\347\247\273\345\212\250.png);"));
        pushButton_5 = new QPushButton(dockWidgetContents_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 70, 51, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("image: url(:/\347\233\264\347\272\277.png);"));
        pushButton_6 = new QPushButton(dockWidgetContents_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 130, 51, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("image: url(:/\345\275\242\347\212\266-\346\244\255\345\234\206\345\275\242.png);"));
        pushButton_7 = new QPushButton(dockWidgetContents_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 190, 51, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("image: url(:/\346\216\247\344\273\266\346\234\252\351\200\211.png);"));
        pushButton_8 = new QPushButton(dockWidgetContents_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(10, 250, 51, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("image: url(:/\347\233\264\347\272\277.png);"));
        dock_paint->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_paint);
        dock_geometry = new QDockWidget(MainWindow);
        dock_geometry->setObjectName(QStringLiteral("dock_geometry"));
        dock_geometry->setStyleSheet(QStringLiteral("background-color:rgb(243, 243, 243)"));
        dock_geometry->setFloating(true);
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QStringLiteral("dockWidgetContents_8"));
        label_25 = new QLabel(dockWidgetContents_8);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(20, 40, 81, 21));
        label_26 = new QLabel(dockWidgetContents_8);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(120, 70, 81, 21));
        lineEdit_7 = new QLineEdit(dockWidgetContents_8);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(210, 40, 111, 21));
        lineEdit_8 = new QLineEdit(dockWidgetContents_8);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(210, 70, 111, 22));
        label_27 = new QLabel(dockWidgetContents_8);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(330, 40, 16, 16));
        label_28 = new QLabel(dockWidgetContents_8);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(330, 70, 16, 16));
        label_29 = new QLabel(dockWidgetContents_8);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(20, 120, 71, 21));
        comboBox_7 = new QComboBox(dockWidgetContents_8);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));
        comboBox_7->setGeometry(QRect(131, 121, 91, 22));
        spinBox_4 = new QSpinBox(dockWidgetContents_8);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(240, 120, 71, 20));
        label_30 = new QLabel(dockWidgetContents_8);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(140, 160, 81, 16));
        comboBox_8 = new QComboBox(dockWidgetContents_8);
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));
        comboBox_8->setGeometry(QRect(240, 160, 121, 22));
        label_31 = new QLabel(dockWidgetContents_8);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(20, 200, 71, 20));
        pushButton_15 = new QPushButton(dockWidgetContents_8);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(130, 200, 91, 31));
        pushButton_16 = new QPushButton(dockWidgetContents_8);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(240, 200, 101, 31));
        label_32 = new QLabel(dockWidgetContents_8);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(121, 40, 81, 21));
        dock_geometry->setWidget(dockWidgetContents_8);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_geometry);
        dock_center = new QDockWidget(MainWindow);
        dock_center->setObjectName(QStringLiteral("dock_center"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dock_center->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_center);
        dock_special = new QDockWidget(MainWindow);
        dock_special->setObjectName(QStringLiteral("dock_special"));
        dock_special->setLayoutDirection(Qt::LeftToRight);
        dock_special->setStyleSheet(QStringLiteral("background-color:rgb(255,255,255)"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        label_11 = new QLabel(dockWidgetContents_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 30, 61, 31));
        label_12 = new QLabel(dockWidgetContents_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 100, 61, 31));
        pushButton = new QPushButton(dockWidgetContents_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 40, 101, 31));
        label_13 = new QLabel(dockWidgetContents_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(110, 100, 71, 31));
        label_14 = new QLabel(dockWidgetContents_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(110, 150, 81, 31));
        horizontalSlider = new QSlider(dockWidgetContents_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(200, 160, 91, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        comboBox_3 = new QComboBox(dockWidgetContents_3);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(200, 110, 91, 31));
        dock_special->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dock_special);

        menuBar->addAction(menu21->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu21->addAction(action_2);
        menu21->addAction(action);
        menu21->addSeparator();
        menu21->addAction(action_4);
        menu21->addAction(action_5);
        menu21->addSeparator();
        menu21->addAction(action_7);
        menu21->addAction(action_3);
        menu->addAction(action_8);
        menu->addAction(action_9);
        menu_2->addAction(actionj);
        menu_2->addAction(actiont);
        menu_2->addAction(actionhui);
        menu_2->addAction(action_6);
        mainToolBar->addAction(action_2);
        mainToolBar->addAction(action);
        mainToolBar->addAction(action_4);
        mainToolBar->addAction(action_5);
        mainToolBar->addAction(action_8);
        mainToolBar->addAction(action_9);
        designUI(MainWindow);
        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "hyynb", nullptr));
        action->setText(QApplication::translate("MainWindow", "&\346\211\223\345\274\200", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "&\346\226\260\345\273\272", nullptr));
        action_4->setText(QApplication::translate("MainWindow", "&\344\277\235\345\255\230", nullptr));
        action_5->setText(QApplication::translate("MainWindow", "&\345\217\246\345\255\230\344\270\272", nullptr));
        action_7->setText(QApplication::translate("MainWindow", "&\345\205\263\351\227\255", nullptr));
        action_8->setText(QApplication::translate("MainWindow", "&\346\222\244\351\224\200", nullptr));
        action_9->setText(QApplication::translate("MainWindow", "&\351\207\215\345\201\232", nullptr));
        actionj->setText(QApplication::translate("MainWindow", "&\345\207\240\344\275\225\345\217\230\346\215\242", nullptr));
        actiont->setText(QApplication::translate("MainWindow", "&\347\211\271\346\256\212\346\225\210\346\236\234", nullptr));
        actionhui->setText(QApplication::translate("MainWindow", "&\347\273\230\345\233\276\345\267\245\345\205\267", nullptr));
        action_3->setText(QApplication::translate("MainWindow", "\346\240\274\345\274\217\350\275\254\346\215\242", nullptr));
        action_6->setText(QApplication::translate("MainWindow", "\345\233\276\345\261\202", nullptr));
        menu21->setTitle(QApplication::translate("MainWindow", "&\346\226\207\344\273\266", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "&\347\274\226\350\276\221", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "&\350\247\206\345\233\276", nullptr));
        dock_layer->setWindowTitle(QApplication::translate("MainWindow", "\345\233\276\345\261\202", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\345\217\257\350\247\206", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\345\233\276\345\261\202", nullptr));
#ifndef QT_NO_TOOLTIP
        dock_paint->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        dock_paint->setWindowTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267\347\256\261", nullptr));
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QString());
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QString());
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QString());
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QString());
#ifndef QT_NO_WHATSTHIS
        pushButton_8->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_8->setText(QString());
        dock_geometry->setWindowTitle(QApplication::translate("MainWindow", "\345\207\240\344\275\225\345\217\230\346\215\242", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\247\345\260\217", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\256\275\345\272\246\357\274\232", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "px", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "px", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\346\227\213\350\275\254", nullptr));
        comboBox_7->setItemText(0, QApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\210", nullptr));
        comboBox_7->setItemText(1, QApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\210", nullptr));

        label_30->setText(QApplication::translate("MainWindow", "\345\270\270\347\224\250\346\223\215\344\275\234", nullptr));
        comboBox_8->setItemText(0, QApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\210\346\227\213\350\275\25490\302\260", nullptr));
        comboBox_8->setItemText(1, QApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\210\346\227\213\350\275\254180\302\260", nullptr));
        comboBox_8->setItemText(2, QApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\210\346\227\213\350\275\254270\302\260", nullptr));

        label_31->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\347\277\273\350\275\254", nullptr));
        pushButton_15->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\347\277\273\350\275\254", nullptr));
        pushButton_16->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\347\277\273\350\275\254", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\351\225\277\345\272\246\357\274\232", nullptr));
        dock_center->setWindowTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\204\347\220\206", nullptr));
        dock_special->setWindowTitle(QApplication::translate("MainWindow", "\347\211\271\346\256\212\346\225\210\346\236\234", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\346\273\244\351\225\234", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276\346\230\276\347\244\272", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\346\273\244\351\225\234\346\225\210\346\236\234", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\346\273\244\351\225\234\347\250\213\345\272\246", nullptr));
        comboBox_3->setItemText(0, QApplication::translate("MainWindow", "\346\227\240", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("MainWindow", "\346\200\200\346\227\247", nullptr));
        comboBox_3->setItemText(2, QApplication::translate("MainWindow", "\351\273\221\347\231\275", nullptr));

    } // retranslateUi
    void designUI(QMainWindow *MainWindow)
    {
        dock_center->setMinimumSize(600, 600);
        setCentralWidget(dock_center);
    }
};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_H

#endif // DESIGN_H
