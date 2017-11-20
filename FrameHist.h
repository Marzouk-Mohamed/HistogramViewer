#ifndef FRAMEHIST_H
#define FRAMEHIST_H
 #include <QWidget>
#include <QGridLayout>
#include "Histogram.h"
#include <opencv2/opencv.hpp>
#include <core/core.hpp>
#include <imgcodecs.hpp>
#include <highgui/highgui.hpp>
#include <imgproc/imgproc.hpp>

using namespace cv;

  class FrameHist :public QWidget{
    private:
        Histogram* ListHistos[3];
        QGridLayout *layout;
        QString path;
    public:
        FrameHist(Histogram*,Histogram*,Histogram*);
        FrameHist(QString,bool);
        double** CalculHistogram(Mat);
        void setPath(QString p);
        ~FrameHist();
  };

#endif // FRAMEHIST_H
