#ifndef SECONDFLOOROTHER_H
#define SECONDFLOOROTHER_H
#include <iostream>
#include<vector>
using namespace std;
#include <QWidget>

namespace Ui {
class SecondFloorOther;
}

class SecondFloorOther : public QWidget
{
    Q_OBJECT

public:
    explicit SecondFloorOther(QWidget *parent = nullptr);
    vector<string> CreateGrid();
    ~SecondFloorOther();

private slots:
    void on_SecondF_widget_2_cellActivated(int row, int column);
    void on_menuButton_toggled();

    void on_menuButton_3_toggled();

    void on_nextButton_2_clicked();

    void on_previousButton_2_clicked();

    void on_backButton_2_clicked();

private:
    Ui::SecondFloorOther *ui;
};

#endif // SECONDFLOOROTHER_H
