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
    ui->stack_widget_course->hide();
    ui->stackedWidget_student->hide();

    // QGraphicsBlurEffect* p_blur = new QGraphicsBlurEffect;
    // p_blur->setBlurRadius(3);
    // p_blur->setBlurHints(QGraphicsBlurEffect::QualityHint);

    //ui->Full->setGraphicsEffect(p_blur);
   // ui->icon_name_widget_2->)
   // ui->icon_name_widget_2->auz;
 //  ui->icon_name_widget_2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

AdminView::~AdminView()
{
    delete ui;
}

void AdminView::on_Test_toggled()
{

        ui->Icons->hide();
        ui->Full->show();

    // else{
    //     ui->Icons->show();
    //     ui->Full->hide();
    // }
}

void AdminView::on_Test_2_toggled()
{

        ui->Icons->show();
        ui->Full->hide();

    // else{
    //     ui->Icons->hide();
    //     ui->Full->show();
    // }
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









 int row=5;





void AdminView::on_pushButton_11_clicked()
{
    Write_Students_table_delete();
    ui->stackedWidget_student->setCurrentWidget(ui->delete_student_widget);
    ui->stackedWidget_student->show();

}


void AdminView::on_pushButton_2_clicked()
{
    int row=ui->tableWidget_2->rowCount();
    ui->tableWidget_2->insertRow(row);
}


void AdminView::on_pushButton_4_clicked()
{
    int row=ui->tableWidget_2->rowCount();
    ui->tableWidget_2->removeRow(row-1);
}
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




void AdminView::on_logout_clicked()
{
    Login::w_stack->setCurrentIndex(0);
}




void AdminView::on_logout_2_clicked()
{
    Login::w_stack->setCurrentIndex(0);
}




void AdminView::on_pushButton_10_clicked()
{
    Write_Students_table_edit();

    ui->stackedWidget_student->setCurrentWidget(ui->edit_student_widget);
    ui->stackedWidget_student->show();
}




void AdminView::on_pushButton_16_clicked()
{
      Write_Courses_table_edit();
      ui->stackedWidget_student->setCurrentWidget(ui->edit_course_widget);
    ui->stack_widget_course->show();

}


void AdminView::on_pushButton_12_clicked()
{
    ui->stackedWidget_student->hide();
}


void AdminView::on_pushButton_17_clicked()
{
    Write_Courses_table_delete();
    ui->stack_widget_course->setCurrentWidget(ui->delete_course_widget);
    ui->stack_widget_course->show();
}

void AdminView::on_pushButton_18_clicked()
{
    ui->stack_widget_course->hide();
}

