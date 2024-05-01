#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // ui->icon_name_widget_2->)
   // ui->icon_name_widget_2->auz;
 //  ui->icon_name_widget_2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

MainWindow::~MainWindow()
{
    delete ui;
}


