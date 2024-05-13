#ifndef FIRSTFLOOR_GENERAL_H
#define FIRSTFLOOR_GENERAL_H

#include <QMainWindow>
#include<string>
#include<QString>
#include<vector>
#include <iostream>
using namespace std;

namespace Ui {
class Firstfloor_general;
}

class Firstfloor_general : public QMainWindow
{
    Q_OBJECT

public:
    explicit Firstfloor_general(QWidget *parent = nullptr);
    ~Firstfloor_general();

private slots:
    void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::Firstfloor_general *ui;
};

#endif // FIRSTFLOOR_GENERAL_H
