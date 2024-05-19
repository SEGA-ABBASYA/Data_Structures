#ifndef FIRSTFLOOR_CREDIT_H
#define FIRSTFLOOR_CREDIT_H

#include <QMainWindow>
#include<string>
#include<QString>
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
     vector<string> write_Graph_credit();
    ~firstfloor_credit();

 private slots:
     void on_tableWidget_cellActivated(int row, int column);





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
