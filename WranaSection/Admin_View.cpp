#include "Admin_View.h"
#include "ui_Admin_View.h"
#include "course.h"
#include "database.h"
#include <QGraphicsBlurEffect>
#include <QDebug>
#include "login.h"

AdminView::AdminView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Test->setCheckable(true);
    ui->Full->hide();
}

AdminView::~AdminView()
{
    delete ui;
}


//Panels Codes
void AdminView::on_Test_toggled()
{

        ui->Icons->hide();
        ui->Full->show();
}

void AdminView::on_Test_2_toggled()
{

        ui->Icons->show();
        ui->Full->hide();
}

void AdminView::on_course_icon_toggled(bool checked)
{

    ui->stackedWidget->setCurrentIndex(0);
  //  if(checked) ui->course->setStyleSheet("color:rgb(177, 59, 177); ");
  //  else ui->course->setStyleSheet("color: rgb(255, 255, 255)") ;
}

void AdminView::on_graph_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(1);
  //  if(checked) ui->graph->setStyleSheet("color:rgb(177, 59, 177); ");
   // else ui->graph->setStyleSheet("color: rgb(255, 255, 255)") ;
}

void AdminView::on_student_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(2);
  //  if(checked) ui->student->setStyleSheet("color:rgb(177, 59, 177); ");
  //  else ui->student->setStyleSheet("color: rgb(255, 255, 255)") ;
}

void AdminView::on_schedule_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(3);
  //  if(checked) ui->schedule->setStyleSheet("color:rgb(177, 59, 177); ");
  //  else ui->schedule->setStyleSheet("color: rgb(255, 255, 255)") ;
}

void AdminView::on_logout_clicked()
{
    Login::w_stack->setCurrentIndex(0);
}

void AdminView::on_logout_2_clicked()
{
    Login::w_stack->setCurrentIndex(0);
}


//Table Manibulation
void AdminView::Write_Courses_table_edit()
{


    int i=0;
    for (auto& course : Database:: courses) {

       // qDebug() << QString::fromStdString((course.second.getTAs_S()));

        ui->tableWidget->item(i,0)->setText(QString::fromStdString(course.second.getCourseName()));
        ui->tableWidget->item(i,1)->setText(QString::fromStdString(course.second.getDepartment()));
        ui->tableWidget->item(i,2)->setText(QString::fromStdString(course.second.getLab_S()));
        ui->tableWidget->item(i,3)->setText(QString::fromStdString(course.second.getSection_S()));

        ui->tableWidget->item(i,4)->setText(QString::fromStdString(course.second.getDoctors_S()));
        ui->tableWidget->item(i,5)->setText(QString::fromStdString(course.second.getTAs_S()));


        i++;
    }

}
void AdminView::Write_Courses_table_delete()
{


    int i=0;
    for (auto& course : Database:: courses) {

        // qDebug() << QString::fromStdString((course.second.getTAs_S()));

        ui->tableWidget_3->item(i,0)->setText(QString::fromStdString(course.second.getCourseName()));
        ui->tableWidget_3->item(i,1)->setText(QString::fromStdString(course.second.getDepartment()));
        ui->tableWidget_3->item(i,2)->setText(QString::fromStdString(course.second.getLab_S()));
        ui->tableWidget->item(i,3)->setText(QString::fromStdString(course.second.getSection_S()));

        ui->tableWidget_3->item(i,4)->setText(QString::fromStdString(course.second.getDoctors_S()));
        ui->tableWidget_3->item(i,5)->setText(QString::fromStdString(course.second.getTAs_S()));


        i++;
    }

}

