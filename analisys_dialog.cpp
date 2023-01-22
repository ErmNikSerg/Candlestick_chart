#include "analisys_dialog.h"
#include "dateandtime_dialog.h"

Analisys_dialog::Analisys_dialog(QWidget *parent)
    : QWidget{parent}
{
    QLabel *analisysLabel = new QLabel("Analisys stock exchange");
    QLabel *datAnBeginLabel = new QLabel("Time analysis begin");
    QLabel *datAnEndLabel = new QLabel("Time analysis end");
    DateAndTime_dialog *dat_analisys_begin = new DateAndTime_dialog;
    DateAndTime_dialog *dat_analisys_end = new DateAndTime_dialog;
    QLabel *taxLabel = new QLabel("Tax, %");
    QLineEdit *taxLineEdit = new QLineEdit;
    QLabel *brokerComissionLabel = new QLabel("Broker Comission, %");
    QLineEdit *brokerComissionLineEdit = new QLineEdit;
    QLabel *analisysButLabel = new QLabel("The algorithm will find the pattern:");
    QPushButton *analisysButton = new QPushButton;
    analisysButton->setText("Run");
    QLabel *analisysOutputLabel = new QLabel("analisysOutputLabel");

    QSize longSize(325,20);
    analisysLabel->setFixedSize(longSize);

    QSize midSize(160,20);
    datAnBeginLabel->setFixedSize(midSize);
    datAnEndLabel->setFixedSize(midSize);

    QSize smallSize(50,20);
    taxLabel->setFixedSize(smallSize);
    taxLineEdit->setFixedSize(smallSize);
    brokerComissionLineEdit->setFixedSize(smallSize);
    analisysButton->setFixedSize(smallSize);

    QSize analisysButLabelSize(270,20);
    analisysButLabel->setFixedSize(analisysButLabelSize);

    QSize brokerComissionLabelSize(160,20);  
    brokerComissionLabel->setFixedSize(brokerComissionLabelSize);

    QSize analisysOutputLabelSize(325,60);
    analisysOutputLabel->setFixedSize(analisysOutputLabelSize);

    taxLineEdit->setPlaceholderText("13");
    taxLineEdit->setReadOnly(true);

    brokerComissionLineEdit->setPlaceholderText("0.15");
    brokerComissionLineEdit->setReadOnly(true);

    analisysLabel->setAlignment(Qt::AlignCenter);
    datAnBeginLabel->setAlignment(Qt::AlignCenter);
    datAnEndLabel->setAlignment(Qt::AlignCenter);
    taxLineEdit->setAlignment(Qt::AlignCenter);
    brokerComissionLineEdit->setAlignment(Qt::AlignCenter);

    analisysLabel->setObjectName("analisysLabel");

    QGridLayout *analisysDialog = new QGridLayout(this);
    analisysDialog->addWidget(analisysLabel,0,0);
    analisysDialog->addWidget(datAnBeginLabel,1,0,1,3);
    analisysDialog->addWidget(datAnEndLabel,1,3,1,3);
    analisysDialog->addWidget(dat_analisys_begin,2,0,1,3);
    analisysDialog->addWidget(dat_analisys_end,2,3,1,3);
    analisysDialog->addWidget(taxLabel,3,0);
    analisysDialog->addWidget(taxLineEdit,3,1);
    analisysDialog->addWidget(brokerComissionLabel,3,2,1,3);
    analisysDialog->addWidget(brokerComissionLineEdit,3,5);
    analisysDialog->addWidget(analisysButLabel,4,0,1,5);
    analisysDialog->addWidget(analisysButton,4,5);
    analisysDialog->addWidget(analisysOutputLabel,5,0,1,6);
    analisysDialog->setSpacing(5);
    analisysDialog->setContentsMargins(0,0,0,0);

    QSize widSize(325, 260);
    this->setFixedSize(widSize);



}
