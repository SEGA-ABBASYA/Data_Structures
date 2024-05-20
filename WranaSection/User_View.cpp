#include "User_View.h"
#include <iostream>
#include "qdatetime.h"
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
#include <user.h>
#include <QMap>
#include <map>
#include <vector>
#include <regex>
#include <QListWidgetItem>
#include <QListWidget>
#include <database.h>
#include <ChatWindow.h>
#include <QTimer>
#include "QString"
QListWidgetItem *user;
string Login::USERNAME;


UserView::UserView(QWidget *parent)
    : QWidget(parent), statusBar(new QStatusBar(this))
    , ui(new Ui::UserView)
{
    ui->setupUi(this);
    //GUI Modifications
    ui->verticalLayout->addWidget(statusBar);
    ui->full->hide();
    //statusBar->showMessage("Welcome Back " +  QString::fromStdString(USERNAME));

    //Graph UIs
    u = new UndergroundFloor();
    g = new GroundFloor();
    f = new Firstfloor_general();
    c = new firstfloor_credit();
    o = new SecondFloorOther();
    s = new SecondFloor();
    t = new ThirdFloor();
    ui->centralStackedWidget->addWidget(u);//1 underground
    ui->centralStackedWidget->addWidget(g);//2 ground
    ui->centralStackedWidget->addWidget(c);//3 first credit
    ui->centralStackedWidget->addWidget(f);//4 first general
    ui->centralStackedWidget->addWidget(o);//5 second other
    ui->centralStackedWidget->addWidget(s);//6 second
    ui->centralStackedWidget->addWidget(t);//7 third
    g_stack = ui->centralStackedWidget;

    //Courses lists
    for(auto &course:Database::courses)
    {
        ui->ALL_courses_list->addItem(QString::fromStdString(course.first));

    }
    User &current_user=Database::users[Database::CurrentUser];

    for(auto &registered_course:current_user.registered_courses)
    {
        ui->Registerd_courses->addItem(QString::fromStdString(registered_course));

    }


    //Location Search
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

    //For Schedule
    RefreshTable();

    //For Notifications
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &UserView::refreshNotifications);
    timer->start(1000);
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


Timetable UserView::getrealtime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();

    QString day = currentDateTime.toString("dddd");
    int hour = currentDateTime.time().hour();

    if (hour == 1)
    {
        hour = 12;
    }
    else if (hour % 2 != 0) {
        hour--;
    }

    Timetable tt;
    tt.day = day.toStdString();
    tt.hour = hour;
    tt.minutes = 0;
    return tt;
}

////////////////////////////////////////////////////Panells////////////////////////////////////////////
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
    showData();
    ui->stackedWidgetNew->setCurrentIndex(2);
}


void UserView::on_scheduleicons_toggled(bool checked)
{
    ui->stackedWidgetNew->setCurrentIndex(3);
}

void UserView::on_friendicons_toggled(bool checked)
{
    updateFriendsList();
    ui->stackedWidgetNew->setCurrentIndex(4);
}

void UserView::on_notificationicons_toggled(bool checked)
{
    ui->stackedWidgetNew->setCurrentIndex(5);
}


void UserView::on_logouticons_clicked()
{
    Login::w_stack->setCurrentIndex(0);
}

void UserView::on_logoutfull_clicked()
{
    Login::w_stack->setCurrentIndex(0);
}


////////////////////////////////////////////////Schedule//////////////////////////////////////////
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


////////////////////////////////////////////// Graph Page //////////////////////////////////////////

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
        start = true;
        startRoom = db.locations[chosenRoom];
        statusBar->showMessage("You Have Selected " + QString::fromStdString(chosenRoom) + " As Your Starting Point");
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
        end = true;
        endRoom = db.locations[chosenRoom];
        statusBar->showMessage("You Have Selected " + QString::fromStdString(chosenRoom) + " As Your Destination");
    }
    else if (genedyBuilding.find(chosenRoom) != genedyBuilding.end())
    {
        QMessageBox::warning(this, "Error", "Your destination is in Genedy Building.");
        endRoom = db.locations["Class 7"];
    }
}

