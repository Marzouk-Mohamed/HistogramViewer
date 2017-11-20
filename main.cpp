#include "mainwindow.h"
#include <QApplication>
#include "Histogram.h"
#include "FrameHist.h"
#include "FenetrePrincipale.h"
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     FenetrePrincipale *Z = new FenetrePrincipale();
     Z->show();
    return a.exec();
}
