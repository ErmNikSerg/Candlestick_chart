#ifndef DATEANDTIME_DIALOG_H
#define DATEANDTIME_DIALOG_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

class DateAndTime_dialog : public QWidget
{
    Q_OBJECT
public:
    explicit DateAndTime_dialog(QWidget *parent = nullptr);

signals:

};

#endif // DATEANDTIME_DIALOG_H
