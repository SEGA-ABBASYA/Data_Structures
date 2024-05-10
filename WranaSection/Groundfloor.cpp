#include "Groundfloor.h"
#include "ui_Groundfloor.h"
#include <QStandardItem>
#include <iostream>
using namespace std;
GroundFloor::GroundFloor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GroundFloor)
{
    ui->setupUi(this);
    for(int i =0;i<ui->tableWidget->columnCount();i++)
    {
        ui->tableWidget->setColumnWidth(i,17);
    }
    for (int i=0;i<ui->tableWidget->rowCount();i++)
    {
        ui->tableWidget->setRowHeight(i, 20);
    }
    vector<string> test = createGrid();
    for(int i = 0; i < ui->tableWidget->rowCount(); ++i) {

        for(int j = 0; j < ui->tableWidget->columnCount(); ++j) {

            auto item = ui->tableWidget->item(i, j);
            if(!item)
            { // make sure there's an item in that cell
                item= new QTableWidgetItem();
                ui->tableWidget->setItem(i, j, item);
            }
            string row = test[i];
            if(row[j] != '.')
            {
                item->setFlags(item->flags() & !~Qt::ItemIsSelectable);
            }

        }
    }
}

vector<string> GroundFloor::createGrid(){
    vector<string> groundFloor;
    groundFloor.push_back("********..C*************B.........*****************************************");
    groundFloor.push_back("********..C*************B.........*****************************************");
    groundFloor.push_back("********..C*************B.........*****************************************");
    groundFloor.push_back("********..C*************B.........*****************************************");
    groundFloor.push_back("********..C*************B.........*****************************************");
    groundFloor.push_back("********..******************...********************************************");
    groundFloor.push_back("********..******************...********************************************");
    groundFloor.push_back("********..******************...***********************************.********");
    groundFloor.push_back("********..******************...***********************************.********");
    groundFloor.push_back("********....****************...***********************************.********");
    groundFloor.push_back("********....****************...***********************************.********");
    groundFloor.push_back("********..******************...***********************************.********");
    groundFloor.push_back("********..******************...***********************************.********");
    groundFloor.push_back("********..******************...***********************************.********");
    groundFloor.push_back("********..******************...***********************************.********");
    groundFloor.push_back("********.......*************...***************************MMMMMMM*.********");
    groundFloor.push_back("********.......*************...***************************.......*.********");
    groundFloor.push_back("********.......*************...***************************.......*.********");
    groundFloor.push_back("**.............*************...***************************.......*.********");
    groundFloor.push_back("**.............*************...***************************.......*.********");
    groundFloor.push_back("**........................**...***************************.......*.********");
    groundFloor.push_back("**........................**...***************************.......*.********");
    groundFloor.push_back("**...................................*********************.......*.********");
    groundFloor.push_back("**........................**.........*********************.......*.********");
    groundFloor.push_back("****************************.......................................********");
    groundFloor.push_back("****************************.....................................**********");
    groundFloor.push_back("****************************.....................................**********");
    groundFloor.push_back("**********************************************************........*********");
    groundFloor.push_back("**********************************************************........*********");
    groundFloor.push_back("*************************************************************....**********");
    groundFloor.push_back("*************************************************************....**********");
    groundFloor.push_back("*************************************************************....**********");
    groundFloor.push_back("*************************************************************....**********");
    groundFloor.push_back("***************************************************************************");
    groundFloor.push_back("***************************************************************************");
    groundFloor.push_back("***************************************************************************");
    return groundFloor;
}

GroundFloor::~GroundFloor()
{
    delete ui;
}

void GroundFloor::on_tableWidget_cellClicked(int row, int column)
{
    cout<<row<<" "<<column<<endl;
}

