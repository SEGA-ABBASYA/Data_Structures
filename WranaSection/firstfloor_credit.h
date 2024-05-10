#ifndef FIRSTFLOOR_CREDIT_H
#define FIRSTFLOOR_CREDIT_H

#include <QMainWindow>
#include<string>
#include<QString>
#include <iostream>
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

 private:
    Ui::firstfloor_credit *ui;
};

#endif // FIRSTFLOOR_CREDIT_H
