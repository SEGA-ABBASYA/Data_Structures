#include "Admin_View.h"
#include "ui_Admin_View.h"
#include "course.h"
#include "database.h"
#include <QGraphicsBlurEffect>
#include <QDebug>
#include "login.h"
#include <vector>
#include <string>
#include"Admin.h"
#include <QTableWidgetItem>
#include <QMessageBox>

Admin admin;
Database dbase;

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

///////////////////////////////Course///////////////////////////////////

string courseName;
string courseDept;
string hasLab;
string hasSection;
string doctors;
string teachingAssistants;

// Add Course.
void AdminView::on_pushButton_clicked()
{
    courseName = ui->lineEdit->text().toLower().toStdString();
    courseDept = ui->lineEdit_2->text().toStdString();
    bool hasLab = false;
    if(ui->checkBox->isChecked())
    {
        hasLab = true;
    }
    bool hasSection = false;
    if(ui->checkBox_2->isChecked())
    {
        hasSection = true;
    }
    doctors = ui->textEdit->toPlainText().toStdString();
    teachingAssistants = ui->textEdit_2->toPlainText().toStdString();

    vector<string> newDoctors = disectStringEnter(doctors);
    vector<string> newTeachingAssistants = disectStringEnter(teachingAssistants);

    // Validation.
    bool violatedConstraint = 0;
    if (courseName.empty())
    {
        QMessageBox::warning(this, "Error", "Please enter course name.");
        violatedConstraint = 1;
    }
    else if(courseDept.empty())
    {
        QMessageBox::warning(this, "Error", "Please enter course department.");
        violatedConstraint = 1;
    }
    else if (doctors.empty())
    {
        QMessageBox::warning(this, "Error", "Please enter course doctors names.");
        violatedConstraint = 1;
    }
    else if (teachingAssistants.empty() && (hasLab == 1 || hasSection == 1))
    {
        QMessageBox::warning(this, "Error", "Please enter course TAs names.");
        violatedConstraint = 1;
    }
    else
    {
        Course course(courseName,courseDept,hasLab,hasSection,newDoctors,newTeachingAssistants);
        // If course doesn't exist append it.
        if (dbase.courses.find(course.getCourseName()) == dbase.courses.end())
        {
            admin.addCourse(course);
        }
        else // Course found in map
        {
            QMessageBox::warning(this, "Error", "Course Already Exists,\nYou can edit course in the edit screen.");
        }
    }
}
vector<string> AdminView::disectStringEnter(string str)
{
    string str2;
    vector<string> newvector;
    for (int i=0;i< str.length();i++)
    {
        if (str[i] == '\n')
        {
            newvector.push_back(str2);
            str2.clear();
        }
        else
        {
            str2.push_back(str[i]);
        }
    }
    newvector.push_back(str2);
    return newvector;
}

// Delete course.
void AdminView::on_tableWidget_3_itemClicked(QTableWidgetItem *item)
{
    if (item != nullptr) {
        int row = item->row();
        QTableWidgetItem *cellItem = ui->tableWidget_3->item(row, 0);
        if (cellItem != nullptr)
        {
            courseName = cellItem->data(Qt::DisplayRole).toString().toStdString();
        }
    }
    cout<<courseName<<endl;
}
void AdminView::on_Delete_clicked()
{
    admin.deleteCourse(courseName);
}

// Edit course.

string currentCourseName;

bool AdminView::encodeValues(string hasLabOrSection)
{
    if (hasLabOrSection == "yes")
        return 1;
    else
        return 0;
}
vector<string> AdminView::disectStringComma(string str)
{
    string str2;
    vector<string> newvector;
    for (int i=0;i< str.length();i++)
    {
        if (str[i] == ',')
        {
            newvector.push_back(str2);
            str2.clear();
        }
        else
        {
            str2.push_back(str[i]);
        }
    }
    newvector.push_back(str2);
    return newvector;
}
void AdminView::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if (item != nullptr) {
        int row = item->row();
        QTableWidgetItem *cellItem = ui->tableWidget->item(row, 0);
        if (cellItem != nullptr)
        {
            currentCourseName = cellItem->data(Qt::DisplayRole).toString().toStdString();
        }
    }
    cout<<currentCourseName<<endl;
}
void AdminView::on_Edit_clicked()
{
    int row = ui->tableWidget->currentRow();
    for (int col = 0; col < 6; ++col) {
        QTableWidgetItem *cellItem = ui->tableWidget->item(row, col);
        if (cellItem != nullptr) {
            // Assign data to corresponding variables based on column index
            switch (col) {
            case 0:
                courseName = cellItem->text().toLower().toStdString();
                break;
            case 1:
                courseDept = cellItem->text().toStdString();
                break;
            case 2:
                hasLab = cellItem->text().toStdString();
                break;
            case 3:
                hasSection = cellItem->text().toStdString();
                break;
            case 4:
                doctors = cellItem->text().toStdString();
                break;
            case 5:
                teachingAssistants = cellItem->text().toStdString();
                break;
            default:
                break;
            }
        }
    }

    bool newHasLab = encodeValues(hasLab);
    bool newHasSection = encodeValues(hasSection);
    vector<string> newDoctors = disectStringComma(doctors);
    vector<string> newTeachingAssistants = disectStringComma(teachingAssistants);

    Course course(courseName,courseDept,newHasLab,newHasSection,newDoctors,newTeachingAssistants);

    if (dbase.courses.find(course.getCourseName()) == dbase.courses.end() || currentCourseName == courseName)
    {
        // Key doesn't exist in the map, proceed to edit the course
        admin.deleteCourse(currentCourseName);
        admin.editCourse(course);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Course Already Exists and is Identical.");
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////



