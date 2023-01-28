#ifndef DATAREADER_H
#define DATAREADER_H

#include <QtCore/QTextStream>
#include <QtCore/QHash>
#include <QtCore/QFile>
#include <QtCharts/QCandlestickSet>
#include <QtDebug>
#include <QDateTime>

class DataReader : public QTextStream
{
public:
    enum Scale
    {
        Scale_Hour = 0,
        Scale_Day = 1,
        Scale_Month = 2,
        Scale_Year = 3
    };

public:
    void readFile(QString ticketDataFile); //Read data from file to ticker_qhash
    QList<std::int64_t> *timestempList(QDateTime dt_begin, QDateTime dt_end, Scale scale);//Calculate List of timestemp
    QCandlestickSet *getSet(std::int64_t timestemp, Scale scale); //Data for chart

protected:
    struct Ticket_data
    {
        qreal price_open;
        qreal price_high;
        qreal price_low;
        qreal price_close;
    };

protected:
    QHash<std::int64_t,Ticket_data> ticker_qhash;//Timestemp - Ticker_data
};

#endif // DATAREADER_H
