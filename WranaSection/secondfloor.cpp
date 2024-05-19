#include "secondfloor.h"
#include "ui_secondfloor.h"
#include"database.h"
#include <QDebug>
using namespace::std;

SecondFloor::SecondFloor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecondFloor)
{
    ui->setupUi(this);




    for(int i = 0; i < 47; i++){
        for(int j = 0; j < 76; j++) if(Database::SecondFloor[i][j] == '+'){
                ui->SecondF_widget->setItem(i, j, new QTableWidgetItem());
                ui->SecondF_widget->item(i, j)->setFlags(Qt::NoItemFlags);
            }
    }
}

SecondFloor::~SecondFloor()
{
    delete ui;
}


void SecondFloor::on_SecondF_widget_cellActivated(int row, int column)
{
    cout<<row<<" "<<column<<endl;
}

