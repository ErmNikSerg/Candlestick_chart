#include "datareader.h"

void DataReader::readFile(QString ticketDataFile)
{ 
    QFile gaspromData(ticketDataFile);

    if (gaspromData.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream qtstream(&gaspromData);
        Qt::dec(qtstream);

        QString ticker_temp;
        qreal per_temp;
        QString date_temp;
        QString time_temp;
        qreal price_open_temp;
        qreal price_high_temp;
        qreal price_low_temp;
        qreal price_close_temp;
        qreal vol_temp;

        Ticket_data ticker_data_temp;

        QDate date;
        QTime time;
        QDateTime dateTime;

        while(!qtstream.atEnd())
        {
            qtstream >> ticker_temp >> per_temp >> date_temp >> time_temp
                     >> price_open_temp >> price_high_temp >> price_low_temp >> price_close_temp >> vol_temp;

            ticker_data_temp.price_open = price_open_temp;
            ticker_data_temp.price_high = price_high_temp;
            ticker_data_temp.price_low = price_low_temp;
            ticker_data_temp.price_close = price_close_temp;

            auto year = date_temp.sliced(0,4).toInt();
            auto month = date_temp.sliced(4,2).toInt();
            auto day = date_temp.sliced(6,2).toInt();

            auto hour = time_temp.sliced(0,2).toInt();
            auto minute = time_temp.sliced(2,2).toInt();
            auto second = time_temp.sliced(4,2).toInt();

            date.setDate(year,month,day);
            time.setHMS(hour,minute,second);

            dateTime.setDate(date);
            dateTime.setTime(time);
            std::int64_t timestemp = dateTime.toMSecsSinceEpoch();

            ticker_qhash.insert(timestemp, ticker_data_temp);
        }
    }
}

QList<std::int64_t> *DataReader::timestempList(const QDateTime dt_begin,const QDateTime dt_end,const Scale scale)
{
    auto *timestempList = new QList<std::int64_t>;

    std::int64_t timestemp = dt_begin.toMSecsSinceEpoch();
    std::int64_t timestemp_end = dt_end.toMSecsSinceEpoch();

    switch (scale) {
    case Scale_Hour:
    {
        while (timestemp<=timestemp_end) {
            timestempList->append(timestemp);
            timestemp += 300000;
        }
        break;
    }

    default:
        break;
    }

    return timestempList;
}

QCandlestickSet *DataReader::getSet(const std::int64_t timestamp, const Scale scale)
{
    QCandlestickSet *box = new QCandlestickSet();

    auto ticker = ticker_qhash.value(timestamp);

    box->setHigh(ticker.price_high);
    box->setLow(ticker.price_low);
    box->setOpen(ticker.price_open);
    box->setClose(ticker.price_close);
    box->setTimestamp(timestamp);

    return box;
}
