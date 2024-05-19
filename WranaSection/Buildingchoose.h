#ifndef BUILDINGCHOOSE_H
#define BUILDINGCHOOSE_H

#include <QDialog>

namespace Ui {
class BuildingChoose;
}

class BuildingChoose : public QDialog
{
    Q_OBJECT

public:
    static bool right,left;
    explicit BuildingChoose(QWidget *parent = nullptr);
    ~BuildingChoose();

private slots:
    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_clicked(bool checked);

private:
    Ui::BuildingChoose *ui;
};

#endif // BUILDINGCHOOSE_H
