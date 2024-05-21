#include "floortransition.h"
#include "ui_floortransition.h"

FloorTransition::FloorTransition(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FloorTransition)
{
    ui->setupUi(this);
    //ui->pushButton->setVisible(true);
    // ui->transitionLabel->setVisible(false);
    // ui->bg->setVisible(false);
    //startAnimation();

}

FloorTransition::~FloorTransition()
{
    delete ui;
}

void FloorTransition::startAnimation()
{
    QMovie *GifAnimation = new QMovie("E:/projects/Data_Structures/WranaSection/All_Materials/download.gif");
    ui->transitionLabel->setMovie(GifAnimation);
    ui->transitionLabel->raise();
    GifAnimation->start();

    ui->pushButton->setVisible(false);
    ui->transitionLabel->setVisible(true);
    ui->bg->setVisible(true);
    ui->progressBar->setVisible(true);
    ui->progressBar->setValue(0);

    for (int i =0;i<=100;i++)
    {
        ui->progressBar->setValue(i);
        qApp->processEvents(QEventLoop::AllEvents);
        QThread::msleep(30); //adjusts speed
    }
}


void FloorTransition::on_pushButton_clicked()
{
    QMovie *GifAnimation = new QMovie("D:/Downloads/walking.gif");
    ui->transitionLabel->setMovie(GifAnimation);
    ui->bg->setVisible(true);
    ui->transitionLabel->setVisible(true);
    ui->transitionLabel->raise();
    GifAnimation->start();

    for (int i =0;i<=100;i++)
    {
        ui->progressBar->setValue(i);
        qApp->processEvents(QEventLoop::AllEvents);
        QThread::msleep(50);
    }

}

