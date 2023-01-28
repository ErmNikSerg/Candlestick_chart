#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QColor appColor(64,64,64);
    QPalette appPalette(appColor);

    a.setPalette(appPalette);
    return a.exec();
}
