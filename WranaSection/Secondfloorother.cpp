#include "Secondfloorother.h"
#include "ui_Secondfloorother.h"
#include<database.h>


SecondFloorOther::SecondFloorOther(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecondFloorOther)
{
    ui->setupUi(this);



    for(int i = 0; i < 67; i++){
        for(int j = 0; j < 85; j++) if(Database::SecondOtherFloor[i][j] == '+'){
                ui->SecondF_widget_2->setItem(i, j, new QTableWidgetItem());
                ui->SecondF_widget_2->item(i, j)->setFlags(Qt::NoItemFlags);
            }
        // qDebug() << second[i] << '\n';
    }
}


SecondFloorOther::~SecondFloorOther()
{
    delete ui;
}
