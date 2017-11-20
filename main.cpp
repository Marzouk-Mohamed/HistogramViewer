#include "mainwindow.h"
#include <QApplication>
#include "FenetrePrincipale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     FenetrePrincipale *Z = new FenetrePrincipale();
     Z->show();
    return a.exec();
}
