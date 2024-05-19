#include "ThirdFloor.h"
#include "ui_ThirdFloor.h"
#include "database.h"
#include "User_View.h"
#include <QMessageBox>
ThirdFloor::ThirdFloor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ThirdFloor)
{
    ui->setupUi(this);
    Database::thirdFloorTable = ui->tableWidget;
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

    ui->widget->hide();

}


void ThirdFloor::on_tableWidget_cellActivated(int row, int column)
{
    string r = to_string(row);
    string c = to_string(column);
    QString s = QString::fromStdString(r +" "+ c);
}

ThirdFloor::~ThirdFloor()
{
    delete ui;
}




void ThirdFloor::on_menuButton_toggled()
{
    ui->widget->show();
}


void ThirdFloor::on_menuButton_3_toggled()
{
    ui->widget->hide();
}


void ThirdFloor::on_nextButton_2_clicked()
{
    QMessageBox::warning(this, "Error", "This is the last floor!");
}


void ThirdFloor::on_previousButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(UserView::g_stack->currentIndex() - 1);
}


void ThirdFloor::on_backButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(0);
}

