#ifndef BOXDATAREADER_H
#define BOXDATAREADER_H

#include <QtCore/QTextStream>
#include <QtCharts/QBoxSet>

QT_USE_NAMESPACE

class BoxDataReader : public QTextStream
{
public:
    void readFile(QIODevice *device);
    QBoxSet *readBox();
private:
    QList<qreal> sortedList;
    qreal findMedian(int begin, int end);
};

#endif // BOXDATAREADER_H
