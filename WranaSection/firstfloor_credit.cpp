#include "firstfloor_credit.h"
#include "ui_firstfloor_credit.h"
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

    vector<string>c;
    c=write_Graph_credit();

    for(int i = 0; i < ui->tableWidget->rowCount(); ++i) {

        for(int j = 0; j < ui->tableWidget->columnCount(); ++j) {

            auto item = ui->tableWidget->item(i, j);
            if(!item) { // make sure there's an item in that cell
                item= new QTableWidgetItem();
                ui->tableWidget->setItem(i, j, item);
            }
            if(c[i][j]!='.')
                item->setFlags(item->flags() & !~Qt::ItemIsSelectable);

        }
    }

}

firstfloor_credit::~firstfloor_credit()
{
    delete ui;
}

 vector<string> firstfloor_credit::write_Graph_credit()
{
      vector<string>c;

      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...............Lxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...............Lxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...............Lxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx...........xxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx..............xxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx..............xxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx..............xxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx..............xxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx..............xxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx..............xxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx..............xxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxx..............xxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
      c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");




      return c;


}

void firstfloor_credit::on_tableWidget_cellActivated(int row, int column)
{
    string r = to_string (row);
    string c = to_string(column);
    QString s = QString::fromStdString(r + " " + c) ;
    //ui->label_2->setText(s) ;
    cout<<row<<" "<<column<<endl;
}






void firstfloor_credit::on_class1_clicked()
{
    QMessageBox::information(this,"Room Name","Class 1                   ");
}


void firstfloor_credit::on_class2_1_clicked()
{
     QMessageBox::information(this,"Room Name","Class 2                  ");
}




void firstfloor_credit::on_class3_clicked()
{
     QMessageBox::information(this,"Room Name","Class 3                  ");
}




void firstfloor_credit::on_programs_office_clicked()
{
    QMessageBox::information(this,"Room Name","Programs Management Office");
}




void firstfloor_credit::on_WCgirls_clicked()
{
    QMessageBox::information(this,"Room Name","W.C For Women               ");
}


void firstfloor_credit::on_ProgramDirector_clicked()
{
     QMessageBox::information(this,"Room Name","Program Director : Dr sherine Rady");
}


void firstfloor_credit::on_MultiMedia_Bioinformatics_clicked()
{
     QMessageBox::information(this,"Room Name","AI coordinator,Multimedia coordinator,Bioinformatics coordinator : Dr Mariam Nabil ,Dr Dina el sayad ");
}

