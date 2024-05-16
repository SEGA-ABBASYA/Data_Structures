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
    vector<string> createGrid();
    ~GroundFloor();

private slots:
    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::GroundFloor *ui;
};

#endif // GROUNDFLOOR_H
