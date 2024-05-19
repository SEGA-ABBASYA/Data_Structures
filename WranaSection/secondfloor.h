#ifndef SECONDFLOOR_H
#define SECONDFLOOR_H
#include <iostream>
using namespace std;
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


private slots:
    void on_menuButton_3_toggled();

    void on_menuButton_toggled();

    void on_backButton_2_clicked();

    void on_nextButton_2_clicked();

    void on_previousButton_2_clicked();

private:
    Ui::SecondFloor *ui;
};

#endif // SECONDFLOOR_H
