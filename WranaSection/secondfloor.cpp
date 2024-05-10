#include "secondfloor.h"
#include "ui_secondfloor.h"
#include <QDebug>
using namespace::std;

SecondFloor::SecondFloor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecondFloor)
{
    ui->setupUi(this);
    vector<string> first(47);
    //make all empty
    for(int i = 0; i < 47; i++) for(int j = 0; j < 76; j++) first[i] += '.';
    //////////////////////////////////////insert labs
    //Back Ladder
    for(int i = 0; i < 7; i++) for(int j = 0; j < 10; j++) first[i][j] = '+';
    //Robotic Lab
    for(int i = 7; i < 27; i++) for(int j = 0; j < 14; j++) first[i][j] = '+';
    //Cis Lab 2
    for(int i = 32; i < 47; i++) for(int j = 0; j < 14; j++) first[i][j] = '+';
    //Cis Lab 2 to Head of CS
    for(int i = 36; i < 47; i++) for(int j = 0; j < 76; j++) first[i][j] = '+';
    //CS Secretary to Emergency Ladder
    for(int i = 0; i < 47; i++) for(int j = 66; j < 76; j++) first[i][j] = '+';
    //Emergency Ladder
    for(int i = 0; i < 22; i++) for(int j = 65; j < 76; j++) first[i][j] = '+';
    //Main Ladder
    for(int i = 0; i < 28; i++) for(int j = 54; j < 65; j++) first[i][j] = '+';
    //Dr.Ali to Dr.El sayed
    for(int i = 0; i < 31; i++) for(int j = 26; j < 54; j++) first[i][j] = '+';
    //network to Elevators
    for(int i = 0; i < 29; i++) for(int j = 18; j < 54; j++) first[i][j] = '+';


    vector<string> second(67);
    //make all empty
    for(int i = 0; i < 67; i++) for(int j = 0; j < 88; j++) second[i] += '.';
    //////////////////////////////////////insert labs
    //first Lab
    for(int i = 0; i < 21; i++) for(int j = 0; j < 19; j++) second[i][j] = '+';
    //second Lab
    for(int i = 21; i < 28; i++) for(int j = 0; j < 10; j++) second[i][j] = '+';
    //third and fourth Lab
    for(int i = 28; i < 67; i++) for(int j = 0; j < 19; j++) second[i][j] = '+';
    //fifth Lab
    for(int i = 51; i < 67; i++) for(int j = 19; j < 34; j++) second[i][j] = '+';
    //ladder
    for(int i = 54; i < 67; i++) for(int j = 34; j < 88; j++) second[i][j] = '+';
    //masjid and TAs Room
    for(int i = 0; i < 45; i++) for(int j = 49; j < 83; j++) second[i][j] = '+';
    //sixth lab to W.C
    for(int i = 18; i < 45; i++) for(int j = 26; j < 49; j++) second[i][j] = '+';
    //rest of building
    for(int i = 0; i < 11; i++) for(int j = 19; j < 34; j++) second[i][j] = '+';
    for(int i = 0; i < 36; i++) for(int j = 83; j < 88; j++) second[i][j] = '+';


    for(int i = 0; i < 47; i++){
        for(int j = 0; j < 76; j++) if(first[i][j] == '+'){
                ui->SecondF_widget->setItem(i, j, new QTableWidgetItem());
                ui->SecondF_widget->item(i, j)->setFlags(Qt::NoItemFlags);
            }
        // qDebug() << first[i] << '\n';
    }
    // qDebug() <<"\t--------------------Second----------------------------------\n";
    for(int i = 0; i < 67; i++){
        for(int j = 0; j < 88; j++) if(second[i][j] == '+'){
            ui->SecondF_widget_2->setItem(i, j, new QTableWidgetItem());
            ui->SecondF_widget_2->item(i, j)->setFlags(Qt::NoItemFlags);
        }
        // qDebug() << second[i] << '\n';
    }
}

SecondFloor::~SecondFloor()
{
    delete ui;
}

void SecondFloor::on_SecondF_widget_2_cellActivated(int row, int column)
{
    //ui->label_2->setText(QString::number(row) + "    " + QString::number(column));
}

void SecondFloor::on_SecondF_widget_cellActivated(int row, int column)
{
    //ui->label->setText(QString::number(row) + "    " + QString::number(column));
}


void SecondFloor::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void SecondFloor::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

