#-------------------------------------------------
#
# Project created by QtCreator 2018-12-12T19:59:07
#
#-------------------------------------------------
RC_ICONS = PhotoStall.ico
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhotoStall
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    layer.cpp \
    layergroup.cpp \
    layerbasic.cpp \
    imageqlabel.cpp \
    layertablemodel.cpp \
    layerdelegate.cpp \
    layertableview.cpp

HEADERS += \
        mainwindow.h \
    layer.h \
    layergroup.h \
    layerbasic.h \
    imageqlabel.h \
    layertablemodel.h \
    layerdelegate.h \
    layertableview.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon/icon.qrc \
    qss/qss.qrc \
    resources.qrc
win32 {
    INCLUDEPATH += D:\opencv\opencv\build\include
    INCLUDEPATH += D:\opencv\opcnv\build\include\opencv
    INCLUDEPATH += D:\opencv\opcnv\build\include\opencv2
    CONFIG(debug,debug|release){
        LIBS+= -LD:\opencv\opencv\build\x64\vc15\lib \
        -lopencv_world342d
    }
    else {
        LIBS+= -LD:\opencv\opencv\build\x64\vc15\lib \
        -lopencv_world342
    }
}
unix {
    INCLUDEPATH += /usr/local/include
    INCLUDEPATH += /usr/local/include/opencv
    INCLUDEPATH += /usr/local/include/opencv2
    LIBS += -L/usr/local/lib \
     -lopencv_core \
     -lopencv_highgui \
     -lopencv_imgproc \

    QT_CONFIG -= no-pkg-config
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}
TRANSLATIONS += PhotoStall_zh_CN.ts

DISTFILES +=
