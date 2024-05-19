#include "User_View.h"
#include <iostream>
#include "ui_User_View.h"
#include "login.h"
#include "cellcourseselection.h"
#include "database.h"
using namespace std;
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

    ui->start_list_widget->hide();
    ui->end_list_widget->hide();
    RefreshTable();
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

void UserView::RefreshTable()
{
    for (int i = 0; i < 6;i++)
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


            //cout << day << ' ' << usablehour << ": " << Database::users[Database::CurrentUser].current_schedule[temptt].getName() << endl;

            if (Database::users[Database::CurrentUser].current_schedule[temptt].getName() != "None")
            {
                ui->Schedule->setItem(i,j, new QTableWidgetItem(QString::fromStdString(Database::users[Database::CurrentUser].current_schedule[temptt].getCourse() + "\n" + Database::users[Database::CurrentUser].current_schedule[temptt].getType()  + "\n" + Database::users[Database::CurrentUser].current_schedule[temptt].getName())));
                QColor color = QColor::fromRgb(229,112,30);
                ui->Schedule->item(i, j)->setBackground(color);
            }
            else
            {
                ui->Schedule->setItem(i,j,new QTableWidgetItem(QString::fromStdString("")));
                QColor color = QColor::fromRgb(28, 32, 33);
                ui->Schedule->item(i, j)->setBackground(color);
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

    CellCourseSelection CCS;
    CCS.setModal(true);
    CCS.exec();
    RefreshTable();
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

////////////////////////////////// Graph Page //////////////////////////////////

// to show rooms list
void UserView::on_search_start_selectionChanged()
{
    ui->start_list_widget->show();
}

void UserView::on_search_end_selectionChanged()
{
    ui->end_list_widget->show();
}


// filter rooms based on input
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


// get start and end rooms from what the user selected
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




