#include "login.h"
#include "ui_login.h"
#include "database.h"
#include "newuser.h"
#include <QMessageBox>
QStackedWidget* Login::w_stack = nullptr;
Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    w_stack = new QStackedWidget(this);
    w_stack->addWidget(ui->centralwidget);
    setCentralWidget(w_stack);
    w_stack->show();
    QFile styleFile("Files/dark_theme.qss");
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString style = styleFile.readAll();
        ui->centralwidget->setStyleSheet(style);
        styleFile.close();
    } else {
        qDebug() << "StyleSheet File Can't be opened.\n";
    }
    connect(ui->registerBtn, SIGNAL(clicked(bool)), this, SLOT(reg()));
    connect(ui->loginBtn, SIGNAL(clicked(bool)), this, SLOT(login()));
    connect(ui->showPassCheckBox, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(showPass()));
}

Login::~Login()
{
    delete w_stack;
    delete ui;
}

void Login::login()
{
    string userName = ui->userNameLineEdit->text().toLower().toStdString();
    string password = ui->passwordLineEdit->text().toStdString();
    if(userName == "admin" && password == "admin"){
        admPage = new AdminView();
        w_stack->addWidget(admPage);
        w_stack->setCurrentWidget(admPage);
        ui->userNameLineEdit->clear();
        ui->passwordLineEdit->clear();
        return;
    }
    auto user = Database::users.find(userName);
    if(user == Database::users.end())
    {
        QMessageBox::warning(this, "Error", "Wrong UserName");
    }
    else if(user->getPassword() == password)
    {
        // Data::currentUserName = userName;
        //QMessageBox::information(this, "Success", "Welcome Back " + QString::fromStdString(user->getName()));
        // Home *home = new Home();
        // home->show();
        // this->close();
        Database::CurrentUser = userName;
        userPage = new UserView();
        w_stack->addWidget(userPage);
        w_stack->setCurrentWidget(userPage);
        ui->userNameLineEdit->clear();
        ui->passwordLineEdit->clear();
    }
    else{
        QMessageBox::warning(this, "Error", "Wrong Password");
    }

}

void Login::reg()
{
    // NewUser *newUser = new NewUser();
    // newUser->show();
    // this->close();
    regPage = new NewUser();
    w_stack->addWidget(regPage);
    w_stack->setCurrentWidget(regPage);
    ui->userNameLineEdit->clear();
    ui->passwordLineEdit->clear();
}


void Login::showPass()
{
    if(ui->showPassCheckBox->isChecked()){
        ui->passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Normal);
    }
    else {
        ui->passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
    }
}
