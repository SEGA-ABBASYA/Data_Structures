#include "User_View.h"
#include "ui_User_View.h"
#include "login.h"
#include <QMessageBox>

Location UserView::startRoom;
Location UserView::endRoom;
QListWidgetItem *user;
UserView::UserView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserView)
{
    ui->setupUi(this);
    ui->full->hide();
    genedyBuilding =
    {
        {"HP Lab", true},
        {"Class 4", true},
        {"CIS Lab 1", true},
        {"CIS Lab 2", true},
        {"CIS Lab 3", true},
        {"CIS Lab 4", true},
        {"CIS Lab 5", true},
        {"CIS Lab 6", true},
        {"CIS Lab 7", true},
        {"Physics Lab", true},
    };

    for (const auto& pair : db.locations) {
        roomsList.push_back(QString::fromStdString(pair.first));
    }
    for (const auto& pair : genedyBuilding) {
        roomsList.push_back(QString::fromStdString(pair.first));
    }

    ui->start_list_widget->addItems(roomsList);
    ui->end_list_widget->addItems(roomsList);
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


void UserView::on_search_start_textChanged(const QString &arg1)
{
    QRegularExpression regex(arg1, QRegularExpression::CaseInsensitiveOption);
    ui-> start_list_widget -> clear();
    ui -> start_list_widget -> addItems(roomsList.filter(regex));
}

void UserView::on_search_end_textChanged(const QString &arg1)
{
    QRegularExpression regex(arg1, QRegularExpression::CaseInsensitiveOption);
    ui-> end_list_widget -> clear();
    ui -> end_list_widget -> addItems(roomsList.filter(regex));
}

void UserView::on_start_list_widget_itemClicked(QListWidgetItem *item)
{
    string chosenRoom =item->data(Qt::DisplayRole).toString().toStdString();;

    if (db.locations.find(chosenRoom) != db.locations.end())
    {
        startRoom = db.locations[chosenRoom];
    }
    else if (genedyBuilding.find(chosenRoom) != genedyBuilding.end())
    {
        QMessageBox::warning(this, "Error", "You're in Genedy, Go to the Main Building.");
        startRoom = db.locations["Class 7"];
    }
}


void UserView::on_end_list_widget_itemClicked(QListWidgetItem *item)
{
    string chosenRoom =item->data(Qt::DisplayRole).toString().toStdString();;

    if (db.locations.find(chosenRoom) != db.locations.end())
    {
        endRoom = db.locations[chosenRoom];
    }
    else if (genedyBuilding.find(chosenRoom) != genedyBuilding.end())
    {
        QMessageBox::warning(this, "Error", "Your destination is in Genedy Building.");
        endRoom = db.locations["Class 7"];
    }
}

