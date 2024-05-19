#ifndef GROUNDFLOOR_H
#define GROUNDFLOOR_H
#include <vector>
#include <string>
#include <QWidget>
using namespace std;

namespace Ui {
class GroundFloor;
}

class GroundFloor : public QWidget
{
    Q_OBJECT

public:

    explicit GroundFloor(QWidget *parent = nullptr);
    ~GroundFloor();

private slots:
    void on_tableWidget_cellClicked(int row, int column);

    void on_backButton_4_clicked();

    void on_menuButton_toggled();

    void on_menuButton_5_toggled();

    void on_nextButton_2_clicked();

    void on_previousButton_2_clicked();

private:
    Ui::GroundFloor *ui;
};

#endif // GROUNDFLOOR_H
