#include "Histogram.h"
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
#include <QToolTip>

Histogram::Histogram(double* d,QString s,QWidget* parent):QWidget(parent){
  for(int i=0;i<256;i++){
     Values[i] = d[i];
  }
  this->type = s;
  this->setMouseTracking(true);
}

void Histogram::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);

      QPainter qp(this);
      drawLines(&qp);
}

void Histogram::drawLines(QPainter *qp){
      qp ->fillRect(15,0,300,300,Qt::white);
      //X-Axis
      QPen pen(Qt::black, 2, Qt::SolidLine);
      this->setPenColor(&pen);
      qp->setPen(pen);
      QFont f; f.setPixelSize(18);
      qp->setFont(f);
      qp->drawText(295,20,type);
      pen.setColor(Qt::black);
      qp->setPen(pen);
      qp->drawLine(30, 270, 310, 270);
      qp->drawLine(307,267,310,270);
      qp->drawLine(307,273,310,270);
      // Y-Axis
      qp->setPen(pen);
      qp->drawLine(30, 270, 30, 10);
      qp->drawLine(27,13,30,10);
      qp->drawLine(33,13,30,10);

      //qp->fillRect(20,200,20,40,Qt::SolidPattern);
      //qp->fillRect(30,200,20,80,Qt::SolidPattern);
      //Draw Histogram
      this->setPenColor(&pen);
      qp->setPen(pen);
      for(int i=0;i<256;i++){
          if(Values[i]!= 0)
          qp->drawLine(35+i,(int) (270-250*Values[i]/maxi()),35+i,268);

      }
       // Draw legends
        pen.setColor(Qt::black);
        qp->setPen(pen);
        f.setPixelSize(11);
        qp->setFont(f);
        qp->drawText(130,290,"Pixel values");
        qp->drawText(34,12,"Frequency");
        //qp->rotate(-45);
}

void Histogram::setPenColor(QPen* pen){
    if(QString::compare(type,"B")==0){
            pen->setColor(Qt::blue);}
    else{
        if(QString::compare(type,"G")==0){
                pen->setColor(Qt::green);}
        else{
           pen->setColor(Qt::red);
        }
    }
}

void Histogram::mouseMoveEvent(QMouseEvent *event){
  QToolTip::showText(event->globalPos(),
                     QString::number( event->pos().x()>35&event->pos().x()<=290? event->pos().x()-35:0  ) + ", " +
                     QString::number( event->pos().x()>35&event->pos().x()<=290? Values[event->pos().x()-35]:0 ),
                     this, rect()
                     );
}



double Histogram::maxi(){
    double m=0;
   for(int i=0;i<256;i++)
       if(Values[i]>m) m = Values[i];
   return m;
}


