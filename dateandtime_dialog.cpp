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
    yearLineEdit->setPlaceholderText("2022");
    yearLineEdit->setReadOnly(true);
    QLineEdit *monthLineEdit = new QLineEdit;
    monthLineEdit->setPlaceholderText("01");
    monthLineEdit->setReadOnly(true);
    QLineEdit *dayLineEdit = new QLineEdit;
    dayLineEdit->setPlaceholderText("01");
    dayLineEdit->setReadOnly(true);

    QLineEdit *hourLineEdit = new QLineEdit;
    hourLineEdit->setPlaceholderText("07");
    hourLineEdit->setReadOnly(true);
    QLineEdit *minuteLineEdit = new QLineEdit;
    minuteLineEdit->setPlaceholderText("00");
    minuteLineEdit->setReadOnly(true);
    QLineEdit *secondLineEdit = new QLineEdit;
    secondLineEdit->setPlaceholderText("00");
    secondLineEdit->setReadOnly(true);

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
}
