#ifndef PLOTTINGCHART_DIALOG_H
#define PLOTTINGCHART_DIALOG_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class PlottingChart_Dialog : public QWidget
{
    Q_OBJECT
public:
    explicit PlottingChart_Dialog(QWidget *parent = nullptr);
    void plottingChart();
signals:



};

#endif // PLOTTINGCHART_DIALOG_H
