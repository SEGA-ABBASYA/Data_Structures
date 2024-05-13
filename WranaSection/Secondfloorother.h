#ifndef SECONDFLOOROTHER_H
#define SECONDFLOOROTHER_H
#include <iostream>
#include<vector>
using namespace std;
#include <QWidget>

namespace Ui {
class SecondFloorOther;
}

class SecondFloorOther : public QWidget
{
    Q_OBJECT

public:
    explicit SecondFloorOther(QWidget *parent = nullptr);
    vector<string> CreateGrid();
    ~SecondFloorOther();

private:
    Ui::SecondFloorOther *ui;
};

#endif // SECONDFLOOROTHER_H