void AdminView::Write_Students_table_edit()
{


    int i=0;
    for (auto& student : Database:: users) {

        string Gender,ID,Academic_year,Section;

        ui->tableWidget_2->item(i,0)->setText(QString::fromStdString(student.getName()));
        ui->tableWidget_2->item(i,1)->setText(QString::fromStdString(student.getEmail()));

        ID=to_string(student.getId());
        ui->tableWidget_2->item(i,2)->setText(QString::fromStdString(ID));

        Academic_year=to_string(student.getAcademicYear());
        ui->tableWidget_2->item(i,3)->setText(QString::fromStdString( Academic_year));

        Section=to_string(student.getSection());
        ui->tableWidget_2->item(i,4)->setText(QString::fromStdString(Section));

        ui->tableWidget_2->item(i,5)->setText(QString::fromStdString(student.getUsername()));
        ui->tableWidget_2->item(i,6)->setText(QString::fromStdString(student.getPassword()));
        ui->tableWidget_2->item(i,7)->setText(QString::fromStdString(student.getProgram()));


        Gender.push_back(student.getGender());
        ui->tableWidget_2->item(i,8)->setText(QString::fromStdString(Gender));


        i++;
    }
}
void AdminView::Write_Students_table_delete()
{


    int i=0;
    for (auto& student : Database:: users) {

       string Gender,ID,Academic_year,Section;

        ui->tableWidget_4->item(i,0)->setText(QString::fromStdString(student.getName()));
        ui->tableWidget_4->item(i,1)->setText(QString::fromStdString(student.getEmail()));

        ID=to_string(student.getId());
        ui->tableWidget_4->item(i,2)->setText(QString::fromStdString(ID));

        Academic_year=to_string(student.getAcademicYear());
        ui->tableWidget_4->item(i,3)->setText(QString::fromStdString( Academic_year));

        Section=to_string(student.getSection());
        ui->tableWidget_4->item(i,4)->setText(QString::fromStdString(Section));

        ui->tableWidget_4->item(i,5)->setText(QString::fromStdString(student.getUsername()));
      ui->tableWidget_4->item(i,6)->setText(QString::fromStdString(student.getPassword()));
        ui->tableWidget_4->item(i,7)->setText(QString::fromStdString(student.getProgram()));

      Gender.push_back(student.getGender());

         ui->tableWidget_4->item(i,8)->setText(QString::fromStdString(Gender));


        i++;
    }

}


//Student Widget
void AdminView::on_pushButton_11_toggled(bool checked)
{
    //Delete
    ui->stackedWidget_student->setCurrentWidget(ui->delete_student_widget);
    Write_Students_table_delete();
}

void AdminView::on_pushButton_10_toggled(bool checked)
{
    //Edit
    ui->stackedWidget_student->setCurrentWidget(ui->edit_student_widget);
    Write_Students_table_edit();
}

void AdminView::on_pushButton_12_toggled(bool checked)
{
    //Add
    ui->stackedWidget_student->setCurrentWidget(ui->add_student_widget);
}


//Course Widget

void AdminView::on_pushButton_16_toggled(bool checked)
{
    //Edit
    ui->stack_widget_course->setCurrentWidget(ui->edit_course_widget);
    Write_Courses_table_edit();
}

void AdminView::on_pushButton_17_toggled(bool checked)
{
    //Delete
    ui->stack_widget_course->setCurrentWidget(ui->delete_course_widget);
    Write_Courses_table_delete();
}

void AdminView::on_pushButton_18_toggled(bool checked)
{
    //Add
    ui->stack_widget_course->setCurrentWidget(ui->add_course_widget);
}


//Schedule Widget
void AdminView::on_pushButton_21_toggled(bool checked)
{
    //Add
    ui->stackedWidget_schedule->setCurrentIndex(0);
}

void AdminView::on_pushButton_20_toggled(bool checked)
{
    ui->stackedWidget_schedule->setCurrentIndex(1);
}

//Graph Widget
void AdminView::on_pushButton_15_toggled(bool checked)
{
    //Add
    ui->stackedWidget_graph->setCurrentIndex(0);
}

void AdminView::on_pushButton_13_toggled(bool checked)
{
    //Edit
    ui->stackedWidget_graph->setCurrentIndex(1);
}

void AdminView::on_pushButton_14_toggled(bool checked)
{
    //Delete
    ui->stackedWidget_graph->setCurrentIndex(2);
}

