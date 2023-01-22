#include "fileverification.h"

FileVerification::FileVerification(QWidget *parent)
    : QWidget{parent}
{
    QString fileVerifStatus("File read");

    QLabel *pathToFileLabel = new QLabel("Path to file with stock exchange data");
    QLineEdit *pathToFileLineEdit = new QLineEdit;
    QPushButton *fileVerifButton = new QPushButton;
    QLabel *fileVerifStatusLabel = new QLabel(fileVerifStatus);

    QSize longSize(325,20);
    pathToFileLabel->setFixedSize(longSize);
    pathToFileLineEdit->setFixedSize(longSize);

    QSize midSize(160,20);
    fileVerifStatusLabel->setFixedSize(midSize);
    fileVerifButton->setFixedSize(midSize);

    fileVerifButton->setText("Read file");

    pathToFileLineEdit->setPlaceholderText("C:/Qt_Projects/St_ex/Initial_Data/GAZPROM_2022.txt");
    pathToFileLineEdit->setReadOnly(true);

    pathToFileLabel->setAlignment(Qt::AlignCenter);

    pathToFileLabel->setObjectName("pathToFileLabel");

    QGridLayout *fileFerification = new QGridLayout(this);
    fileFerification->addWidget(pathToFileLabel,0,0,1,2);
    fileFerification->addWidget(pathToFileLineEdit,1,0,1,2);
    fileFerification->addWidget(fileVerifButton,2,0);
    fileFerification->addWidget(fileVerifStatusLabel,2,1);
    fileFerification->setSpacing(5);
    fileFerification->setContentsMargins(0,0,0,0);
    fileFerification->setAlignment(fileVerifStatusLabel,Qt::AlignRight);

    QSize widSize(325, 70);
    this->setFixedSize(widSize);
}
