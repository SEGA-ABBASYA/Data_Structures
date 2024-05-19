#include "secondfloor.h"
#include "ui_secondfloor.h"
#include "database.h"
#include <QDebug>
#include "User_View.h"
using namespace::std;

SecondFloor::SecondFloor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecondFloor)
{
    ui->setupUi(this);
    Database::second1Table = ui->SecondF_widget;



    for(int i = 0; i < 47; i++){
        for(int j = 0; j < 76; j++) if(Database::SecondFloor[i][j] == '+'){
                ui->SecondF_widget->setItem(i, j, new QTableWidgetItem());
                ui->SecondF_widget->item(i, j)->setFlags(Qt::NoItemFlags);
            }
    }
    ui->verticalLayoutWidget->hide();
}

SecondFloor::~SecondFloor()
{
    delete ui;
}


void SecondFloor::on_SecondF_widget_cellActivated(int row, int column)
{
    cout<<row<<" "<<column<<endl;
}
void SecondFloor::on_menuButton_3_toggled()
{
    ui->verticalLayoutWidget->hide();
    ui->menuButton->show();
}


void SecondFloor::on_menuButton_toggled()
{
    ui->verticalLayoutWidget->show();
    ui->menuButton->hide();
}


void SecondFloor::on_backButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(0);
}


void SecondFloor::on_nextButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(UserView::g_stack->currentIndex() + 1);
}


void SecondFloor::on_previousButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(UserView::g_stack->currentIndex() - 1);
}

