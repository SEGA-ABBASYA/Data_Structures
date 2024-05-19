#include "Buildingchoose.h"
#include "ui_Buildingchoose.h"
bool BuildingChoose::right;
bool BuildingChoose::left;

BuildingChoose::BuildingChoose(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BuildingChoose)
{
    ui->setupUi(this);
}

BuildingChoose::~BuildingChoose()
{
    delete ui;
}

void BuildingChoose::on_pushButton_2_clicked(bool checked)
{
    left = checked;
    right = false;
    close();
}


void BuildingChoose::on_pushButton_clicked(bool checked)
{
    right = checked;
    left = false;
    close();
}

