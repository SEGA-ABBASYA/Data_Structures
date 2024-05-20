#include "Navigation.h"
#include "ui_Navigation.h"
#include "database.h"
#include "User_View.h"
#include <QColor>

Navigation::Navigation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Navigation)
{
    ui->setupUi(this);
}

Navigation::~Navigation()
{
    delete ui;
}

void Navigation::intializeVector()
{
    floorsTables.push_back(Database::underGroundFloorTable);//0
    floorsTables.push_back(Database::groundFloorTable);//1
    floorsTables.push_back(Database::firstCreditTable);//2
    floorsTables.push_back(Database::firstGeneralTable);//3
    floorsTables.push_back(Database::second2Table);//4
    floorsTables.push_back(Database::second1Table);//5
    floorsTables.push_back(Database::thirdFloorTable);//6
}

void Navigation::navigate()
{
    //Graph
    //Underground 0
    //Ground 1
    //First 2
    //Second 3
    //Third 4

    intializeVector();
    int startX, endX, startY, endY, startF, endF;
    startX = 23;
    startY = 12;
    startF = 1;
    endX = 26;
    endY = 49;
    endF = 1;
    //Floor, Occupied, Name, End Nodes
    //Location end(endF, false, "Navigation", {endX, endY});//end
    //Floor, Path X, Path Y                                        Floor, Start Nodes, End Location
    vector<pair<int, pair<int, int>>> ans = Database::mg.SearchBig(UserView::startRoom.getFloor(), UserView::startRoom.getNode().first, UserView::startRoom.getNode().second, UserView::endRoom);//start
    steps = ans.size();
    ui->steps->setText( QString::fromStdString(std::to_string(steps)));
    for (auto i : ans)
    {
        if (i.first == 0 || i.first == 1 || i.first == 4)
        {
            if (i.first == 0 || i.first == 1)
            {
                floorsTables[i.first]->setItem(i.second.first, i.second.second, new QTableWidgetItem);
                floorsTables[i.first]->item(i.second.first, i.second.second)->setBackground(Qt::green);

                moving.push({i.first,{i.second.first, i.second.second}});
                cout << moving.back().first << ' ' << moving.back().second.first << ' ' << moving.back().second.second << endl;
            }
            else
            {
                floorsTables[6]->setItem(i.second.first, i.second.second, new QTableWidgetItem);
                floorsTables[6]->item(i.second.first, i.second.second)->setBackground(Qt::green);
                //cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
                moving.push({6,{i.second.first, i.second.second}});
            }
        }
        else if (i.first == 2)
        {
            //first Floor
            if (i.second.second >= 51)
            {
                floorsTables[3]->setItem(i.second.first, i.second.second - 42, new QTableWidgetItem);
                floorsTables[3]->item(i.second.first, i.second.second - 42)->setBackground(Qt::green);
                //cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
                moving.push({3,{i.second.first, i.second.second}});
            }
            else
            {
                floorsTables[i.first]->setItem(i.second.first, i.second.second, new QTableWidgetItem);
                floorsTables[i.first]->item(i.second.first, i.second.second)->setBackground(Qt::green);
                //cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
                moving.push({i.first,{i.second.first, i.second.second}});
            }
        }
        else
        {
            //second Floor
            if (i.second.second >= 84)
            {
                if (i.second.second >= 84 && i.second.second <= 88)
                    continue;
                floorsTables[5]->setItem(i.second.first - 20, i.second.second - 85, new QTableWidgetItem);
                floorsTables[5]->item(i.second.first - 20, i.second.second - 85)->setBackground(Qt::green);
                //cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
                moving.push({5,{i.second.first, i.second.second}});
            }
            else
            {
                if(i.second.second >= 81)
                    continue;
                floorsTables[4]->setItem(i.second.first, i.second.second, new QTableWidgetItem);
                floorsTables[4]->item(i.second.first, i.second.second)->setBackground(Qt::green);
                //cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
                moving.push({4,{i.second.first, i.second.second}});
            }
        }

    }
}

void Navigation::on_pushButton_clicked()
{
    navigate();
}


void Navigation::on_bysteps_clicked()
{
    if(!moving.empty()){
       int top = moving.front().first;
       pair<int, int> node = moving.front().second;
       UserView::g_stack->setCurrentIndex(top + 1);
       moving.pop();
       if(moving.size() > 2)
       {
           if(moving.front().first != top)
               UserView::g_stack->setCurrentIndex(top + 1);
           if (moving.front().first == 0 || moving.front().first == 1 || moving.front().first == 4)
           {
               if (moving.front().first == 0 || moving.front().first == 1)
               {
                   floorsTables[moving.front().first]->setItem(moving.front().second.first, moving.front().second.second, new QTableWidgetItem);
                   floorsTables[moving.front().first]->item(moving.front().second.first, moving.front().second.second)->setBackground(Qt::black);
               }
               else
               {
                   floorsTables[6]->setItem(moving.front().second.first, moving.front().second.second, new QTableWidgetItem);
                   floorsTables[6]->item(moving.front().second.first, moving.front().second.second)->setBackground(Qt::black);
               }
           }
           else if (moving.front().first == 2 || moving.front().first == 3)
           {
               //first Floor
               if (moving.front().second.second >= 51)
               {
                   floorsTables[3]->setItem(moving.front().second.first, moving.front().second.second - 42, new QTableWidgetItem);
                   floorsTables[3]->item(moving.front().second.first, moving.front().second.second - 42)->setBackground(Qt::black);

               }
               else
               {
                   floorsTables[moving.front().first]->setItem(moving.front().second.first, moving.front().second.second, new QTableWidgetItem);
                   floorsTables[moving.front().first]->item(moving.front().second.first, moving.front().second.second)->setBackground(Qt::black);

               }
           }
           else
           {
               //second Floor
               if (moving.front().second.second >= 84)
               {
                   if (!moving.front().second.second >= 84 && !moving.front().second.second <= 88)
                   floorsTables[5]->setItem(moving.front().second.first - 20, moving.front().second.second - 85, new QTableWidgetItem);
                   floorsTables[5]->item(moving.front().second.first - 20, moving.front().second.second - 85)->setBackground(Qt::black);

               }
               else
               {
                   if(!moving.front().second.second >= 81)
                   floorsTables[4]->setItem(moving.front().second.first, moving.front().second.second, new QTableWidgetItem);
                   floorsTables[4]->item(moving.front().second.first, moving.front().second.second)->setBackground(Qt::black);

               }
           }
           if(!moving.empty())
            moving.pop();
           top = moving.front().first;
       }
    }
}

















