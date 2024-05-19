#include "firstfloor_credit.h"
#include "ui_firstfloor_credit.h"
#include"database.h"
#include <iostream>
using namespace std;

firstfloor_credit::firstfloor_credit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::firstfloor_credit)
{
    ui->setupUi(this);


    for(int i =0;i<(42);i++)
    {
        ui->tableWidget->setColumnWidth(i,30);
    }
    for (int i=0;i<(36);i++)
    {
        ui->tableWidget->setRowHeight(i, 20);

    }



    for(int i = 0; i < ui->tableWidget->rowCount(); ++i) {

        for(int j = 0; j < ui->tableWidget->columnCount(); ++j) {

            auto item = ui->tableWidget->item(i, j);
            if(!item) { // make sure there's an item in that cell
                item= new QTableWidgetItem();
                ui->tableWidget->setItem(i, j, item);
            }
            if(Database::FirstCreditFloor[i][j]!='.')
                item->setFlags(item->flags() & !~Qt::ItemIsSelectable);

        }
    }

}

firstfloor_credit::~firstfloor_credit()
{
    delete ui;
}



void firstfloor_credit::on_tableWidget_cellActivated(int row, int column)
{
    string r = to_string (row);
    string c = to_string(column);
    QString s = QString::fromStdString(r + " " + c) ;
    //ui->label_2->setText(s) ;
    cout<<row<<" "<<column<<endl;
}

