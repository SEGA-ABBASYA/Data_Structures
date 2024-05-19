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

    void on_creditBtn_clicked();

    void on_IJICIS_clicked();

    void on_SWBtn_clicked();

    void on_Room3Btn_clicked();

    void on_Room2Btn_clicked();

    void on_SaiedHallBtn_clicked();

    void on_Prayer_clicked();

    void on_DrAbdElAzizBtn_clicked();

    void on_DrKhalifaBtn_clicked();

    void on_WC_clicked();

    void on_TAsRoomBtn_clicked();

private:
    Ui::SecondFloorOther *ui;
};

#endif // SECONDFLOOROTHER_H
