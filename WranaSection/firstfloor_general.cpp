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

void Firstfloor_general::on_ConferenceHall_clicked()
{
     QMessageBox::information(this,"Room Name","Conference Hall                 ");
}


void Firstfloor_general::on_SecretaryOffice_clicked()
{
     QMessageBox::information(this,"Room Name","College Secretary Office        ");
}


void Firstfloor_general::on_SeminarHall_clicked()
{
     QMessageBox::information(this,"Room Name","Seminar Hall                    ");
}


void Firstfloor_general::on_QualityOffice_clicked()
{
      QMessageBox::information(this,"Room Name","Quality Sssurance Office       ");
}


void Firstfloor_general::on_SecretaryQuality_clicked()
{
    QMessageBox::information(this,"Room Name","Secretary Of Quality Assurance   ");
}


void Firstfloor_general::on_PostgraduateHALL_clicked()
{
     QMessageBox::information(this,"Room Name","Postgraduate Teaching Hall      ");
}


void Firstfloor_general::on_WC_W_clicked()
{
     QMessageBox::information(this,"Room Name","W.C For Women                  ");
}


void Firstfloor_general::on_WC_M_clicked()
{
    QMessageBox::information(this,"Room Name","W.C For Men                     ");
}


void Firstfloor_general::on_ResearchLaboratory_clicked()
{
     QMessageBox::information(this,"Room Name","Research Laboratory            ");
}


void Firstfloor_general::on_SecrataryForGraduate_clicked()
{
     QMessageBox::information(this,"Room Name","Secratary of the College Vice Dean for Graduate Studies Office");
}


void Firstfloor_general::on_OfficeForGraduate_clicked()
{
    QMessageBox::information(this,"Room Name","Office of the College Vice Dean for Graduate Studies");
}


void Firstfloor_general::on_TechnicallOffice_clicked()
{
     QMessageBox::information(this,"Room Name","Secretary of collage secretary office / Technical Office of the College Dean");
}


void Firstfloor_general::on_AffairsOffice_clicked()
{
    QMessageBox::information(this,"Room Name","Community and Environmental Affairs Secretary Office");
}


void Firstfloor_general::on_WC_clicked()
{
    QMessageBox::information(this,"Room Name","W.C For Women                          ");
}


void Firstfloor_general::on_Buffet_clicked()
{
    QMessageBox::information(this,"Room Name","Buffet                          ");
}


void Firstfloor_general::on_Elevators_clicked()
{
    QMessageBox::information(this,"Room Name","Elevators                        ");
}


void Firstfloor_general::on_DR_HalaMoshir_clicked()
{
    QMessageBox::information(this,"Room Name","DR Hala Moshir Office of the College Vice Dean for Education and Student Affairs");
}


void Firstfloor_general::on_DR_TamerMustafa_clicked()
{
QMessageBox::information(this,"Room Name"," Dr Tamer Mustafa's Office College Vice Dean for Community and Environmental Affairs");

}


void Firstfloor_general::on_CollageSecretary_clicked()
{
    QMessageBox::information(this,"Room Name","Collage Dean Secretary Office            ");

}


void Firstfloor_general::on_CollageOffice_clicked()
{
     QMessageBox::information(this,"Room Name","Collage Dean's Office                  ");

}


void Firstfloor_general::on_MainLadder_clicked()
{
    QMessageBox::information(this,"Room Name","Main Building Ladder                ");
}


void Firstfloor_general::on_EmergencyLadder_clicked()
{
    QMessageBox::information(this,"Room Name","Emergency Ladder                    ");
}


void Firstfloor_general::on_BackLadder_clicked()
{
    QMessageBox::information(this,"Room Name","Main Building Back Ladder              ");
}

