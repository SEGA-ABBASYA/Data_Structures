#include "Groundfloor.h"
#include "ui_Groundfloor.h"
#include <QStandardItem>
#include "database.h"
#include <vector>
#include <iostream>
#include "User_View.h"
using namespace std;
GroundFloor::GroundFloor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GroundFloor)
{

    ui->setupUi(this);
    Database::groundFloorTable = ui->tableWidget;
    ui->verticalLayoutWidget->hide();

    for(int i =0;i<ui->tableWidget->columnCount();i++)
    {
        ui->tableWidget->setColumnWidth(i,17);
    }
    for (int i=0;i<ui->tableWidget->rowCount();i++)
    {
        ui->tableWidget->setRowHeight(i, 20);
    }



    for(int i = 0; i < ui->tableWidget->rowCount(); ++i) {

        for(int j = 0; j < ui->tableWidget->columnCount(); ++j) {

            auto item = ui->tableWidget->item(i, j);
            if(!item)
            { // make sure there's an item in that cell
                item= new QTableWidgetItem();
                ui->tableWidget->setItem(i, j, item);
            }
            string row = Database::GroundFloor[i];
            if(row[j] != '.')
            {
                item->setFlags(item->flags() & !~Qt::ItemIsSelectable);
            }

        }
    }
}


GroundFloor::~GroundFloor()
{
    delete ui;
}

void GroundFloor::on_tableWidget_cellClicked(int row, int column)
{
    cout<<row<<" "<<column<<endl;
}


void GroundFloor::on_backButton_4_clicked()
{

    UserView::g_stack->setCurrentIndex(0);
}


void GroundFloor::on_menuButton_toggled()
{

        ui->verticalLayoutWidget->show();
        ui->menuButton->hide();
}


void GroundFloor::on_menuButton_5_toggled()
{

    ui->verticalLayoutWidget->hide();
    ui->menuButton->show();
}


void GroundFloor::on_nextButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(UserView::g_stack->currentIndex() + 1);
}


void GroundFloor::on_previousButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(UserView::g_stack->currentIndex() - 1);
}

