#include "ThirdFloor.h"
#include "ui_ThirdFloor.h"
#include"database.h"
#include <QMessageBox>
ThirdFloor::ThirdFloor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ThirdFloor)
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
            string row = Database::ThirdFloor[i];
            if(row[j] == '+')
            {
                item->setFlags(item->flags() & !~Qt::ItemIsSelectable);
            }

        }
    }

}


ThirdFloor::~ThirdFloor()
{
    delete ui;
}

void ThirdFloor::on_room1_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr Huda Amin, Dr Dina Fawzy, Dr Eman Amin");
}


void ThirdFloor::on_room2_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr Sayed Fadel, Dr Mahmoud Elgamal");
}



void ThirdFloor::on_room3_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr Howayda Abdelfatah");
}

void ThirdFloor::on_room4_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr Salsabeel Amin, Dr Dina Khattab");
}


void ThirdFloor::on_room5_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr Eslam Hegazy, Dr Manal Tantawy, Dr Shimaa Abu Elyan");
}




void ThirdFloor::on_room6_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr Esraa Abdelraouf, Dr Mervat el Qut, Dr Wedad Hussein, Dr Heba Khaled, Dr Safeya Abas");
}


void ThirdFloor::on_room7_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr walaa khaled ibn al waleed (Head of IS dept)");
}



void ThirdFloor::on_fahmyTolba_clicked()
{
    QMessageBox::information(this, "Room Name", "Fahmy Tolba Hall");
}


void ThirdFloor::on_wcM_clicked()
{
    QMessageBox::information(this, "Room Name", "Male WC");
}


void ThirdFloor::on_wcF_clicked()
{
    QMessageBox::information(this, "Room Name", "Female WC");
}


void ThirdFloor::on_sweL1_clicked()
{
    QMessageBox::information(this, "Room Name", "SWE Lab 1");
}


void ThirdFloor::on_sweL2_clicked()
{
    QMessageBox::information(this, "Room Name", "SWE Lab 2");
}

