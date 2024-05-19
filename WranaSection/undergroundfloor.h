#ifndef UNDERGROUNDFLOOR_H
#define UNDERGROUNDFLOOR_H

#include <QWidget>
#include <string>
#include <vector>
using namespace std;

namespace Ui {
class UndergroundFloor;
}

class UndergroundFloor : public QWidget
{
    Q_OBJECT

public:
    explicit UndergroundFloor(QWidget *parent = nullptr);
    ~UndergroundFloor();

private slots:
    void on_tableWidget_cellActivated(int row, int column);



    void on_storage1_clicked();

    void on_room1_clicked();

    void on_room2_clicked();

    void on_class6_clicked();

    void on_room3_clicked();

    void on_class5_clicked();

    void on_room4_clicked();

    void on_csSystem_clicked();

    void on_room5_clicked();

    void on_electronics_clicked();

    void on_storage2_clicked();

    void on_equipMaintenance_clicked();

    void on_room6_clicked();

    void on_room7_clicked();

    void on_room8_clicked();

private:
    Ui::UndergroundFloor *ui;
};

#endif // UNDERGROUNDFLOOR_H
