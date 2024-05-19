#include "Navigation.h"
#include "ui_Navigation.h"
#include "database.h"

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
    startX = 26;
    startY = 63;
    startF = 2;
    endX = 21;
    endY = 29;
    endF = 2;
    //Floor, Occupied, Name, End Nodes
    Location end(endF, false, "Navigation", {endX, endY});//end
    //Floor, Path X, Path Y                                        Floor, Start Nodes, End Location
    vector<pair<int, pair<int, int>>> ans = Database::mg.SearchBig(startF, startX, startY, end);//start
    steps = ans.size();
    for (auto i : ans)
    {
        if (i.first == 0 || i.first == 1 || i.first == 4)
        {
            if (i.first == 0 || i.first == 1)
            {
                floorsTables[i.first]->setItem(i.second.first, i.second.second, new QTableWidgetItem);
                floorsTables[i.first]->item(i.second.first, i.second.second)->setBackground(Qt::green);
                cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
                moving.push({i.first,{i.second.first, i.second.second}});
            }
            else
            {
                floorsTables[6]->setItem(i.second.first, i.second.second, new QTableWidgetItem);
                floorsTables[6]->item(i.second.first, i.second.second)->setBackground(Qt::green);
                cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
                moving.push({i.first,{i.second.first, i.second.second}});
            }
        }
        else if (i.first == 2)
        {
            //first Floor
            if (i.second.second >= 51)
            {
                floorsTables[3]->setItem(i.second.first, i.second.second - 42, new QTableWidgetItem);
                floorsTables[3]->item(i.second.first, i.second.second - 42)->setBackground(Qt::green);
                cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
                moving.push({i.first,{i.second.first, i.second.second}});
            }
            else
            {
                floorsTables[i.first]->setItem(i.second.first, i.second.second, new QTableWidgetItem);
                floorsTables[i.first]->item(i.second.first, i.second.second)->setBackground(Qt::green);
                cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
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
                cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
                moving.push({i.first,{i.second.first, i.second.second}});
            }
            else
            {
                if(i.second.second >= 81)
                    continue;
                floorsTables[4]->setItem(i.second.first, i.second.second, new QTableWidgetItem);
                floorsTables[4]->item(i.second.first, i.second.second)->setBackground(Qt::green);
                cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
                moving.push({i.first,{i.second.first, i.second.second}});
            }
        }

    }
}

void Navigation::on_pushButton_clicked()
{
    navigate();
}

