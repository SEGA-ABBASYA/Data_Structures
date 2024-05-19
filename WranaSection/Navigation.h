#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QDialog>

namespace Ui {
class Navigation;
}

class Navigation : public QDialog
{
    Q_OBJECT

public:
    explicit Navigation(QWidget *parent = nullptr);
    ~Navigation();

private:
    Ui::Navigation *ui;
};

#endif // NAVIGATION_H
