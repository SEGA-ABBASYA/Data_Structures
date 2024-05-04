#include "User_View.h"
#include "ui_User_View.h"
#include <QGraphicsBlurEffect>

UserView::UserView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Test->setCheckable(true);
    ui->Full->hide();
}

UserView::~UserView()
{
    delete ui;
}

void UserView::on_Test_toggled()
{

    ui->Icons->hide();
    ui->Full->show();
}

void UserView::on_Test_2_toggled()
{

    ui->Icons->show();
    ui->Full->hide();
}


void UserView::on_course_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(0);
}


void UserView::on_graph_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(1);
}


void UserView::on_student_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(2);
}

void UserView::on_schedule_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(3);
}


void UserView::on_FrienddsButton_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(4);
}


void UserView::on_NotificationButton_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(5);
}

