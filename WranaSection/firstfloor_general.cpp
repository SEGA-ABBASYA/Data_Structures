#include "firstfloor_general.h"
#include "ui_firstfloor_general.h"
#include <iostream>
using namespace std;

Firstfloor_general::Firstfloor_general(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Firstfloor_general)
{
    ui->setupUi(this);

    for(int i =0;i<(41);i++)
    {
        ui->tableWidget->setColumnWidth(i,30);
    }
    for (int i=0;i<(30);i++)
    {
        ui->tableWidget->setRowHeight(i, 20);

    }
    vector<string>c;
    c=write_Graph_general();

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

Firstfloor_general::~Firstfloor_general()
{
    delete ui;
}

void Firstfloor_general::on_tableWidget_cellActivated(int row, int column)
{
    string r = to_string (row);
    string c = to_string(column) ;
    QString s = QString:: fromStdString(r + " " + c) ;
   //ui->label_2->setText(s);
    cout<<row<<" "<<column<<endl;
}
vector<string> Firstfloor_general::write_Graph_general()
{
    vector<string>c; //47 rows -> 46 // 76 columns
    // Main Building Ladder Column 74 Row 20
    //    Back Ladder (Electronics) Column 36 Row 6
    // col 41 row 30

        // ML

     c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxB.....xxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxB.....xxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxB.....xxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxx....xxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxx.xxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxx.xxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxx.xxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxx.xxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxx.xxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxx.xxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxx.xxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxxxxxxx.xxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxxMMxxxx.xxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxx..xxxx.xxxx");
     c.push_back("xxxxxxxx..xxxxxxxxxxxxxxxxxxxx.......xxxx");
     c.push_back("xxxxxxxx......xxxxxxxxxxxxxxxx.......xxxx");
     c.push_back("xxxxxxxx.............................xxxx");
     c.push_back("xxxxxxxx.............................xxxx");
     c.push_back("xxxxxxxx.............................xxxx");
     c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
     c.push_back("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");




     return c;

}
