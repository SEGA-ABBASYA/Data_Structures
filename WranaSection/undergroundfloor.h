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

private:
    Ui::UndergroundFloor *ui;
};

#endif // UNDERGROUNDFLOOR_H
