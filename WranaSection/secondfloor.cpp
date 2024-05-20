#include "secondfloor.h"
#include "ui_secondfloor.h"
#include "database.h"
#include <QDebug>
#include "User_View.h"
#include <QMessageBox>
using namespace::std;

SecondFloor::SecondFloor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecondFloor)
{
    ui->setupUi(this);
    Database::second1Table  = ui->SecondF_widget;



    for(int i = 0; i < 47; i++){
        for(int j = 0; j < 76; j++) if(Database::SecondFloor[i][j] == '+'){
                ui->SecondF_widget->setItem(i, j, new QTableWidgetItem());
                ui->SecondF_widget->item(i, j)->setFlags(Qt::NoItemFlags);
            }
    }
    ui->verticalLayoutWidget->hide();
}

SecondFloor::~SecondFloor()
{
    delete ui;
}


void SecondFloor::on_SecondF_widget_cellActivated(int row, int column)
{
    cout<<row<<" "<<column<<endl;
}
void SecondFloor::on_menuButton_3_toggled()
{
    ui->verticalLayoutWidget->hide();
    ui->menuButton->show();
}


void SecondFloor::on_menuButton_toggled()
{
    ui->verticalLayoutWidget->show();
    ui->menuButton->hide();
}


void SecondFloor::on_backButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(0);
}


void SecondFloor::on_nextButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(UserView::g_stack->currentIndex() + 1);
}


void SecondFloor::on_previousButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(UserView::g_stack->currentIndex() - 1);
}


void SecondFloor::on_BackLadderBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Main Building\nBack Ladder");
}


void SecondFloor::on_RoboticsLabBtn_clicked()
{
     QMessageBox::information(this, "Room Name", "Robotics Lab");
}


void SecondFloor::on_SecondEntrance_clicked()
{
    QMessageBox::information(this, "Room Name", "Second Building Entrance");
}


void SecondFloor::on_CisLab2Btn_2_clicked()
{
    on_CisLab2Btn_clicked();
}


void SecondFloor::on_CisLab2Btn_clicked()
{
    QMessageBox::information(this, "Room Name", "CIS Lab 2");
}


void SecondFloor::on_ISdepartBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Eman Shaban's Office Head of the IS Department");
}


void SecondFloor::on_ISLabBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "IS Lab");
}


void SecondFloor::on_SCLabBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "SC Lab");
}


void SecondFloor::on_CSDepBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr Abir Mahmoud\nHead of the CS department");
}


void SecondFloor::on_CsSecertaryBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "CS Secretary");
}


void SecondFloor::on_CentralControlBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Central Control");
}


void SecondFloor::on_WC_clicked()
{
    QMessageBox::information(this, "Room Name", "W.C 🙍🏻‍♀️");
}


void SecondFloor::on_WC_2_clicked()
{
    QMessageBox::information(this, "Room Name", "W.C 🙍🏻‍♂️");
}


void SecondFloor::on_EmergencyBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Emergency Ladder");
}


void SecondFloor::on_MainLadderBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Main Building Ladder");
}


void SecondFloor::on_DrAliBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr Ali ElNaa'm\nDr Ahmed Hamed\nDr Saied Ghoniemy\nDr Mohamed Roshdy");
}


void SecondFloor::on_SalamOfficeBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr AbdElBadyea/nSalam's Office");
}


void SecondFloor::on_ZakyOfficeBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Dr Zaky Taha\nDr Taha El Areef\nOffice");
}


void SecondFloor::on_ElSayedOfficeBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "ElSayed Mohamed\nTaimor Nazmy\nOffice");
}


void SecondFloor::on_NetwrokBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Netwrok");
}


void SecondFloor::on_StorageBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Storage");
}


void SecondFloor::on_StorageBtn_2_clicked()
{
    on_StorageBtn_clicked();
}


void SecondFloor::on_ArefOfficeBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Mustafa Mohamed\nAref's Office");
}


void SecondFloor::on_ElevatorBtn_clicked()
{
    QMessageBox::information(this, "Room Name", "Elevators");
}

