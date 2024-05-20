#include "User_View.h"
#include <iostream>
#include "ui_User_View.h"
#include "login.h"
#include "cellcourseselection.h"
#include "database.h"
using namespace std;
#include "Buildingchoose.h"
#include <QMessageBox>

Location UserView::startRoom;
Location UserView::endRoom;
#include "database.h"
#include "Navigation.h"
QStackedWidget* UserView::g_stack = nullptr;
QListWidgetItem *user;
UserView::UserView(QWidget *parent)
    : QWidget(parent), statusBar(new QStatusBar(this))
    , ui(new Ui::UserView)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(statusBar);
    statusBar->showMessage("Ready for the Sugar Cane");
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
    for(auto &course:Database::courses)
    {
        ui->ALL_courses_list->addItem(QString::fromStdString(course.first));

    }

    User &current_user=Database::users["hano4"];


    for(auto &registered_course:current_user.registered_courses)
    {
        ui->Registerd_courses->addItem(QString::fromStdString(registered_course));

    }

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
    g_stack = ui->centralStackedWidget;
}

UserView::~UserView()
{
    delete Database::underGroundFloorTable;
    delete Database::firstCreditTable;
    delete Database::firstGeneralTable;
    delete Database::groundFloorTable;
    delete Database::second1Table;
    delete Database::second2Table;
    delete Database::thirdFloorTable;
    delete g_stack;
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

void UserView::on_add_button_clicked()
{
    string course_name= ui->ALL_courses_list->currentItem()->text().toStdString();
    ui->Registerd_courses->clear();

    User &current_user=Database::users["hano4"];


         current_user.registered_courses.insert(course_name);

        for(auto &registered_course:current_user.registered_courses)
        {
                ui->Registerd_courses->addItem(QString::fromStdString(registered_course));

        }

        current_user.lecture[course_name]=false;
        bool hasLab=Database::courses[course_name].getLab(),hasSection=Database::courses[course_name].getSection();
        if(hasLab)
        {
            current_user.lab[course_name]=false;
        }
        if(hasSection)
        {
            current_user.tutorial[course_name]=false;
        }




}


void UserView::on_delete_button_clicked()
{
   // qDebug()<<"Button clicked";
    QListWidgetItem *currentItem = ui->Registerd_courses->currentItem();

    if (currentItem)
    {

        string course_name=currentItem->text().toStdString();
        User &current_user=Database::users["hano4"];

        current_user.registered_courses.erase(course_name);
        current_user.lecture.erase(course_name);

        auto end_of_labs=current_user.lab.end(),end_of_tutorials=current_user.tutorial.end();

        if(current_user.lab.find(course_name)!= end_of_labs)

        {
            current_user.lab.erase(course_name);
        }
        if(current_user.tutorial.find(course_name)!=end_of_tutorials)
        {
            current_user.tutorial.erase(course_name);
        }

        delete ui->Registerd_courses->takeItem(ui->Registerd_courses->row(currentItem));

    }


}




void UserView::on_text_filter_textChanged(const QString &arg1)
{

    for (int i = 0; i < ui->ALL_courses_list->count(); ++i) {
        QListWidgetItem *item = ui->ALL_courses_list->item(i);
        item->setHidden(!item->text().contains(arg1, Qt::CaseInsensitive));
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

void UserView::on_pushButton_4_clicked()
{
    Navigation *navigator = new Navigation(nullptr);
    navigator->show();
}

void UserView::on_text_filter_2_textChanged(const QString &arg1)
{
    for (int i = 0; i < ui->Registerd_courses->count(); ++i) {
        QListWidgetItem *item = ui->Registerd_courses->item(i);
        item->setHidden(!item->text().contains(arg1, Qt::CaseInsensitive));
    }
}

