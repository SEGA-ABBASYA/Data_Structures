#include "undergroundfloor.h"
#include "ui_undergroundfloor.h"

UndergroundFloor::UndergroundFloor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UndergroundFloor)
{
    ui->setupUi(this);
    for(int i =0;i<76;i++)
    {
        ui->tableWidget->setColumnWidth(i,17);
    }
    for (int i=0;i<37;i++)
    {
        ui->tableWidget->setRowHeight(i, 20);
    }

    // vector<string> grid = CreateGrid();

    // for(int i = 0; i < ui->tableWidget->rowCount(); ++i) {

    //     for(int j = 0; j < ui->tableWidget->columnCount(); ++j) {

    //         auto item = ui->tableWidget->item(i, j);
    //         if(!item) { // make sure there's an item in that cell
    //             item= new QTableWidgetItem();
    //             ui->tableWidget->setItem(i, j, item);
    //         }
    //         string row = grid[i];
    //         if(row[j] == '+')
    //         {
    //             item->setFlags(item->flags() & !~Qt::ItemIsSelectable);
    //         }

    //     }
    // }
}


UndergroundFloor::~UndergroundFloor()
{
    delete ui;
}
