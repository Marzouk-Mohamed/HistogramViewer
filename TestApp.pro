#-------------------------------------------------
#
# Project created by QtCreator 2017-11-14T11:27:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestApp
TEMPLATE = app

CONFIG += qtcommercialchart

SOURCES += main.cpp\
        mainwindow.cpp \
    Histogram.cpp \
    FrameHist.cpp \
    FenetrePrincipale.cpp

INCLUDEPATH += /usr/local/include/opencv\
               /usr/local/include/opencv2

LIBS += -L/home/reda/Bureau/ImageProcessing/opencv/build/lib -lopencv_highgui -lopencv_imgcodecs -lopencv_core -lopencv_imgproc
HEADERS  += mainwindow.h \
    Histogram.h \
    FrameHist.h \
    FenetrePrincipale.h

FORMS    += mainwindow.ui

OTHER_FILES +=
