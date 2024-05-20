#include "User_View.h"
#include "ui_User_View.h"
#include "login.h"
#include <QMessageBox>
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
    : QWidget(parent)
    , ui(new Ui::UserView)
{
    ui->setupUi(this);
    ui->full->hide();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &UserView::refreshNotifications);
    timer->start(10000);
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


// friends and chat things
QMap<string,User>& usersMap = Database::users;

void UserView::search(const QString& text)
{
    qDebug() << "Search text:" << text;
    ui->resultsList->clear();
    QString searchText = text.toLower();
    for (auto it = Database::users.begin(); it !=Database::users.end(); ++it)
    {
        QString key = QString::fromStdString(it.key());
        qDebug() << "Checking user:" << key;
        if (key.contains(searchText, Qt::CaseInsensitive))
        {
            ui->resultsList->addItem(key);
        }
    }
}



void UserView::on_searchEdit_textChanged(const QString &arg1)
{
    search(arg1);
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


void UserView::on_directMessageButton_clicked()
{
    openChat();
}


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


void UserView::on_DM_3_clicked()
{
    auto it = Database::users.find(Login::USERNAME);
    if (it != Database::users.end()) {
        User& currentUser = it.value();
        currentUser.clearNotifications();
        updateNotifications();
    }
}


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

