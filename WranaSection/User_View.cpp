#include "User_View.h"
#include <iostream>
#include "ui_User_View.h"
#include "login.h"
#include "cellcourseselection.h"
#include "database.h"
using namespace std;
#include <QMessageBox>
QListWidgetItem *user;
UserView::UserView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserView)
{
    ui->setupUi(this);
    ui->full->hide();

    //RefreshTable();
}

UserView::~UserView()
{
    Database::users[Database::CurrentUser.getUsername()] = Database::CurrentUser;
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
    Database::users[Database::CurrentUser.getUsername()] = Database::CurrentUser;
    Login::w_stack->setCurrentIndex(0);
}

void UserView::RefreshTable()
{
    for (int i = 0; i < 7;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            string hour = ui->Schedule->horizontalHeaderItem(j)->text().toStdString();
            string day = ui->Schedule->verticalHeaderItem(i)->text().toStdString();
            int usablehour;
            if (hour[0] == '1')
            {
                usablehour = stoi(hour.substr(0,2));
            }
            else
                usablehour = stoi(hour.substr(0,1));

            Timetable temptt;
            temptt.day = day;
            temptt.hour = usablehour;
            temptt.minutes = 0;

            ui->Schedule->item(i,j)->text() = QString::fromStdString( Database::CurrentUser.current_schedule[temptt].getName());
            if(Database::CurrentUser.current_schedule[temptt].getName() != "None")
            {
                QColor color = QColor::fromRgb(229,112,30);
                ui->Schedule->item(i,j)->background().setColor(color);
            }
        }
    }
}

void UserView::on_Schedule_cellDoubleClicked(int row, int column)
{
    string hour = ui->Schedule->horizontalHeaderItem(column)->text().toStdString();
    string day = ui->Schedule->verticalHeaderItem(row)->text().toStdString();
    int usablehour;
    if (hour[0] == '1')
    {
        usablehour = stoi(hour.substr(0,2));
    }
    else
        usablehour = stoi(hour.substr(0,1));

    Database::CurrentUserTT.hour = usablehour;
    Database::CurrentUserTT.day = day;
    Database::CurrentUserTT.minutes = 0;
    //if (Database::CurrentUser.current_schedule[Database::CurrentUserTT].getName() != "None")
    //{
        //QColor color = QColor::fromRgb(229,112,30);
        //ui->Schedule->item(row,column)->background().setColor(color);
    //}
    //ui->Schedule->item(row,column)->text() = QString::fromStdString(Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse());
    CellCourseSelection CCS;
    CCS.setModal(true);
    CCS.exec();
    //RefreshTable();
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

