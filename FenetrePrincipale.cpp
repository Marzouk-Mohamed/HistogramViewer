#include "FenetrePrincipale.h"
#include "FrameHist.h"
#include <QSize>
#include <iostream>

  FenetrePrincipale::FenetrePrincipale(QWidget *parent):QWidget(parent){
       L = new QLineEdit();
       Browse = new QPushButton("Browse..");
       ShowHist = new QPushButton("Show Histogram");
       Quit = new QPushButton("Exit");
       ChooseFile = new QLabel("Choose File :");
       dialog = new QFileDialog();
       CvtGray = new QCheckBox("Convert to Gray");
       g = new QGridLayout;

       g->addWidget(ChooseFile,0,0,1,1);
       g->addWidget(L,0,1,1,6);
       g->addWidget(Browse,0,7,1,1);
       g->addWidget(CvtGray,1,3,1,2);
       g->addWidget(ShowHist,1,5,1,2);
       g->addWidget(Quit,1,7,1,1);
       this->setFixedSize(QSize(500,100));
       this->setLayout(g);

       QObject::connect(Browse,SIGNAL(clicked()),this,SLOT(loadFile()));
       QObject::connect(Quit,SIGNAL(clicked()),qApp,SLOT(quit()));
       QObject::connect(ShowHist,SIGNAL(clicked()),this,SLOT(showHistograms()));
  }



  void FenetrePrincipale::loadFile(){
      QString fileName = QFileDialog::getOpenFileName(this,
             tr("Load Image"), "",
             tr("JPEG Image (*.jpg);;All Files (*)"));
      if (fileName.isEmpty())
              return;
          else {
              // Insert the path file to the line edit
              L->clear();
              L->insert(fileName);

           }
  }

  void FenetrePrincipale::showHistograms(){
       QString path = L->text();
       if(!path.isEmpty()){
          // Opencv code
             h = new FrameHist(path,CvtGray->isChecked());
             h->show();
       }

  }
