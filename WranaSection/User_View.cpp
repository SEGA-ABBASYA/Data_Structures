#include "User_View.h"
#include "ui_User_View.h"
#include "login.h"
#include "Buildingchoose.h"
#include <QMessageBox>

Location UserView::startRoom;
Location UserView::endRoom;
#include "database.h"
#include "Navigation.h"
QStackedWidget* UserView::g_stack = nullptr;
QListWidgetItem *user;
UserView::UserView(QWidget *parent)
    : QWidget(parent), statusBar(new QStatusBar(this))
    , ui(new Ui::UserView)
{
    ui->setupUi(this);
    ui->verticalLayout_2->addWidget(statusBar);
    statusBar->showMessage("Ready for the Sugar Cane");
    u = new UndergroundFloor();
    g = new GroundFloor();
    f = new Firstfloor_general();
    c = new firstfloor_credit();
    o = new SecondFloorOther();
    s = new SecondFloor();
    t = new ThirdFloor();
    ui->centralStackedWidget->addWidget(u);//1 underground
    ui->centralStackedWidget->addWidget(g);//2 ground
    ui->centralStackedWidget->addWidget(f);//3 first general
    ui->centralStackedWidget->addWidget(c);//4 first credit
    ui->centralStackedWidget->addWidget(s);//5 second
    ui->centralStackedWidget->addWidget(o);//6 second other
    ui->centralStackedWidget->addWidget(t);//7 third
    ui->full->hide();
<<<<<<< HEAD

    genedyBuilding =
    {
        {"HP Lab", true},
        {"Class 4", true},
        {"CIS Lab 1", true},
        {"CIS Lab 2", true},
        {"CIS Lab 3", true},
        {"CIS Lab 4", true},
        {"CIS Lab 5", true},
        {"CIS Lab 6", true},
        {"CIS Lab 7", true},
        {"Physics Lab", true},
    };

    for (const auto& pair : db.locations) {
        roomsList.push_back(QString::fromStdString(pair.first));
    }
    for (const auto& pair : genedyBuilding) {
        roomsList.push_back(QString::fromStdString(pair.first));
    }

    ui->start_list_widget->addItems(roomsList);
    ui->end_list_widget->addItems(roomsList);

    ui->start_list_widget->hide();
    ui->end_list_widget->hide();
=======
    g_stack = ui->centralStackedWidget;
>>>>>>> GUI_Graph
}

UserView::~UserView()
{
    delete Database::underGroundFloorTable;
    delete Database::firstCreditTable;
    delete Database::firstGeneralTable;
    delete Database::groundFloorTable;
    delete Database::second1Table;
    delete Database::second2Table;
    delete Database::thirdFloorTable;
    delete g_stack;
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

<<<<<<< HEAD
////////////////////////////////// Graph Page //////////////////////////////////

// to show rooms list
void UserView::on_search_start_selectionChanged()
{
    ui->start_list_widget->show();
}

void UserView::on_search_end_selectionChanged()
{
    ui->end_list_widget->show();
}


// filter rooms based on input
void UserView::on_search_start_textChanged(const QString &arg1)
{
    QRegularExpression regex(arg1, QRegularExpression::CaseInsensitiveOption);
    ui-> start_list_widget -> clear();
    ui -> start_list_widget -> addItems(roomsList.filter(regex));
}

void UserView::on_search_end_textChanged(const QString &arg1)
{
    QRegularExpression regex(arg1, QRegularExpression::CaseInsensitiveOption);
    ui-> end_list_widget -> clear();
    ui -> end_list_widget -> addItems(roomsList.filter(regex));
}


// get start and end rooms from what the user selected
void UserView::on_start_list_widget_itemClicked(QListWidgetItem *item)
{
    string chosenRoom =item->data(Qt::DisplayRole).toString().toStdString();;

    if (db.locations.find(chosenRoom) != db.locations.end())
    {
        startRoom = db.locations[chosenRoom];
    }
    else if (genedyBuilding.find(chosenRoom) != genedyBuilding.end())
    {
        QMessageBox::warning(this, "Error", "You're in Genedy, Go to the Main Building.");
        startRoom = db.locations["Class 7"];
    }
}


void UserView::on_end_list_widget_itemClicked(QListWidgetItem *item)
{
    string chosenRoom =item->data(Qt::DisplayRole).toString().toStdString();;

    if (db.locations.find(chosenRoom) != db.locations.end())
    {
        endRoom = db.locations[chosenRoom];
    }
    else if (genedyBuilding.find(chosenRoom) != genedyBuilding.end())
    {
        QMessageBox::warning(this, "Error", "Your destination is in Genedy Building.");
        endRoom = db.locations["Class 7"];
    }
}




=======

void UserView::on_underground_start_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(1);
}


void UserView::on_ground_start_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(2);
}


void UserView::on_first_start_clicked()
{
    BuildingChoose choice;
    choice.setModal(true);
    choice.exec();
    if (BuildingChoose::right)
        ui->centralStackedWidget->setCurrentIndex(3);
    else if (BuildingChoose::left)
        ui->centralStackedWidget->setCurrentIndex(4);
    else
        QMessageBox::warning(this, "Error", "Please Select a half!");
}


void UserView::on_third_start_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(7);
}


void UserView::on_second_start_clicked()
{
    BuildingChoose choice;
    choice.setModal(true);
    choice.exec();
    if (BuildingChoose::right)
        ui->centralStackedWidget->setCurrentIndex(5);
    else if (BuildingChoose::left)
        ui->centralStackedWidget->setCurrentIndex(6);
    else
        QMessageBox::warning(this, "Error", "Please Select a half!");
}

void UserView::on_underground_end_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(1);
}


void UserView::on_ground_end_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(2);
}


void UserView::on_first_end_clicked()
{
    BuildingChoose choice;
    choice.setModal(true);
    choice.exec();
    if (BuildingChoose::right)
        ui->centralStackedWidget->setCurrentIndex(3);
    else if (BuildingChoose::left)
        ui->centralStackedWidget->setCurrentIndex(4);
    else
        QMessageBox::warning(this, "Error", "Please Select a half!");
}


void UserView::on_third_end_clicked()
{
    ui->centralStackedWidget->setCurrentIndex(7);
}


void UserView::on_second_end_clicked()
{
    BuildingChoose choice;
    choice.setModal(true);
    choice.exec();
    if (BuildingChoose::right)
        ui->centralStackedWidget->setCurrentIndex(5);
    else if (BuildingChoose::left)
        ui->centralStackedWidget->setCurrentIndex(6);
    else
        QMessageBox::warning(this, "Error", "Please Select a half!");
}

void UserView::on_pushButton_4_clicked()
{
    Navigation *navigator = new Navigation(nullptr);
    navigator->show();
}

>>>>>>> GUI_Graph
