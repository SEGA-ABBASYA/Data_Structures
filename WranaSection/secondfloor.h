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

private slots:
    void on_SecondF_widget_2_cellActivated(int row, int column);

    void on_SecondF_widget_cellActivated(int row, int column);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::SecondFloor *ui;
};

#endif // SECONDFLOOR_H
