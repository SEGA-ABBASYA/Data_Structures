#include "cellcourseselection.h"
#include "ui_cellcourseselection.h"
#include "database.h"
#include <QMessageBox>

QListWidgetItem *curritem;

CellCourseSelection::CellCourseSelection(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CellCourseSelection)
{
    ui->setupUi(this);
    Timetable tt = Database::CurrentUserTT;
    for (auto itr : Database::schedules[tt])
    {
        string coursename = itr.getCourse();
        if (Database::CurrentUser.is_registered_course(coursename))
        {
            ui->CoursesList->addItem(QString::fromStdString("Name : " + coursename + ",Type : " + itr.getType() + ",Location : " + itr.getName()));
        }
    }
}

CellCourseSelection::~CellCourseSelection()
{
    delete ui;
}

void CellCourseSelection::on_Exit_clicked()
{
    string currentstring = curritem->text().toStdString();
    string locationName = "",CourseName = "",TypeName = "";
    string currtype = Database::CurrentUser.current_schedule[Database::CurrentUserTT].getType();
    string currcourse = Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse();
    bool isLocationName = false,isTypeName = false;
    if (currentstring != "None")
    {
        for (int i = 7;i < currentstring.size();i++)
        {
            if (currentstring[i] != ',')
            {
                if (isLocationName)
                    locationName += currentstring[i];
                else if (isTypeName)
                    TypeName += currentstring[i];
                else
                    CourseName += currentstring[i];
            }
            else
            {
                if (!isLocationName && !isTypeName)
                {
                    i+=7;
                    isTypeName = true;
                    continue;
                }
                i+=11;
                isLocationName = true;
            }
        }
    }
    else
    {
        //cout << Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse().getCourseName() << endl;
        if (Database::CurrentUser.current_schedule[Database::CurrentUserTT].getName() != "None")
        {

            if (currtype == "Lab")
            {
                Database::CurrentUser.lab[currcourse] = false;
            }
            else if (currtype == "Lecture")
            {
                Database::CurrentUser.lecture[currcourse] = false;
            }
            else
            {
                Database::CurrentUser.tutorial[currcourse] = false;
            }
        }
        Database::CurrentUser.current_schedule[Database::CurrentUserTT].setName("None");
        return;
    }
    //cout << locationName << ' ' << CourseName << ' ' << TypeName << endl;

    if ((Database::CurrentUser.lab[CourseName] && TypeName == "Lab") || (Database::CurrentUser.lecture[CourseName] && TypeName == "Lecture")
        || (Database::CurrentUser.tutorial[CourseName] && TypeName == "Tutorial"))
    {
        QMessageBox::warning(this, "Invalid Selection", "You have already registered this course on another time.");
        cout << Database::CurrentUser.current_schedule[Database::CurrentUserTT].getName() << endl;
        return;
    }
    else
    {
        if (Database::CurrentUser.current_schedule[Database::CurrentUserTT].getName() != "None")
        {

            if (currtype == "Lab")
            {
                Database::CurrentUser.lab[currcourse] = false;
            }
            else if (currtype == "Lecture")
            {
                Database::CurrentUser.lecture[currcourse] = false;
            }
            else
            {
                Database::CurrentUser.tutorial[currcourse] = false;
            }
        }
        Database::CurrentUser.current_schedule[Database::CurrentUserTT].setName(locationName);
        Database::CurrentUser.current_schedule[Database::CurrentUserTT].setCourse(CourseName);
        Database::CurrentUser.current_schedule[Database::CurrentUserTT].setType(TypeName);
        if (TypeName == "Lab")
        {
            Database::CurrentUser.lab[CourseName] = true;
        }
        else if (TypeName == "Lecture")
        {
            Database::CurrentUser.lecture[CourseName] = true;
        }
        else
        {
            Database::CurrentUser.tutorial[CourseName] = true;
        }
    }

}

void CellCourseSelection::on_CoursesList_itemPressed(QListWidgetItem *item)
{
        curritem = item;
}

