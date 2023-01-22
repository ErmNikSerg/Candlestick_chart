#include "main_dialog.h"

Main_dialog::Main_dialog(QWidget *parent)
    : QWidget(parent)
{ 
    QLabel *pathToFileLabel = new QLabel("Path to file with stock exchange data");

    QLineEdit *pathToFileLineEdit = new QLineEdit;
    pathToFileLineEdit->setPlaceholderText("C:/Qt_Projects/St_ex/Initial_Data/GAZPROM_2022.txt");
    pathToFileLineEdit->setReadOnly(true);

    QLabel *startDateTimeLabel = new QLabel("Start Date and Time");
    QLabel *endDateTimeLabel = new QLabel("End Date and Time");
    DateAndTime_dialog *dat_begin = new DateAndTime_dialog;
    DateAndTime_dialog *dat_end = new DateAndTime_dialog;

    QGridLayout *mainDialog = new QGridLayout(this);
    mainDialog->addWidget(pathToFileLabel,0,0);
    mainDialog->addWidget(pathToFileLineEdit,1,0);
    mainDialog->addWidget(startDateTimeLabel,4,0);
    mainDialog->addWidget(endDateTimeLabel,4,1);
    mainDialog->addWidget(dat_begin,5,0);
    mainDialog->addWidget(dat_end,5,1);
}

Main_dialog::~Main_dialog()
{
}
