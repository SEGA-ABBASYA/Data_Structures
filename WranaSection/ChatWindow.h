#ifndef CHATWINDOW_H
#define CHATWINDOW_H
#include <user.h>
#include <QWidget>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWindow(User &currentUser, User &friendUser,QWidget *parent = nullptr);
    ~ChatWindow();

private slots:
    void sendMessage();


    void on_sendMessage_clicked();

private:
    Ui::ChatWindow *ui;
    void loadChatHistory();
    User &currentUser;
    User &friendUser;
};

#endif // CHATWINDOW_H
