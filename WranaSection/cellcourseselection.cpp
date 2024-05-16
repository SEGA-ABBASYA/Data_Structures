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
    auto Schmap = Database::schedules.toStdMap();
    for (auto i : Schmap)
    {
        auto tempmap = i.second.toStdMap();
        for (auto j : tempmap)
        {
            if (j.first.day != tt.day || j.first.hour != tt.hour) continue;
            QString str = "Name : " + QString::fromStdString(j.second.getCourse().getCourseName() + ",Location : " + i.first);
            ui->CoursesList->addItem(str);
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
    string locationName = "",CourseName = "";
    bool isLocationName = false;
    if (currentstring != "None")
    {
        for (int i = 7;i < currentstring.size();i++)
        {
            if (currentstring[i] != ',')
            {
                if (isLocationName)
                    locationName += currentstring[i];
                else
                    CourseName += currentstring[i];
            }
            else
            {
                i+=11;
                isLocationName = true;
            }
        }
    }
    else
    {
        //cout << Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse().getCourseName() << endl;
        if (Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse().getCourseName() != "None")
        {
            Database::CurrentUser.unregister_course(Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse().getCourseName());
        }
        Course cors;
        cors.setCourseName("None");
        Schedule currschedule;
        currschedule.setCourse(Database::courses[CourseName]);
        Database::CurrentUser.current_schedule[Database::CurrentUserTT] = currschedule;
        return;
    }

    if (Database::CurrentUser.is_registered_course(CourseName))
    {
        QMessageBox::warning(this, "Invalid Selection", "You have already registered this course on another time.");
        cout << Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse().getCourseName() << endl;
        return;
    }

    else
    {
        if (Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse().getCourseName() != "None")
        {
            Database::CurrentUser.unregister_course(Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse().getCourseName());
        }
        Schedule currschedule;
        Course newcourse;
        newcourse.setCourseName(CourseName);

        if (Database::courses[CourseName].getCourseName() == "None")
            Database::courses[CourseName] = newcourse;

        currschedule.setCourse(Database::courses[CourseName]);
        Database::CurrentUser.register_courses(Database::courses[CourseName]);
        Database::CurrentUser.current_schedule[Database::CurrentUserTT] = currschedule;
    }
    cout << Database::CurrentUser.current_schedule[Database::CurrentUserTT].getCourse().getCourseName() << endl;
}

void CellCourseSelection::on_CoursesList_itemClicked(QListWidgetItem *item)
{
        curritem = item;
}

