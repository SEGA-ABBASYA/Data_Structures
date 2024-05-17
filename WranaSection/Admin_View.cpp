#include "Admin_View.h"
#include "ui_Admin_View.h"
#include "course.h"
#include "database.h"
#include <QGraphicsBlurEffect>
#include <QDebug>
#include "login.h"
#include <vector>
#include <string>
#include "Admin.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include "user.h"
#include <QString>
#include <QMessageBox>
#include <regex>

Admin admin;
Database dbase;

AdminView::AdminView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Test->setCheckable(true);
    ui->Full->hide();
    QStringList programs = {"General", "SC", "CS", "CSys", "IS", "Bioinformatics", "AI", "SW", "Cyber Security", "Robotics", "Multimedia"};
    ui->programComboBox->addItems(programs);
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
    on_pushButton_15_toggled(true);
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
    ui->tableWidget->setRowCount(Database::courses.size());
    for (auto& course : Database::courses) {

        // qDebug() << QString::fromStdString((course.second.getTAs_S()));
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(QString::fromStdString(course.second.getCourseName())));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(QString::fromStdString(course.second.getDepartment())));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(QString::fromStdString(course.second.getLab_S())));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(QString::fromStdString(course.second.getSection_S())));

        ui->tableWidget->setItem(i,4, new QTableWidgetItem(QString::fromStdString(course.second.getDoctors_S())));
        ui->tableWidget->setItem(i,5, new QTableWidgetItem(QString::fromStdString(course.second.getTAs_S())));


        i++;
    }

}
void AdminView::Write_Courses_table_delete()
{


    int i=0;
    ui->tableWidget_3->setRowCount(Database::courses.size());
    for (auto& course : Database:: courses) {

        // qDebug() << QString::fromStdString((course.second.getTAs_S()));

        ui->tableWidget_3->setItem(i,0, new QTableWidgetItem(QString::fromStdString(course.second.getCourseName())));
        ui->tableWidget_3->setItem(i,1, new QTableWidgetItem(QString::fromStdString(course.second.getDepartment())));
        ui->tableWidget_3->setItem(i,2, new QTableWidgetItem(QString::fromStdString(course.second.getLab_S())));
        ui->tableWidget_3->setItem(i,3, new QTableWidgetItem(QString::fromStdString(course.second.getSection_S())));

        ui->tableWidget_3->setItem(i,4, new QTableWidgetItem(QString::fromStdString(course.second.getDoctors_S())));
        ui->tableWidget_3->setItem(i,5, new QTableWidgetItem(QString::fromStdString(course.second.getTAs_S())));



        i++;
    }

}

