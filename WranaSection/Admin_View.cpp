#include "Admin_View.h"
#include "ui_Admin_View.h"
#include"course.h"
#include"database.h"
#include <QGraphicsBlurEffect>
#include <QDebug>

AdminView::AdminView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Test->setCheckable(true);
    ui->Full->hide();
    ui->add_courses_widget->hide();
    ui->pushButton->hide();
    ui->pushButton_3->hide();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
     ui->add_courses_widget_2->hide();
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



void AdminView::on_pushButton_18_clicked()
{
    Write_Courses_table();
    ui->add_courses_widget->show();
      ui->pushButton_3->hide();
    ui->pushButton->show();
   //ui->pushButton_2->show();
}


void AdminView::on_pushButton_clicked()
{


    Add_course_row();


}



 int row=5;

void AdminView::on_pushButton_3_clicked()
{
    // int row=ui->tableWidget->rowCount();
    Delete_course_row();
    ui->tableWidget->item(row-1,0)->setText("null");
   ui->tableWidget->item(row-1,1)->setText("null");
   ui->tableWidget->item(row-1,2)->setText("null");
   ui->tableWidget->item(row-1,3)->setText("null");
   ui->tableWidget->item(row-1,4)->setText("null");
   ui->tableWidget->item(row-1,5)->setText("null");
}


void AdminView::on_pushButton_17_clicked()
{
     Write_Courses_table();
      ui->add_courses_widget->show();

        ui->pushButton->hide();
    ui->pushButton_3->show();


}


void AdminView::on_pushButton_12_clicked()
{
    ui->add_courses_widget_2->show();
     ui->pushButton_4->hide();
    ui->pushButton_2->show();
}


void AdminView::on_pushButton_11_clicked()
{
     ui->add_courses_widget_2->show();
     ui->pushButton_2->hide();
     ui->pushButton_4->show();
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
void AdminView::Write_Courses_table()
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




void AdminView::Add_course_row()
{

   // ui->tableWidget->item(5,0)->setText("malak");
    string name,dept,lab,section,doctors,TA_s, tempString; bool section_b,lab_b;
    name= ui->tableWidget->item(row,0)->text().toStdString();
    dept= ui->tableWidget->item(row,1)->text().toStdString();
    lab= ui->tableWidget->item(row,2)->text().toStdString();
    section= ui->tableWidget->item(row,3)->text().toStdString();
    doctors= ui->tableWidget->item(row,4)->text().toStdString();
      TA_s= ui->tableWidget->item(row,5)->text().toStdString();

    row++;

    section_b=(section=="yes")? 1:0;
    lab_b=(lab=="yes")? 1:0;
    vector<string>ALLDoctors,ALLTAs;

    for (char c :  doctors) {
        if (c != ',') {
            tempString += c;
        } else {
            ALLDoctors.push_back(tempString);
            tempString.clear();
        }
    }

     tempString.clear(); //a,b,
    for (char c :   TA_s) {
        if (c != ',') {
            tempString += c;
        } else {
            ALLTAs.push_back(tempString);
            tempString.clear();
        }
    }

   // ALLTAs.push_back(tempString);

    Course c(name,dept,lab_b,section_b,ALLDoctors,ALLTAs);
   Database::courses[name]=c;
}
void AdminView::Delete_course_row()
{
    string name= ui->tableWidget->item(row-1,0)->text().toStdString();
    Database::courses.erase(name);
    row--;
}

