#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

class Main_dialog: public QWidget
{
     Q_OBJECT

     public:
        explicit Main_dialog(QWidget *parent = nullptr);     

     protected:

};

#endif // MAIN_DIALOG_H
