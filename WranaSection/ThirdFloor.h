#ifndef THIRDFLOOR_H
#define THIRDFLOOR_H

#include <QWidget>
#include <string>
#include <vector>
using namespace std;

namespace Ui {
class ThirdFloor;
}

class ThirdFloor : public QWidget
{
    Q_OBJECT

public:
    explicit ThirdFloor(QWidget *parent = nullptr);
    ~ThirdFloor();




private slots:
    void on_room1_clicked();

    void on_room2_clicked();

    void on_room3_clicked();

    void on_room4_clicked();

    void on_room5_clicked();

    void on_room6_clicked();

    void on_room7_clicked();

    void on_fahmyTolba_clicked();

    void on_wcM_clicked();

    void on_wcF_clicked();

    void on_sweL1_clicked();

    void on_sweL2_clicked();

private:
    Ui::ThirdFloor *ui;
};

#endif // THIRDFLOOR_H
