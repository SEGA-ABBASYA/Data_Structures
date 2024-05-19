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
        if (Database::users[Database::CurrentUser].is_registered_course(coursename))
        {
            string groupstring,sectionstring = to_string(itr.getSection());
            if (itr.getGroup()==0)
                groupstring = "G1";
            else
                groupstring = "G2";
            ui->CoursesList->addItem(QString::fromStdString("Name : " + coursename + ",Type : " + itr.getType() + ",Location : " + itr.getName() + ",Section : " + sectionstring + ",Group : " + groupstring));
        }
    }
}

CellCourseSelection::~CellCourseSelection()
{
    //cout << "u luv me" << endl;
    delete ui;
}

void CellCourseSelection::on_Exit_clicked()
{
    string currentstring = curritem->text().toStdString();
    string locationName = "",CourseName = "",TypeName = "",SectionString = "";
    string currtype = Database::users[Database::CurrentUser].current_schedule[Database::CurrentUserTT].getType();
    string currcourse = Database::users[Database::CurrentUser].current_schedule[Database::CurrentUserTT].getCourse();
    bool isLocationName = false,isTypeName = false,isSectionName = false;
    int groupNum,sectionNum;
    if (currentstring != "None")
    {
        for (int i = 7;i < currentstring.size();i++)
        {
            if (currentstring[i] != ',')
            {
                if (isSectionName)
                    SectionString += currentstring[i];
                else if (isLocationName)
                    locationName += currentstring[i];
                else if (isTypeName)
                    TypeName += currentstring[i];
                else
                    CourseName += currentstring[i];
            }
            else
            {
                if (isSectionName)
                    break;
                if (!isLocationName && !isTypeName)
                {
                    i+=7;
                    isTypeName = true;
                    continue;
                }
                else if (!isLocationName)
                {
                    i+=11;
                    isLocationName = true;
                    continue;
                }
                i+=10;
                isSectionName = true;
            }
        }
        groupNum = currentstring[currentstring.size()-1] - '0';
        groupNum--;
        sectionNum = stoi(SectionString);
    }
    else
    {
        //cout << Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse().getCourseName() << endl;
        if (Database::users[Database::CurrentUser].current_schedule[Database::CurrentUserTT].getName() != "None")
        {

            if (currtype == "Lab")
            {
                Database::users[Database::CurrentUser].lab[currcourse] = false;
            }
            else if (currtype == "Lecture")
            {
                Database::users[Database::CurrentUser].lecture[currcourse] = false;
            }
            else
            {
                Database::users[Database::CurrentUser].tutorial[currcourse] = false;
            }
        }
        Database::users[Database::CurrentUser].current_schedule[Database::CurrentUserTT].setName("None");
        return;
    }
    //cout << locationName << ' ' << CourseName << ' ' << TypeName << endl;

    if ((Database::users[Database::CurrentUser].lab[CourseName] && TypeName == "Lab") || (Database::users[Database::CurrentUser].lecture[CourseName] && TypeName == "Lecture")
        || (Database::users[Database::CurrentUser].tutorial[CourseName] && TypeName == "Tutorial"))
    {
        QMessageBox::warning(this, "Invalid Selection", "You have already registered this course on another time.");
        //cout << Database::users[Database::CurrentUser].current_schedule[Database::CurrentUserTT].getName() << endl;
        return;
    }
    else
    {
        if (Database::users[Database::CurrentUser].current_schedule[Database::CurrentUserTT].getName() != "None")
        {

            if (currtype == "Lab")
            {
                Database::users[Database::CurrentUser].lab[currcourse] = false;
            }
            else if (currtype == "Lecture")
            {
                Database::users[Database::CurrentUser].lecture[currcourse] = false;
            }
            else
            {
                Database::users[Database::CurrentUser].tutorial[currcourse] = false;
            }
        }
        Schedule newSchedule(locationName,TypeName,sectionNum,groupNum,Database::CurrentUserTT,CourseName);
        Database::users[Database::CurrentUser].current_schedule[Database::CurrentUserTT] = newSchedule;
        if (TypeName == "Lab")
        {
            Database::users[Database::CurrentUser].lab[CourseName] = true;
        }
        else if (TypeName == "Lecture")
        {
            Database::users[Database::CurrentUser].lecture[CourseName] = true;
        }
        else
        {
            Database::users[Database::CurrentUser].tutorial[CourseName] = true;
        }
    }

}

void CellCourseSelection::on_CoursesList_itemPressed(QListWidgetItem *item)
{
    curritem = item;
}

