#include "Navigation.h"
#include "ui_Navigation.h"

Navigation::Navigation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Navigation)
{
    ui->setupUi(this);
}

Navigation::~Navigation()
{
    delete ui;
}
