#ifndef USER_VIEW_H
#define USER_VIEW_H
#include <QList>
#include <QWidgetItem>
#include <QListWidgetItem>
#include <QWidget>
#include <QStackedWidget>
#include "undergroundfloor.h"
#include "ThirdFloor.h"
#include "secondfloor.h"
#include "firstfloor_credit.h"
#include "firstfloor_general.h"
#include "Groundfloor.h"
#include "Secondfloorother.h"
#include "Secondfloorother.h"
#include "undergroundfloor.h"
#include <QStatusBar>
#include <QVBoxLayout>

namespace Ui {
class UserView;
}

class UserView : public QWidget
{
    Q_OBJECT

public:
    QVBoxLayout* layout;
    QStatusBar* statusBar;
    static QStackedWidget *g_stack;
    GroundFloor *g;
    UndergroundFloor *u;
    ThirdFloor *t;
    SecondFloor *s;
    Firstfloor_general *f;
    firstfloor_credit *c;
    SecondFloorOther *o;
    ThirdFloor *th;
    explicit UserView(QWidget *parent = nullptr);
    ~UserView();

private slots:
    void on_Swapfull_toggled();

    void on_Swapicons_toggled();

    void on_courseicons_toggled(bool checked);

    void on_graphicons_toggled(bool checked);

    void on_studenticons_toggled(bool checked);


    void on_scheduleicons_toggled(bool checked);

    void on_friendicons_toggled(bool checked);

    void on_notificationicons_toggled(bool checked);

    void on_pushButton_toggled(bool checked);

    void on_pushButton_2_toggled(bool checked);


    void on_logouticons_clicked();

    void on_logoutfull_clicked();

    void on_listWidget_itemPressed(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_DM_clicked();

    void on_underground_start_clicked();

    void on_ground_start_clicked();

    void on_first_start_clicked();

    void on_third_start_clicked();

    void on_second_start_clicked();

    void on_underground_end_clicked();

    void on_ground_end_clicked();

    void on_first_end_clicked();

    void on_third_end_clicked();

    void on_second_end_clicked();
private:
    Ui::UserView *ui;
};

#endif // USER_VIEW_H
