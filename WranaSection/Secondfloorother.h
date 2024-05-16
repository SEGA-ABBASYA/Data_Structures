#ifndef SECONDFLOOROTHER_H
#define SECONDFLOOROTHER_H

#include <QWidget>

namespace Ui {
class SecondFloorOther;
}

class SecondFloorOther : public QWidget
{
    Q_OBJECT

public:
    explicit SecondFloorOther(QWidget *parent = nullptr);
    ~SecondFloorOther();

private:
    Ui::SecondFloorOther *ui;
};

#endif // SECONDFLOOROTHER_H
