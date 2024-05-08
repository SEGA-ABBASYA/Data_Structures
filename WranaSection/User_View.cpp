#include "User_View.h"
#include "ui_User_View.h"
#include "login.h"
#include <QMessageBox>
QListWidgetItem *user;
UserView::UserView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserView)
{
    ui->setupUi(this);
    ui->full->hide();

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

