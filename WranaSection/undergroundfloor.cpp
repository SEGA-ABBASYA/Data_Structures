#include "undergroundfloor.h"
#include "ui_undergroundfloor.h"
#include"database.h"
#include <iostream>
#include <QMessageBox>
using namespace std;

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


    for(int i = 0; i < ui->tableWidget->rowCount(); ++i) {

        for(int j = 0; j < ui->tableWidget->columnCount(); ++j) {

            auto item = ui->tableWidget->item(i, j);
            if(!item) { // make sure there's an item in that cell
                item= new QTableWidgetItem();
                ui->tableWidget->setItem(i, j, item);
            }
            string row =  Database::UnderGroundFloor[i];
            if(row[j] == '+')
            {
                item->setFlags(item->flags() & !~Qt::ItemIsSelectable);
            }

        }
    }
}



UndergroundFloor::~UndergroundFloor()
{
    delete ui;
}

void UndergroundFloor::on_tableWidget_cellActivated(int row, int column)
{
    cout<<row<<" "<<column<<endl;
}


void UndergroundFloor::on_storage1_clicked()
{
    QMessageBox::information(this, "Room Name", "Storage");
}


void UndergroundFloor::on_storage2_clicked()
{
    QMessageBox::information(this, "Room Name", "Storage");
}

void UndergroundFloor::on_class5_clicked()
{
    QMessageBox::information(this, "Room Name", "Class 5");
}



void UndergroundFloor::on_class6_clicked()
{
    QMessageBox::information(this, "Room Name", "Class 6");
}

void UndergroundFloor::on_csSystem_clicked()
{
    QMessageBox::information(this, "Room Name", "CS System");
}

void UndergroundFloor::on_electronics_clicked()
{
    QMessageBox::information(this, "Room Name", "Electronics");
}

void UndergroundFloor::on_equipMaintenance_clicked()
{
    QMessageBox::information(this, "Room Name", "Equipment Maintenance Department");
}

void UndergroundFloor::on_room1_clicked()
{
    QMessageBox::information(this, "Room Name", "Room");
}


void UndergroundFloor::on_room2_clicked()
{
    QMessageBox::information(this, "Room Name", "Room");
}



void UndergroundFloor::on_room3_clicked()
{
    QMessageBox::information(this, "Room Name", "Room");
}

void UndergroundFloor::on_room4_clicked()
{
    QMessageBox::information(this, "Room Name", "Room");
}


void UndergroundFloor::on_room5_clicked()
{
    QMessageBox::information(this, "Room Name", "Room");
}


void UndergroundFloor::on_room6_clicked()
{
    QMessageBox::information(this, "Room Name", "Room");
}


void UndergroundFloor::on_room7_clicked()
{
    QMessageBox::information(this, "Room Name", "Room");
}


void UndergroundFloor::on_room8_clicked()
{
    QMessageBox::information(this, "Room Name", "Room");
}

