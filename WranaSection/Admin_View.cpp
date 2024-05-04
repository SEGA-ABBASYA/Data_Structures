#include "Admin_View.h"
#include "ui_Admin_View.h"
#include <QGraphicsBlurEffect>

AdminView::AdminView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Test->setCheckable(true);
    ui->Full->hide();
    // QGraphicsBlurEffect* p_blur = new QGraphicsBlurEffect;
    // p_blur->setBlurRadius(3);
    // p_blur->setBlurHints(QGraphicsBlurEffect::QualityHint);

    //ui->Full->setGraphicsEffect(p_blur);
   // ui->icon_name_widget_2->)
   // ui->icon_name_widget_2->auz;
 //  ui->icon_name_widget_2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

AdminView::~AdminView()
{
    delete ui;
}

void AdminView::on_Test_toggled()
{

        ui->Icons->hide();
        ui->Full->show();

    // else{
    //     ui->Icons->show();
    //     ui->Full->hide();
    // }
}

void AdminView::on_Test_2_toggled()
{

        ui->Icons->show();
        ui->Full->hide();

    // else{
    //     ui->Icons->hide();
    //     ui->Full->show();
    // }
}


void AdminView::on_course_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminView::on_graph_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(1);
}


void AdminView::on_student_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(2);
}




void AdminView::on_schedule_icon_toggled(bool checked)
{
    ui->stackedWidget->setCurrentIndex(3);
}

