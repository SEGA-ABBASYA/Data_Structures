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
    regPage = new NewUser();
    admPage = new AdminView();
    w_stack = new QStackedWidget(this);
    w_stack->addWidget(ui->centralwidget);
    w_stack->addWidget(regPage);
    w_stack->addWidget(admPage);
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
    delete ui;
}

void Login::login()
{
    string userName = ui->userNameLineEdit->text().toLower().toStdString();
    string password = ui->passwordLineEdit->text().toStdString();
    auto user = Database::users.find(userName);
    if(userName == "admin" && password == "admin"){
        w_stack->setCurrentWidget(admPage);
        ui->userNameLineEdit->text().clear();
        ui->passwordLineEdit->text().clear();
    }
    else if(user == Database::users.end())
    {
        QMessageBox::warning(this, "Error", "Wrong UserName");
    }
    else if(user->getPassword() == password)
    {
        // Data::currentUserName = userName;
        QMessageBox::information(this, "Success", "Welcome Back " + QString::fromStdString(user->getName()));
        // Home *home = new Home();
        // home->show();
        // this->close();
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

    w_stack->setCurrentIndex(1);
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
