#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>


class Histogram :public QWidget{

 public:
    Histogram(double*,QString,QWidget* parent=0);
    void paintEvent(QPaintEvent *event);
    void drawLines(QPainter *qp);
    void mouseMoveEvent(QMouseEvent*);
    double maxi();
    void setPenColor(QPen*);

 private:
    double Values[256];
    QString type;
};

#endif // HISTOGRAM_H