///////////////////////////////////////////Course//////////////////////////////////////////
void UserView::on_add_button_clicked()
{
    string course_name= ui->ALL_courses_list->currentItem()->text().toStdString();
    ui->Registerd_courses->clear();

    User &current_user=Database::users[Database::CurrentUser];


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
    QListWidgetItem *currentItem = ui->Registerd_courses->currentItem();

    if (currentItem)
    {

        string course_name=currentItem->text().toStdString();
        User &current_user=Database::users[Database::CurrentUser];

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


///////////////////////////////////Navigation////////////////////////////////
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
        ui->centralStackedWidget->setCurrentIndex(4);
    else if (BuildingChoose::left)
        ui->centralStackedWidget->setCurrentIndex(3);
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
        ui->centralStackedWidget->setCurrentIndex(6);
    else if (BuildingChoose::left)
        ui->centralStackedWidget->setCurrentIndex(5);
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
    if (start && end){
    Navigation *navigator = new Navigation(nullptr);
        navigator->show();
    }
    else if (!start)
        QMessageBox::warning(this, "Error", "Please Select a start point!");
    else
        QMessageBox::warning(this, "Error", "Please Select the ending point!");
}

void UserView::on_text_filter_2_textChanged(const QString &arg1)
{
    for (int i = 0; i < ui->Registerd_courses->count(); ++i) {
        QListWidgetItem *item = ui->Registerd_courses->item(i);
        item->setHidden(!item->text().contains(arg1, Qt::CaseInsensitive));
    }
}
void UserView::on_searchEdit_textChanged(const QString &arg1)
{
    search(arg1);
}



////////////////////// friends and chat things///////////////////////////////////
QMap<string,User>& usersMap = Database::users;

void UserView::search(const QString& text)
{
    ui->resultsList->clear();
    QString searchText = text.toLower();
    for (auto it = Database::users.begin(); it !=Database::users.end(); ++it)
    {
        QString key = QString::fromStdString(it.key());
        if (key.contains(searchText, Qt::CaseInsensitive))
        {
            ui->resultsList->addItem(key);
        }
    }
}

void UserView::updateFriendsList(){
    ui->friendsList->clear();
    auto it = Database::users.find(Login::USERNAME);
    if (it != Database::users.end()) {
        User& currentUser = it.value();
        for (const auto& friendPair : currentUser.friends) {
            ui->friendsList->addItem(QString::fromStdString(friendPair.first));
        }
    }
}


void UserView::addFriend(QListWidgetItem *item){
    QString userName = item->text();
    auto it = Database::users.find(userName.toStdString());
    if (it != Database::users.end()) {
        User &selectedUser = it.value();
        auto currentUserIt = Database::users.find(Login::USERNAME);
        if (currentUserIt != Database::users.end()) {
            User &currentUser = currentUserIt.value();
            currentUser.add_friend(&selectedUser);
            updateFriendsList();
        }
    }
}

void UserView::on_resultsList_itemClicked(QListWidgetItem *item)
{
    addFriend(item);
}

void UserView::removeFriend() {

    QListWidgetItem *item = ui->friendsList->currentItem();
    if (item) {
        QString friendName = item->text();
        std::string friendNameStr = friendName.toStdString();
        auto currentUserIt = Database::users.find(Login::USERNAME);
        if (currentUserIt != Database::users.end()) {
            User &currentUser = currentUserIt.value();
            if (currentUser.friends.find(friendNameStr) != currentUser.friends.end()) {
                currentUser.remove_friend(friendNameStr);
                updateFriendsList();
            }
        }
    }

}

void UserView::on_removeButton_clicked()
{
    removeFriend();
}

void UserView::openChat(){
    QListWidgetItem *item = ui->friendsList->currentItem();
    if(item){
        QString friendName = item->text();
        auto it = Database::users.find(friendName.toStdString());
        if(it != Database::users.end()){
            ChatWindow *chatWindow = new ChatWindow(Database::users[Login::USERNAME],it.value());
            chatWindow->show();
        }
    }else{
        QMessageBox::warning(this, "Error", "Please select a friend to chat with.");
    }

}

//Notifications
    void UserView::updateNotifications(){
    ui->notificationList->clear();

    auto it = Database::users.find(Login::USERNAME);
    if (it != Database::users.end()) {
        User& currentUser = it.value();
        QStringList notifications = currentUser.getNotifications();
        for (const QString& notification : notifications) {
            ui->notificationList->addItem(notification);
        }
    }
}

void UserView::refreshNotifications() {
    updateNotifications();
}

//Clear Notification
void UserView::on_DM_3_clicked()
{
    auto it = Database::users.find(Login::USERNAME);
    if (it != Database::users.end()) {
        User& currentUser = it.value();
        currentUser.clearNotifications();
        updateNotifications();
    }
}


//Remove Notification
void UserView::on_DM_4_clicked()
{
    QListWidgetItem *item = ui->notificationList->currentItem();
    if (item) {
        QString notification = item->text();
        auto it = Database::users.find(Login::USERNAME);
        if (it != Database::users.end()) {
            User& currentUser = it.value();
            currentUser.removeNotification(notification);
            updateNotifications();
        }
    }
}

void UserView::on_directMessageButton_clicked()
{
    openChat();
}


///////////////////////////////////Student Info//////////////////////////////////
void UserView::showData(){
    ui->nameedit->setText(QString::fromStdString(Database::users[Login::USERNAME].getName()));
    ui->emailedit->setText(QString::fromStdString(Database::users[Login::USERNAME].getEmail()));
    ui->usernameedit->setText(QString::fromStdString(Database::users[Login::USERNAME].getUsername()));
    ui->passwordedit->setText(QString::fromStdString(Database::users[Login::USERNAME].getPassword()));
    ui->idedit->setText(QString::number(Database::users[Login::USERNAME].getId()));
    ui->yearSpinBox->setValue(Database::users[Login::USERNAME].getAcademicYear());
    ui->sectionSpinBox->setValue(Database::users[Login::USERNAME].getSection());
    if(Database::users[Login::USERNAME].getGender() == 'F'){
        ui->male->setChecked(0);
        ui->female->setChecked(1);
    }else{
        ui->male->setChecked(1);
        ui->female->setChecked(0);
    }
}

void UserView::updateUserDetails(const std::string &oldUsername, const std::string &newName, const std::string &newEmail, int newId, int newAcademicYear, int newSection, const std::string &newUsername, const std::string &newPassword, const std::string &newProgram, char newGender)
{
    auto it = Database::users.find(oldUsername);
    if (it == Database::users.end()) {
        QMessageBox::warning(this, "Error", "User not found");
        return;
    }

    User user = it.value();
    if (oldUsername != newUsername) {
        if (Database::users.contains(newUsername)) {
            QMessageBox::warning(this, "Error", "Username already exists");
            return;
        }
        Database::users.remove(oldUsername);
        user.updateDetails(newName, newEmail, newId, newAcademicYear, newSection, newUsername, newPassword, newProgram, newGender);
        Database::users.insert(newUsername, user);
    } else {
        user.updateDetails(newName, newEmail, newId, newAcademicYear, newSection, newUsername, newPassword, newProgram, newGender);
        Database::users[oldUsername] = user;
    }
}

void UserView::on_editUserButton_clicked()
{
    QString newName = ui->nameedit->text();
    QString newEmail = ui->emailedit->text();
    QString newUsername = ui->usernameedit->text();
    QString newPassword = ui->passwordedit->text();
    int newId = ui->idedit->text().toInt();
    int newAcademicYear = ui->yearSpinBox->value();
    int newSection = ui->sectionSpinBox->value();
    QString newProgram = "";
    char newGender = ui->male->isChecked() ? 'M' : 'F';

    updateUserDetails(Login::USERNAME, newName.toStdString(), newEmail.toStdString(), newId, newAcademicYear, newSection, newUsername.toStdString(), newPassword.toStdString(), newProgram.toStdString(), newGender);

    if (Login::USERNAME != newUsername.toStdString()) {
        Login::USERNAME = newUsername.toStdString();
    }

    QMessageBox::information(this, "Success", "User details updated successfully");
    showData();
}



void UserView::on_friendsList_itemDoubleClicked(QListWidgetItem *item)
{
    Timetable realtt = getrealtime();
    cout << realtt.day << ' ' << realtt.hour << endl;
    Schedule temp = Database::users[item->text().toStdString()].current_schedule[realtt];
    if (temp.getName() == "None")
    {
        string toDispString = item->text().toStdString() + " has nothing right now";
        QMessageBox::information(this,"Your Friend Location",QString::fromStdString(toDispString));
    }
    else
    {
        string toDispString = item->text().toStdString() + " has " + temp.getCourse() + ' ' + temp.getType() + " in " + temp.getName();
        QMessageBox::warning(this,"Your Friend Location",QString::fromStdString(toDispString));
    }
}

