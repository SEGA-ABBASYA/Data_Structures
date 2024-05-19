#ifndef SECONDFLOOR_H
#define SECONDFLOOR_H
#include <iostream>
using namespace std;
#include <QWidget>

namespace Ui {
class SecondFloor;
}

class SecondFloor : public QWidget
{
    Q_OBJECT

public:
    explicit SecondFloor(QWidget *parent = nullptr);
    ~SecondFloor();


private slots:
    void on_SecondF_widget_cellActivated(int row, int column);

    void on_BackLadderBtn_clicked();

    void on_RoboticsLabBtn_clicked();

    void on_SecondEntrance_clicked();

    void on_CisLab2Btn_2_clicked();

    void on_CisLab2Btn_clicked();

    void on_ISdepartBtn_clicked();

    void on_ISLabBtn_clicked();

    void on_SCLabBtn_clicked();

    void on_CSDepBtn_clicked();

    void on_CsSecertaryBtn_clicked();

    void on_CentralControlBtn_clicked();

    void on_WC_clicked();

    void on_WC_2_clicked();

    void on_EmergencyBtn_clicked();

    void on_MainLadderBtn_clicked();

    void on_DrAliBtn_clicked();

    void on_SalamOfficeBtn_clicked();

    void on_ZakyOfficeBtn_clicked();

    void on_ElSayedOfficeBtn_clicked();

    void on_NetwrokBtn_clicked();

    void on_StorageBtn_clicked();

    void on_StorageBtn_2_clicked();

    void on_ArefOfficeBtn_clicked();

    void on_ElevatorBtn_clicked();

private:
    Ui::SecondFloor *ui;
};

#endif // SECONDFLOOR_H
