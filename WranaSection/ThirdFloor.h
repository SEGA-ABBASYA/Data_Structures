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
    void on_tableWidget_cellActivated(int row, int column);

    void on_menuButton_toggled();

    void on_menuButton_3_toggled();

    void on_nextButton_2_clicked();

    void on_previousButton_2_clicked();

    void on_backButton_2_clicked();

private:
    Ui::ThirdFloor *ui;
};

#endif // THIRDFLOOR_H
