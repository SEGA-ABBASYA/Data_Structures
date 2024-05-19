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

    void on_menuButton_toggled();

    void on_menuButton_3_toggled();

    void on_backButton_2_clicked();

    void on_nextButton_2_clicked();

    void on_previousButton_2_clicked();

private:
    Ui::Firstfloor_general *ui;
};

#endif // FIRSTFLOOR_GENERAL_H
