#ifndef STOCK_QUOTES_CHART_H
#define STOCK_QUOTES_CHART_H

#include <QWidget>
#include <QtCharts>

class Stock_quotes_chart: public QWidget
{
     Q_OBJECT

     public:
        explicit Stock_quotes_chart(QWidget *parent = nullptr);

        QSize get_chartSize();

     protected:
        QSize chartSize;
};

#endif // STOCK_QUOTES_CHART_H
