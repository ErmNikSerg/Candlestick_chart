#include "stock_quotes_chart.h"
#include "datareader.h"

Stock_quotes_chart::Stock_quotes_chart(QWidget *parent)
    : QWidget(parent)
{
    QString ticketDataFile = "C:/Qt_Projects/St_ex/Initial_Data/GAZPROM_2022.txt";

    DataReader dataReader;
    dataReader.readFile(ticketDataFile);  

    auto year_begin = 2022;
    auto month_begin = 1;
    auto day_begin = 3;
    auto hour_begin = 7;
    auto minute_begin = 0;
    auto second_begin = 0;

    auto year_end = 2022;
    auto month_end = 1;
    auto day_end = 3;
    auto hour_end = 7;
    auto minute_end = 55;
    auto second_end = 0;

    DataReader::Scale scale = DataReader::Scale_Hour;

    QDate date_begin(year_begin,month_begin,day_begin);
    QTime time_begin(hour_begin,minute_begin,second_begin);
    QDateTime dateTime_begin(date_begin, time_begin);

    QDate date_end(year_end,month_end,day_end);
    QTime time_end(hour_end,minute_end,second_end);
    QDateTime dateTime_end(date_end, time_end);

    auto *timestampList = dataReader.timestempList(dateTime_begin, dateTime_end, scale);

    QStringList categories;

    QCandlestickSeries *gazprom = new QCandlestickSeries();
    gazprom->setName("Gazprom");
    gazprom->setIncreasingColor(QColor(Qt::green));
    gazprom->setDecreasingColor(QColor(Qt::red));

    for (auto timestamp : *timestampList) {
        QCandlestickSet *set = dataReader.getSet(timestamp,scale);
        if (set)
        {
             gazprom->append(set);
             categories << QDateTime::fromMSecsSinceEpoch(set->timestamp()).toString("mm");
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(gazprom);
    chart->setTitle("Gazprom candlesticks chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    chart->createDefaultAxes();

    QBarCategoryAxis *axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);

    QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
    axisY->setMax(axisY->max());
    axisY->setMin(axisY->min());

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeDark);

    QChartView *chartView = new QChartView(chart); //  QSize chartSize_min(640,480);
    chartView->setRenderHint(QPainter::Antialiasing);   
    chartView->setViewport(this);

    chartSize = chartView->size();
}

Stock_quotes_chart::~Stock_quotes_chart()
{
}

 QSize Stock_quotes_chart::get_chartSize()
{
    return chartSize;
}
