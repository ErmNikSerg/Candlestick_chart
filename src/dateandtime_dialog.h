#ifndef DATEANDTIME_DIALOG_H
#define DATEANDTIME_DIALOG_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateTime>

class DateAndTime_dialog : public QWidget
{
    Q_OBJECT
public:
    explicit DateAndTime_dialog(QWidget *parent = nullptr);
    QDateTime getdateTime();

signals:

private:
    QString year_str = "2022";
    QString month_str = "01";
    QString day_str = "14";
    QString hour_str = "7";
    QString minute_str = "0";
    QString second_str = "0";
};

#endif // DATEANDTIME_DIALOG_H
