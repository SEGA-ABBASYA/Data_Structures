#ifndef LOGIN_H
#define LOGIN_H
#include "newuser.h"
#include "Admin_View.h"
#include "User_View.h"
#include <QMainWindow>
#include <QStackedWidget>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    static QStackedWidget *w_stack;
    NewUser *regPage;
    AdminView *admPage;
    UserView *userPage;
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;

private slots:
    void login();
    void reg();
    void showPass();
};

#endif // LOGIN_H
