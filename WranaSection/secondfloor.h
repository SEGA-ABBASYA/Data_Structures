#ifndef SECONDFLOOR_H
#define SECONDFLOOR_H

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


private:
    Ui::SecondFloor *ui;
};

#endif // SECONDFLOOR_H
