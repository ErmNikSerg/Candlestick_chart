#include "dateandtime_dialog.h"

DateAndTime_dialog::DateAndTime_dialog(QWidget *parent)
    : QWidget{parent}
{
    QLabel *yearLabel = new QLabel("Year");
    QLabel *monthLabel = new QLabel("Month");
    QLabel *dayLabel = new QLabel("Day");
    QLabel *hourLabel = new QLabel("Hour");
    QLabel *minuteLabel = new QLabel("Minute");
    QLabel *secondLabel = new QLabel("Second");

    QLineEdit *yearLineEdit = new QLineEdit;
    yearLineEdit->setPlaceholderText(year_str);
    yearLineEdit->setReadOnly(true);
    QLineEdit *monthLineEdit = new QLineEdit;
    monthLineEdit->setPlaceholderText(month_str);
    monthLineEdit->setReadOnly(true);
    QLineEdit *dayLineEdit = new QLineEdit;
    dayLineEdit->setPlaceholderText(day_str);
    dayLineEdit->setReadOnly(true);
    QLineEdit *hourLineEdit = new QLineEdit;
    hourLineEdit->setPlaceholderText(hour_str);
    hourLineEdit->setReadOnly(true);
    QLineEdit *minuteLineEdit = new QLineEdit;
    minuteLineEdit->setPlaceholderText(minute_str);
    minuteLineEdit->setReadOnly(true);
    QLineEdit *secondLineEdit = new QLineEdit;
    secondLineEdit->setPlaceholderText(second_str);
    secondLineEdit->setReadOnly(true);

    QSize smallSize(50,20);

    yearLineEdit->setFixedSize(smallSize);
    monthLineEdit->setFixedSize(smallSize);
    dayLineEdit->setFixedSize(smallSize);
    hourLineEdit->setFixedSize(smallSize);
    minuteLineEdit->setFixedSize(smallSize);
    secondLineEdit->setFixedSize(smallSize);
    yearLabel->setFixedSize(smallSize);
    monthLabel->setFixedSize(smallSize);
    dayLabel->setFixedSize(smallSize);
    hourLabel->setFixedSize(smallSize);
    minuteLabel->setFixedSize(smallSize);
    secondLabel->setFixedSize(smallSize);

    yearLabel->setAlignment(Qt::AlignCenter);
    monthLabel->setAlignment(Qt::AlignCenter);
    dayLabel->setAlignment(Qt::AlignCenter);
    hourLabel->setAlignment(Qt::AlignCenter);
    minuteLabel->setAlignment(Qt::AlignCenter);
    secondLabel->setAlignment(Qt::AlignCenter);
    yearLineEdit->setAlignment(Qt::AlignCenter);
    monthLineEdit->setAlignment(Qt::AlignCenter);
    dayLineEdit->setAlignment(Qt::AlignCenter);
    hourLineEdit->setAlignment(Qt::AlignCenter);
    minuteLineEdit->setAlignment(Qt::AlignCenter);
    secondLineEdit->setAlignment(Qt::AlignCenter);

    QGridLayout *dateAndTimeDialog = new QGridLayout(this);
    dateAndTimeDialog->addWidget(yearLabel,0,0);
    dateAndTimeDialog->addWidget(monthLabel,0,1);
    dateAndTimeDialog->addWidget(dayLabel,0,2);
    dateAndTimeDialog->addWidget(yearLineEdit,1,0);
    dateAndTimeDialog->addWidget(monthLineEdit,1,1);
    dateAndTimeDialog->addWidget(dayLineEdit,1,2);
    dateAndTimeDialog->addWidget(hourLabel,2,0);
    dateAndTimeDialog->addWidget(minuteLabel,2,1);
    dateAndTimeDialog->addWidget(secondLabel,2,2);
    dateAndTimeDialog->addWidget(hourLineEdit,3,0);
    dateAndTimeDialog->addWidget(minuteLineEdit,3,1);
    dateAndTimeDialog->addWidget(secondLineEdit,3,2);
    dateAndTimeDialog->setSpacing(5);
    dateAndTimeDialog->setContentsMargins(0,0,0,0);

    QSize widSize(160, 95);
    this->setFixedSize(widSize);
}

QDateTime DateAndTime_dialog::getdateTime()
{
    QDate date;
    QTime time;
    QDateTime dateTime(date,time);

    auto year = year_str.toInt();
    auto month = month_str.toInt();
    auto day = day_str.toInt();

    auto hour = hour_str.toInt();
    auto minute = minute_str.toInt();
    auto second = second_str.toInt();

    date.setDate(year,month,day);
    time.setHMS(hour,minute,second);

    dateTime.setDate(date);
    dateTime.setTime(time);

    return dateTime;
}
