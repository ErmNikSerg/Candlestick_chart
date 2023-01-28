#include "main_dialog.h"

#include "fileverification.h"
#include "analisys_dialog.h"
#include "plottingchart_dialog.h"

Main_dialog::Main_dialog(QWidget *parent)
    : QWidget(parent)
{ 
    FileVerification *fileverification = new FileVerification;
    PlottingChart_Dialog *plottingChart = new PlottingChart_Dialog;
    Analisys_dialog *analisys_dialog = new Analisys_dialog;

    QGridLayout *mainDialog = new QGridLayout(this);
    mainDialog->addWidget(fileverification,0,0);
    mainDialog->addWidget(plottingChart,1,0);
    mainDialog->addWidget(analisys_dialog,2,0);
    mainDialog->setSpacing(5);
    mainDialog->setContentsMargins(0,0,0,0);

    QSize widSize(325, 515);
    this->setFixedSize(widSize);

    QString mainDialogStyle(
                            "QLineEdit {"
                            "background-color: white;"
                            "font: bold 14px;"
                            "border-style: outset;"
                            "border-radius: 10px;"
                            "padding: 1px;"
                            "}"

                            "QPushButton {"
                            "background-color: white;"
                            "font: bold 14px;"
                            "border-style: outset;"
                            "border-radius: 10px;"
                            "padding: 1px;"
                            "}"

                            "QLabel#pathToFileLabel {"
                            "border-style: outset;""border-width: 2px;""border-color: beige;"
                            "}"

                            "QLabel#plottingChartLabel {"
                            "border-style: outset;""border-width: 2px;""border-color: beige;"
                            "}"

                            "QLabel#analisysLabel {"
                            "border-style: outset;""border-width: 2px;""border-color: beige;"
                            "}"

                            "QLabel {"
                            "color: white;"
                            "font: bold 14px;"
                            "}"
                            );

    this->setStyleSheet(mainDialogStyle);
}
