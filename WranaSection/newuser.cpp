#include "newuser.h"
#include "ui_newuser.h"
#include "user.h"
#include "login.h"
#include "database.h"
#include <QString>
#include <QMessageBox>
#include <regex>

bool validEmail(string email){
    std::regex pattern(R"(^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$)");
    return std::regex_match(email, pattern);
}

NewUser::NewUser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NewUser)
{
    ui->setupUi(this);

    QFile styleFile("Files/dark_theme.qss");
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString style = styleFile.readAll();
        ui->centralwidget->setStyleSheet(style);
        styleFile.close();
    } else {
        qDebug() << "StyleSheet File Can't be opened.\n";
    }
    QStringList programs = {"General", "SC", "CS", "CSys", "IS", "Bioinformatics", "AI", "SW", "Cyber Security", "Robotics", "Multimedia"};
    ui->programComboBox->addItems(programs);
    connect(ui->loginBtn, SIGNAL(clicked(bool)), this, SLOT(login()));
    connect(ui->registerBtn, SIGNAL(clicked(bool)), this, SLOT(reg()));
    connect(ui->showPassCheckBox, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(showPass()));
}

NewUser::~NewUser()
{
    delete ui;
}

void NewUser::reg()
{
    string name =  ui->nameLineEdit->text().toStdString();
    string email = ui->emailLineEdit->text().toLower().toStdString();
    string userName = ui->userNameLineEdit->text().toLower().toStdString();
    string password = ui->passwordLineEdit->text().toStdString();
    int id = ui->idLineEdit->text().toInt();
    int section = ui->sectionSpinBox->value();
    string program = ui->programComboBox->currentText().toStdString();
    int year = ui->yearSpinBox->value();
    char gender = 'N';
    if(ui->male->isChecked() || ui->female->isChecked()) gender = (ui->male->isChecked())? 'M': 'F';

    auto user = Database::users.find(userName);
    if(!validEmail(email))
    {
        QMessageBox::warning(this, "Error", "Hello " + QString::fromStdString(name) + "\nNot Valid Email");
    }
    else if(user != Database::users.end())
    {
        QMessageBox::warning(this, "Error", "userName is Already Exist");
    }
    else if(password.size() < 8)
    {
        QMessageBox::warning(this, "Error", "Hello " + QString::fromStdString(name) + "\nPlease, Choose a password with 8 or more characters");
    }
    else if(ui->idLineEdit->text().size() < 10)
    {
        QMessageBox::warning(this, "Error", "Hello " + QString::fromStdString(name) + "\nPlease, Check the id, it should be at least 10 digits");
    }
    else if(name.empty() || email.empty() || userName.empty() || password.empty() || gender == 'N')
    {
        QMessageBox::warning(this, "Error", "Please complete all fields");
    }
    else
    {
        User newUser(name, email, id, year, section, userName, password, program, gender);
        Database::users.insert(userName, newUser);
        // Data::currentUserName = userName;
        //QMessageBox::information(this, "Success", "Hello " + QString::fromStdString(name));
        // Home *home = new Home();
        // home->show();
        // this->close();
        Login::w_stack->setCurrentIndex(0);
    }
}

void NewUser::login()
{
    Login::w_stack->setCurrentIndex(0);

}

void NewUser::showPass()
{
    if(ui->showPassCheckBox->isChecked()){
        ui->passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Normal);
    }
    else {
        ui->passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
    }
}
