#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <core/core.hpp>
#include <imgcodecs.hpp>
#include <highgui/highgui.hpp>
#include <imgproc/imgproc.hpp>

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "Histogram.h"
#include "FrameHist.h"
#include "FenetrePrincipale.h"
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /* MainWindow w;

    double V[256];
    for(int i=0;i<256;i++) V[i] = i;
    //Histogram H(V);
    FrameHist *F = new FrameHist(new Histogram(V),new Histogram(V),new Histogram(V));
    F->show();
    //w.show();
    */

    /*
    string imageName("/home/reda/Bureau/ImageProcessing/ExamplesOpenCV/len_top.jpg");
    Mat inputImage = imread(imageName.c_str(),IMREAD_COLOR);
    namedWindow( "Image test", WINDOW_AUTOSIZE );
    if(!inputImage.empty()) imshow("Image test", inputImage);
    waitKey(0);

      return 0;
     */

     FenetrePrincipale *Z = new FenetrePrincipale();
     Z->show();

    return a.exec();
}