void AdminView::Write_Students_table_edit()
{


    int i=0;
    ui->tableWidget_2->setRowCount(Database::users.size());
    for (auto& student : Database:: users) {

        string Gender,ID,Academic_year,Section;

        ui->tableWidget_2->setItem(i,0, new QTableWidgetItem(QString::fromStdString(student.getName())));
        ui->tableWidget_2->setItem(i,1, new QTableWidgetItem(QString::fromStdString(student.getEmail())));

        ID=to_string(student.getId());
        ui->tableWidget_2->setItem(i,2, new QTableWidgetItem(QString::fromStdString(ID)));

        Academic_year=to_string(student.getAcademicYear());
        ui->tableWidget_2->setItem(i,3, new QTableWidgetItem(QString::fromStdString( Academic_year)));

        Section=to_string(student.getSection());
        ui->tableWidget_2->setItem(i,4, new QTableWidgetItem(QString::fromStdString(Section)));

        ui->tableWidget_2->setItem(i,5, new QTableWidgetItem(QString::fromStdString(student.getUsername())));
        ui->tableWidget_2->setItem(i,6, new QTableWidgetItem(QString::fromStdString(student.getPassword())));
        ui->tableWidget_2->setItem(i,7, new QTableWidgetItem(QString::fromStdString(student.getProgram())));


        Gender.push_back(student.getGender());
        ui->tableWidget_2->setItem(i,8, new QTableWidgetItem(QString::fromStdString(Gender)));


        i++;
    }
}
void AdminView::Write_Students_table_delete()
{


    int i=0;
    ui->tableWidget_4->setRowCount(Database::users.size());
    for (auto& student : Database:: users) {

        string Gender,ID,Academic_year,Section;

        ui->tableWidget_4->setItem(i,0, new QTableWidgetItem(QString::fromStdString(student.getName())));
        ui->tableWidget_4->setItem(i,1, new QTableWidgetItem(QString::fromStdString(student.getEmail())));

        ID=to_string(student.getId());
        ui->tableWidget_4->setItem(i,2, new QTableWidgetItem(QString::fromStdString(ID)));

        Academic_year=to_string(student.getAcademicYear());
        ui->tableWidget_4->setItem(i,3, new QTableWidgetItem(QString::fromStdString( Academic_year)));

        Section=to_string(student.getSection());
        ui->tableWidget_4->setItem(i,4, new QTableWidgetItem(QString::fromStdString(Section)));

        ui->tableWidget_4->setItem(i,5, new QTableWidgetItem(QString::fromStdString(student.getUsername())));
        ui->tableWidget_4->setItem(i,6, new QTableWidgetItem(QString::fromStdString(student.getPassword())));
        ui->tableWidget_4->setItem(i,7, new QTableWidgetItem(QString::fromStdString(student.getProgram())));

        Gender.push_back(student.getGender());

        ui->tableWidget_4->setItem(i,8, new QTableWidgetItem(QString::fromStdString(Gender)));


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
void AdminView::Write_graph_list_add()
{
    ui->add_Graph_list->clear();
    for(auto& loc : Database::locations)
    {
        if(!loc.second.getHall())
        {
            ui->add_Graph_list->addItem(QString::fromStdString(loc.second.getName()));
        }
    }
}
void AdminView::on_pushButton_15_toggled(bool checked)
{
    //Add
    Write_graph_list_add();
    ui->stackedWidget_graph->setCurrentIndex(0);
}


void AdminView::on_pushButton_13_toggled(bool checked)
{
    //Edit
    ui->comboLocation1->clear();
    for (auto& loc : Database::locations)
    {
        ui->comboLocation1->addItem(QString::fromStdString(loc.second.getName()));
    }
    ui->stackedWidget_graph->setCurrentIndex(1);

    ui->comboLocation2->clear();
    for (auto& loc : Database::locations)
    {
        ui->comboLocation2->addItem(QString::fromStdString(loc.second.getName()));
    }
    ui->stackedWidget_graph->setCurrentIndex(1);
}

void AdminView::Write_graph_list_delete()
{
    ui->delete_Graph_list->clear();
    for(auto& loc : Database::locations)
    {
        if(loc.second.getHall())
        {
            ui->delete_Graph_list->addItem(QString::fromStdString(loc.second.getName()));
        }
    }
}
void AdminView::on_pushButton_14_toggled(bool checked)
{
    //Delete
    Write_graph_list_delete();
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
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->textEdit->clear();
            ui->textEdit_2->clear();
            ui->checkBox->setCheckState(Qt::Unchecked);
            ui->checkBox_2->setCheckState(Qt::Unchecked);
            QMessageBox::information(this, "Message", "Course successfully added!");
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
    if (item != nullptr)
    {
        int row = item->row();
        QTableWidgetItem *cellItem = ui->tableWidget_3->item(row, 0);
        if (cellItem != nullptr)
        {
            courseName = cellItem->text().toStdString();
        }
    }
}
void AdminView::on_Delete_clicked()
{
    admin.deleteCourse(courseName);
    Write_Courses_table_delete();
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
    int row = ui->tableWidget->currentRow();
    ui->tableWidget->item(row, 0)->setFlags(Qt::NoItemFlags);
    ui->tableWidget->item(row, 1)->setFlags(Qt::NoItemFlags);
    ui->tableWidget->item(row, 2)->setFlags(Qt::NoItemFlags);
    ui->tableWidget->item(row, 3)->setFlags(Qt::NoItemFlags);

    if (item != nullptr)
    {
        int row = item->row();
        QTableWidgetItem *cellItem = ui->tableWidget->item(row, 0);
        if (cellItem != nullptr)
        {
            currentCourseName = cellItem->text().toStdString();
        }
    }
}
void AdminView::on_Edit_clicked()
{
    int row = ui->tableWidget->currentRow();
    for (int col = 0; col < 6; ++col)
    {
        QTableWidgetItem *cellItem = ui->tableWidget->item(row, col);
        if (cellItem != nullptr)
        {
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

////////////////////////////////////////User//////////////////////////////////////////////////
string name;
string email;
string username;
string password;
string program;
char gender = 'N';
int id;
int academicYear;
int section;

// Add user.
bool validEmails(string email)
{
    std::regex pattern(R"(^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$)");
    return std::regex_match(email, pattern);
}

void AdminView::on_Add_clicked()
{
    name = ui->nameLineEdit->text().toStdString();
    email = ui->nameLineEdit_2->text().toStdString();
    username = ui->nameLineEdit_3->text().toStdString();
    password = ui->nameLineEdit_4->text().toStdString();
    id = ui->nameLineEdit_5->text().toInt();
    academicYear = ui->sectionSpinBox_2->value();
    section = ui->sectionSpinBox->value();
    program = ui->programComboBox->currentText().toStdString();
    if(ui->male->isChecked())
    {
        gender = 'M';
    }
    if (ui->female->isChecked())
    {
        gender = 'F';
    }

    // Validation.
    auto user = Database::users.find(username);
    if(!validEmails(email))
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
    else if(to_string(id).size() < 10)
    {
        QMessageBox::warning(this, "Error", "Hello " + QString::fromStdString(name) + "\nPlease, Check the id, it should be at least 10 digits");
    }
    else if(name.empty() || email.empty() || username.empty() || password.empty() || gender == 'N')
    {
        QMessageBox::warning(this, "Error", "Please complete all fields");
    }
    else
    {
        User user(name,email,id,academicYear,section,username,password,program,gender);
        admin.addUser(user);
        ui->nameLineEdit->clear();
        ui->nameLineEdit_2->clear();
        ui->nameLineEdit_3->clear();
        ui->nameLineEdit_4->clear();
        ui->nameLineEdit_5->clear();
        ui->programComboBox->setEditText("General");
        ui->sectionSpinBox->setValue(1);
        ui->sectionSpinBox_2->setValue(1);
        QMessageBox::information(this, "Message", "User successfully added!");
    }
}

// Delete user.
void AdminView::on_tableWidget_4_itemClicked(QTableWidgetItem *item)
{
    if (item != nullptr)
    {
        int row = item->row();
        QTableWidgetItem *cellItem = ui->tableWidget_4->item(row, 5);
        if (cellItem != nullptr)
        {
            username = cellItem->text().toStdString();
        }
    }
}

void AdminView::on_deleteStudent_clicked()
{
    admin.deleteUser(username);
    Write_Students_table_delete();
}

// Edit user.

string currentUsername;
string oldGender;

void AdminView::on_tableWidget_2_itemClicked(QTableWidgetItem *item)
{
    if (item != nullptr)
    {
        int row = item->row();
        QTableWidgetItem *cellItem = ui->tableWidget_2->item(row, 5);
        if (cellItem != nullptr)
        {
            currentUsername = cellItem->text().toStdString();
        }
    }
}
void AdminView::on_EditStudent_clicked()
{
    int row = ui->tableWidget_2->currentRow();
    for (int col = 0; col < 9; ++col)
    {
        QTableWidgetItem *cellItem = ui->tableWidget_2->item(row, col);
        if (cellItem != nullptr)
        {
            // Assign data to corresponding variables based on column index
            switch (col)
            {
            case 0:
                name = cellItem->text().toLower().toStdString();
                break;
            case 1:
                email = cellItem->text().toStdString();
                break;
            case 2:
                id = cellItem->text().toInt();
                break;
            case 3:
                academicYear = cellItem->text().toInt();
                break;
            case 4:
                section = cellItem->text().toInt();
                break;
            case 5:
                username = cellItem->text().toStdString();
                break;
            case 6:
                password = cellItem->text().toStdString();
                break;
            case 7:
                program = cellItem->text().toStdString();
                break;
            case 8:
                oldGender = cellItem->text().toStdString();
                gender = oldGender[0];
                break;
            default:
                break;
            }
        }
    }
    // Validation.
    auto user = Database::users.find(username);
    if(!validEmails(email))
    {
        QMessageBox::warning(this, "Error", "Hello " + QString::fromStdString(name) + "\nNot Valid Email");
    }
    else if(!(user != Database::users.end() || currentUsername == username))
    {
        QMessageBox::warning(this, "Error", "userName is Already Exist");
    }
    else if(password.size() < 8)
    {
        QMessageBox::warning(this, "Error", "Hello " + QString::fromStdString(name) + "\nPlease, Choose a password with 8 or more characters");
    }
    else if(to_string(id).size() < 10)
    {
        QMessageBox::warning(this, "Error", "Hello " + QString::fromStdString(name) + "\nPlease, Check the id, it should be at least 10 digits");
    }
    else if(name.empty() || email.empty() || username.empty() || password.empty() || gender == 'N')
    {
        QMessageBox::warning(this, "Error", "Please complete all fields");
    }
    else
    {
        User user(name,email,id,academicYear,section,username,password,program,gender);
        admin.deleteUser(currentUsername);
        admin.editUser(user);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////Graph////////////////////////////////////////////

string locationName;
string location1Name;
string location2Name;

// Add location.
void AdminView::on_add_Graph_list_itemClicked(QListWidgetItem *item)
{
    locationName = item->text().toStdString();
}
void AdminView::on_add_graph_Btn_clicked()
{
    admin.addLocation(locationName);
    Write_graph_list_add();
}

// Delete location.
void AdminView::on_delete_Graph_list_itemClicked(QListWidgetItem *item)
{
    locationName = item->text().toStdString();
}
void AdminView::on_Delete_2_clicked()
{
    admin.deleteLocation(locationName);
    Write_graph_list_delete();
}

// Edit location.
void AdminView::on_Edit_2_clicked()
{
    location1Name = ui->comboLocation1->currentText().toStdString();
    location2Name = ui->comboLocation2->currentText().toStdString();

    if (location1Name == location2Name)
    {
        QMessageBox::warning(this, "Error", "Please choose 2 different locations so we can swap them.");
    }
    else
    {
        admin.editLocation(location1Name, location2Name);
        QMessageBox::information(this, "Message", "You Have Swapped " + QString::fromStdString(location1Name) + " With " + QString::fromStdString(location2Name) + "\nSuccessfully!");
    }
}

