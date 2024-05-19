#ifndef FLOORTRANSITION_H
#define FLOORTRANSITION_H

#include <QTimer>
#include <QWidget>
#include <QMovie>
#include <QThread>
#include <vector>
#include <string>
using namespace std;

namespace Ui {
class FloorTransition;
}

class FloorTransition : public QWidget
{
    Q_OBJECT

public:
    explicit FloorTransition(QWidget *parent = nullptr);
    ~FloorTransition();
    void startAnimation();

private slots:


    void on_pushButton_clicked();

private:
    Ui::FloorTransition *ui;

};

#endif // FLOORTRANSITION_H
