#include "FrameHist.h"
#include "Histogram.h"
#include <QGridLayout>
#include <opencv2/opencv.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <core/core.hpp>
#include <imgcodecs.hpp>
#include <highgui/highgui.hpp>
#include <imgproc/imgproc.hpp>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <iostream>

using namespace cv;

  FrameHist::FrameHist(Histogram* R,Histogram* G, Histogram* B){
        this->ListHistos[0] = R; this->ListHistos[1] = G; this->ListHistos[2] = B;
        this->layout = new QGridLayout;
        layout->addWidget(ListHistos[0],0,0); layout->addWidget(ListHistos[1],0,1); layout->addWidget(ListHistos[2],1,0);
        this->setLayout(layout);
        this->setFixedSize(700,700);
  }

  FrameHist::FrameHist(QString path,bool togray){
      std::string imageName(path.toStdString());
      Mat inputImage = imread(imageName.c_str(),IMREAD_COLOR);

      // Calcul Histogram
        double** hists = this->CalculHistogram(inputImage);
        this->ListHistos[0] = new Histogram(hists[0],"B"); this->ListHistos[1] = new Histogram(hists[1],"G");
        this->ListHistos[2] = new Histogram(hists[2],"R");
        this->layout = new QGridLayout;
        layout->addWidget(ListHistos[0],0,1);
        layout->addWidget(ListHistos[1],1,0); layout->addWidget(ListHistos[2],1,1);
        QImage myImage;
        myImage.load(path);

        QLabel* myLabel = new QLabel("");
        myLabel->setPixmap(QPixmap::fromImage(myImage.scaled(300,300, Qt::KeepAspectRatio)));
        //myLabel->setFixedSize(300,300);
        layout->addWidget(myLabel,0,0);
        this->setLayout(layout);
        this->setFixedSize(700,700);

        // Display Image
        if(togray){
            Mat grayImage;
            cv::cvtColor(inputImage, grayImage, CV_RGB2GRAY);
            namedWindow( "Image", WINDOW_AUTOSIZE );
            if(!grayImage.empty()) imshow("Image", grayImage);
        }

  }

  double** FrameHist::CalculHistogram(Mat source){
     double **hist;
     hist = new double*[3];
     for(int i=0;i<3;i++)
           hist[i] = new double[256];

     for (int i = 0;i<3;i++)
             for (int j = 0;j<256;j++) {
                 hist[i][j] = 0;
             }
     std::cout<<"ROws "<<source.rows*source.cols<<std::endl;
     for (int i = 0;i<source.rows;i++)
             for (int j = 0;j<source.cols;j++) {
                 Vec3b pixel = source.at<Vec3b>(i, j);
                 hist[0][int(pixel.val[0])]++;
                 hist[1][int(pixel.val[1])]++;
                 hist[2][int(pixel.val[2])]++;

             }

     for(int i=0;i<3;i++){
           for(int j=0;j<256;j++){
               hist[i][j] = hist[i][j]/(source.rows*source.cols);
           }

       }
     return hist;
  }


  FrameHist::~FrameHist(){
      for(int i=0;i<3;i++)
           delete ListHistos[i];

  }

