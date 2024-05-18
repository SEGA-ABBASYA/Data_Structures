#include "User_View.h"
#include "ui_User_View.h"
#include "login.h"
#include "Buildingchoose.h"
#include <QMessageBox>
QStackedWidget* UserView::g_stack = nullptr;
QListWidgetItem *user;
UserView::UserView(QWidget *parent)
    : QWidget(parent), statusBar(new QStatusBar(this))
    , ui(new Ui::UserView)
{
    ui->setupUi(this);
    ui->verticalLayout_2->addWidget(statusBar);
    statusBar->showMessage("Ready for the Mango");
    u = new UndergroundFloor();
    g = new GroundFloor();
    f = new Firstfloor_general();
    c = new firstfloor_credit();
    o = new SecondFloorOther();
    s = new SecondFloor();
    t = new ThirdFloor();
    ui->centralStackedWidget->addWidget(u);//1 underground
    ui->centralStackedWidget->addWidget(g);//2 ground
    ui->centralStackedWidget->addWidget(f);//3 first general
    ui->centralStackedWidget->addWidget(c);//4 first credit
    ui->centralStackedWidget->addWidget(s);//5 second
    ui->centralStackedWidget->addWidget(o);//6 second other
    ui->centralStackedWidget->addWidget(t);//7 third
    ui->full->hide();
    g_stack = ui->centralStackedWidget;
}

UserView::~UserView()
{
    delete ui;
}

void UserView::on_Swapfull_toggled()
{
    ui->icons->show();
    ui->full->hide();

}


void UserView::on_Swapicons_toggled()
{
    ui->icons->hide();
    ui->full->show();
}


void UserView::on_courseicons_toggled(bool checked)
{
    ui->stackedWidgetNew->setCurrentIndex(1);
}


void UserView::on_graphicons_toggled(bool checked)
{
    ui->stackedWidgetNew->setCurrentIndex(0);
}


void UserView::on_studenticons_toggled(bool checked)
{
    ui->stackedWidgetNew->setCurrentIndex(2);
}


void UserView::on_scheduleicons_toggled(bool checked)
{
    ui->stackedWidgetNew->setCurrentIndex(3);
}


void UserView::on_friendicons_toggled(bool checked)
{
    ui->stackedWidgetNew->setCurrentIndex(4);
}


void UserView::on_notificationicons_toggled(bool checked)
{
    ui->stackedWidgetNew->setCurrentIndex(5);
}


void UserView::on_pushButton_toggled(bool checked)
{
    ui->stackedWidgetFriends->setCurrentIndex(0);
}


void UserView::on_pushButton_2_toggled(bool checked)
{
    ui->stackedWidgetFriends->setCurrentIndex(1);
    ui->stackedWidget_chat->setCurrentIndex(0);
}



void UserView::on_logouticons_clicked()
{
    Login::w_stack->setCurrentIndex(0);
}


void UserView::on_logoutfull_clicked()
{
    Login::w_stack->setCurrentIndex(0);
}

void UserView::on_listWidget_itemPressed(QListWidgetItem *item)
{
    user = item;
}

void UserView::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QMessageBox::information(this, "Your Friend ", item->text() + " Have section in IS");
}


void UserView::on_DM_clicked()
{
    if(user)
    {
        //ui->label_25->setText(user->text());
        ui->stackedWidgetFriends->setCurrentIndex(1);
        ui->stackedWidget_chat->setCurrentIndex(1);
    }
    else
        QMessageBox::warning(this, "Error", "Please select a user");
}


void UserView::on_underground_start_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(1);
}


void UserView::on_ground_start_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(2);
}


void UserView::on_first_start_clicked()
{
    BuildingChoose choice;
    choice.setModal(true);
    choice.exec();
    if (BuildingChoose::right)
        ui->centralStackedWidget->setCurrentIndex(3);
    else if (BuildingChoose::left)
        ui->centralStackedWidget->setCurrentIndex(4);
    else
        QMessageBox::warning(this, "Error", "Please Select a half!");
}


void UserView::on_third_start_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(7);
}


void UserView::on_second_start_clicked()
{
    BuildingChoose choice;
    choice.setModal(true);
    choice.exec();
    if (BuildingChoose::right)
        ui->centralStackedWidget->setCurrentIndex(5);
    else if (BuildingChoose::left)
        ui->centralStackedWidget->setCurrentIndex(6);
    else
        QMessageBox::warning(this, "Error", "Please Select a half!");
}

void UserView::on_underground_end_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(1);
}


void UserView::on_ground_end_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(2);
}


void UserView::on_first_end_clicked()
{
    BuildingChoose choice;
    choice.setModal(true);
    choice.exec();
    if (BuildingChoose::right)
        ui->centralStackedWidget->setCurrentIndex(3);
    else if (BuildingChoose::left)
        ui->centralStackedWidget->setCurrentIndex(4);
    else
        QMessageBox::warning(this, "Error", "Please Select a half!");
}


void UserView::on_third_end_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(7);
}


void UserView::on_second_end_clicked()
{
    BuildingChoose choice;
    choice.setModal(true);
    choice.exec();
    if (BuildingChoose::right)
        ui->centralStackedWidget->setCurrentIndex(5);
    else if (BuildingChoose::left)
        ui->centralStackedWidget->setCurrentIndex(6);
    else
        QMessageBox::warning(this, "Error", "Please Select a half!");
}
