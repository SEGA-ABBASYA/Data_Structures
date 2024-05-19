#ifndef USER_VIEW_H
#define USER_VIEW_H
#include <QList>
#include <QWidgetItem>
#include <QListWidgetItem>
#include <QWidget>
#include <unordered_map>
#include <string>
#include <database.h>
#include <QRegularExpression>
#include <Location.h>
using namespace std;
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
>>>>>>> GUI_Graph

namespace Ui {
class UserView;
}

class UserView : public QWidget
{
    Q_OBJECT

public:
    Database db;
    static Location startRoom;
    static Location endRoom;

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
>>>>>>> GUI_Graph
    explicit UserView(QWidget *parent = nullptr);
    void RefreshTable();
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

    void on_Schedule_cellDoubleClicked(int row, int column);
    void on_listWidget_itemPressed(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_DM_clicked();

<<<<<<< HEAD
    void on_search_start_textChanged(const QString &arg1);

    void on_search_end_textChanged(const QString &arg1);

    void on_start_list_widget_itemClicked(QListWidgetItem *item);

    void on_end_list_widget_itemClicked(QListWidgetItem *item);

    void on_search_start_selectionChanged();

    void on_search_end_selectionChanged();
=======
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
    void on_pushButton_4_clicked();

private:
    Ui::UserView *ui;
    unordered_map<string, bool> genedyBuilding;
    QStringList roomsList;

};

#endif // USER_VIEW_H
