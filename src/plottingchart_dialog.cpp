#include "plottingchart_dialog.h"
#include "dateandtime_dialog.h"

void someFunction()
{
    qDebug() << "lol";
};

PlottingChart_Dialog::PlottingChart_Dialog(QWidget *parent)
    : QWidget{parent}
{
    QLabel *plottingChartLabel = new QLabel("Plotting a candlestick chart");
    QLabel *datBeginLabel = new QLabel("Time begin");
    QLabel *datEndLabel = new QLabel("Time end");
    DateAndTime_dialog *dat_begin = new DateAndTime_dialog;
    DateAndTime_dialog *dat_end = new DateAndTime_dialog;
    QPushButton *buildChartButton = new QPushButton;

    QSize longSize(325,20);
    plottingChartLabel->setFixedSize(longSize);
    buildChartButton->setFixedSize(longSize);

    QSize midSize(160,20);
    datBeginLabel->setFixedSize(midSize);
    datEndLabel->setFixedSize(midSize);

    buildChartButton->setText("Build a chart");

    plottingChartLabel->setAlignment(Qt::AlignCenter);
    datBeginLabel->setAlignment(Qt::AlignCenter);
    datEndLabel->setAlignment(Qt::AlignCenter);

    plottingChartLabel->setObjectName("plottingChartLabel");

    QGridLayout *plottingChartDialog = new QGridLayout(this);
    plottingChartDialog->addWidget(plottingChartLabel,0,0);
    plottingChartDialog->addWidget(datBeginLabel,1,0);
    plottingChartDialog->addWidget(datEndLabel,1,1);
    plottingChartDialog->addWidget(dat_begin,2,0);
    plottingChartDialog->addWidget(dat_end,2,1);
    plottingChartDialog->addWidget(buildChartButton,3,0);
    plottingChartDialog->setSpacing(5);
    plottingChartDialog->setContentsMargins(0,0,0,0);

    QSize widSize(325, 175);
    this->setFixedSize(widSize);

    QDateTime dateTime_begin = dat_begin->getdateTime();
    QDateTime dateTime_end = dat_end->getdateTime();

    connect(buildChartButton, &QPushButton::clicked, someFunction);

}
