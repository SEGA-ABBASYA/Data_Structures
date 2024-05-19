#ifndef FIRSTFLOOR_GENERAL_H
#define FIRSTFLOOR_GENERAL_H

#include <QMainWindow>
#include<string>
#include<QString>
#include <iostream>
#include<QMessageBox>
using namespace std;

namespace Ui {
class Firstfloor_general;
}

class Firstfloor_general : public QMainWindow
{
    Q_OBJECT

public:
    explicit Firstfloor_general(QWidget *parent = nullptr);
    vector<string> write_Graph_general();
    ~Firstfloor_general();

private slots:
    void on_tableWidget_cellActivated(int row, int column);

    void on_ConferenceHall_clicked();

    void on_SecretaryOffice_clicked();

    void on_SeminarHall_clicked();

    void on_QualityOffice_clicked();

    void on_SecretaryQuality_clicked();

    void on_PostgraduateHALL_clicked();

    void on_WC_W_clicked();

    void on_WC_M_clicked();

    void on_ResearchLaboratory_clicked();

    void on_SecrataryForGraduate_clicked();

    void on_OfficeForGraduate_clicked();

    void on_TechnicallOffice_clicked();

    void on_AffairsOffice_clicked();

    void on_WC_clicked();

    void on_Buffet_clicked();

    void on_Elevators_clicked();

    void on_DR_HalaMoshir_clicked();

    void on_DR_TamerMustafa_clicked();

    void on_CollageSecretary_clicked();

    void on_CollageOffice_clicked();

    void on_MainLadder_clicked();

    void on_EmergencyLadder_clicked();

    void on_BackLadder_clicked();

private:
    Ui::Firstfloor_general *ui;
};

#endif // FIRSTFLOOR_GENERAL_H
