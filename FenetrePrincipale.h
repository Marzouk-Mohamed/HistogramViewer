#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H
#include "FrameHist.h"
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QFileDialog>
#include <QCheckBox>

class FenetrePrincipale :public QWidget{

     Q_OBJECT

     public:
       FenetrePrincipale(QWidget *parent=0);

     public slots:
       void loadFile();
       void showHistograms();


     private:
        QLineEdit *L;
        QPushButton *Browse;
        QPushButton *ShowHist;
        QPushButton *Quit;
        QLabel *ChooseFile;
        QGridLayout *g;
        QFileDialog *dialog;
        QCheckBox* CvtGray;
        FrameHist* h;

};


#endif // FENETREPRINCIPALE_H
