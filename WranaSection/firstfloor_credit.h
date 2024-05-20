#ifndef FIRSTFLOOR_CREDIT_H
#define FIRSTFLOOR_CREDIT_H

#include <QMainWindow>
#include<string>
#include<QString>
#include<vector>
#include <iostream>
#include<QMessageBox>
using namespace std;

namespace Ui {
class firstfloor_credit;
}

class firstfloor_credit : public QMainWindow
{
    Q_OBJECT

public:
    explicit firstfloor_credit(QWidget *parent = nullptr);
    ~firstfloor_credit();

 private slots:
     void on_tableWidget_cellActivated(int row, int column);

     void on_menuButton_toggled();

     void on_backButton_2_clicked();

     void on_previousButton_2_clicked();

     void on_nextButton_2_clicked();

     void on_menuButton_3_toggled();




     void on_class1_clicked();

     void on_class2_1_clicked();



     void on_class3_clicked();



     void on_programs_office_clicked();


     void on_WCgirls_clicked();

     void on_ProgramDirector_clicked();

     void on_MultiMedia_Bioinformatics_clicked();

 private:
    Ui::firstfloor_credit *ui;
};

#endif // FIRSTFLOOR_CREDIT_H
