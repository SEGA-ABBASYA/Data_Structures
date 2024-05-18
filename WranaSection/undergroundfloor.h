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

    void on_nextButton_2_clicked();

    void on_previousButton_2_clicked();

    void on_backButton_2_clicked();

    void on_menuButton_toggled();

    void on_menuButton_3_toggled();

private:
    Ui::UndergroundFloor *ui;
};

#endif // UNDERGROUNDFLOOR_H
