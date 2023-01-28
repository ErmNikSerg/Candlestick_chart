#include "mainwindow.h"
#include "stock_quotes_chart.h"
#include "main_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto* central_widget = new QWidget;
    this->setCentralWidget(central_widget);

    auto stock_quotes_chart = new Stock_quotes_chart;
    auto main_dialog = new Main_dialog;

    auto mainWidSizeH = main_dialog->size().height()+10;
    auto mainWidSizeW = main_dialog->size().width() + stock_quotes_chart->size().width() + 20;

    QGridLayout *mainLayout = new QGridLayout(central_widget);
    mainLayout->addWidget(stock_quotes_chart,0,0);
    mainLayout->addWidget(main_dialog,0,1); 
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(5,5,5,5);

    QSize mainWidSize(mainWidSizeW, mainWidSizeH);
    this->setFixedSize(mainWidSize);
}

MainWindow::~MainWindow()
{
}

