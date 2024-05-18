#include "undergroundfloor.h"
#include "ui_undergroundfloor.h"
#include "database.h"
#include <iostream>
#include <QMessageBox>
#include "User_View.h"
using namespace std;

UndergroundFloor::UndergroundFloor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UndergroundFloor)
{
    ui->setupUi(this);
    ui->verticalLayoutWidget->hide();
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


void UndergroundFloor::on_nextButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(UserView::g_stack->currentIndex() + 1);
}


void UndergroundFloor::on_previousButton_2_clicked()
{
    QMessageBox::warning(this, "Error", "This is the last floor!");
}


void UndergroundFloor::on_backButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(0);
}


void UndergroundFloor::on_menuButton_toggled()
{
    ui->verticalLayoutWidget->show();
    ui->menuButton->hide();
}


void UndergroundFloor::on_menuButton_3_toggled()
{
    ui->verticalLayoutWidget->hide();
    ui->menuButton->show();
}


