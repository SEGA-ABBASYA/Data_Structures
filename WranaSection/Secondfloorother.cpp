#include "Secondfloorother.h"
#include "ui_Secondfloorother.h"
#include "database.h"
#include "User_View.h"


SecondFloorOther::SecondFloorOther(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecondFloorOther)
{
    ui->setupUi(this);
    Database::second2Table = ui->SecondF_widget_2;

    for(int i = 0; i < 67; i++){
        for(int j = 0; j < 85; j++) if(Database::SecondOtherFloor[i][j] == '+'){
                ui->SecondF_widget_2->setItem(i, j, new QTableWidgetItem());
                ui->SecondF_widget_2->item(i, j)->setFlags(Qt::NoItemFlags);
            }
        // qDebug() << second[i] << '\n';
    }
    ui->verticalLayoutWidget->hide();
}


SecondFloorOther::~SecondFloorOther()
{
    delete ui;
}

void SecondFloorOther::on_SecondF_widget_2_cellActivated(int row, int column)
{
    cout<<row<<" "<<column<<endl;
void SecondFloorOther::on_menuButton_toggled()
{
    ui->verticalLayoutWidget->show();
    ui->menuButton->hide();
}


void SecondFloorOther::on_menuButton_3_toggled()
{
    ui->verticalLayoutWidget->hide();
    ui->menuButton->show();
}


void SecondFloorOther::on_nextButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(UserView::g_stack->currentIndex() + 1);
}


void SecondFloorOther::on_previousButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(UserView::g_stack->currentIndex() - 1);
}


void SecondFloorOther::on_backButton_2_clicked()
{
    UserView::g_stack->setCurrentIndex(0);
}

