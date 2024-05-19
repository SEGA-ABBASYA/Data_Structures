#include "ChatWindow.h"
#include <user.h>
#include "ui_ChatWindow.h"
#include <QString>

using namespace std;

ChatWindow::ChatWindow(User &currentUser, User &friendUser, QWidget *parent)
    : QWidget(parent), currentUser(currentUser), friendUser(friendUser), ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    setWindowTitle("Chat with " + QString::fromStdString(friendUser.getUsername()));
    ui->chatDisplay->setStyleSheet("QTextEdit { color: black; }");
    ui->messageEdit->setStyleSheet("QLineEdit { color: black; }");
    loadChatHistory();
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::loadChatHistory(){
    QStringList chatHistory = currentUser.getChatHistory(friendUser.getUsername());
    for(QString &message : chatHistory){
        ui->chatDisplay->append(message);
    }
}

void ChatWindow::sendMessage(){
    QString message = ui -> messageEdit->text();
    if(!message.isEmpty()){
        QString fullMessage = "Me: " + message;
        currentUser.addMessage(friendUser.getUsername(),fullMessage);
        QString notificationMessage = QString::fromStdString(currentUser.getUsername()) + ": " + message;
        friendUser.addMessage(currentUser.getUsername(),currentUser.getUsername().c_str()+QString(": ")+ message);
        friendUser.addNotification(notificationMessage);
        ui->chatDisplay->setTextColor(Qt::black);
        ui->chatDisplay->append(fullMessage);
        ui->messageEdit->clear();
    }
}

void ChatWindow::on_sendMessage_clicked()
{
    sendMessage();
}

