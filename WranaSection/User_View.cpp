#include "User_View.h"
#include "ui_User_View.h"
#include "login.h"
#include <QMessageBox>
QListWidgetItem *user;
UserView::UserView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserView)
{
    ui->setupUi(this);
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


void UserView::on_text_filter_2_textChanged(const QString &arg1)
{
    for (int i = 0; i < ui->Registerd_courses->count(); ++i) {
        QListWidgetItem *item = ui->Registerd_courses->item(i);
        item->setHidden(!item->text().contains(arg1, Qt::CaseInsensitive));
    }
}

