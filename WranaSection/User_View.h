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

    void on_search_start_textChanged(const QString &arg1);

    void on_search_end_textChanged(const QString &arg1);

    void on_start_list_widget_itemClicked(QListWidgetItem *item);

    void on_end_list_widget_itemClicked(QListWidgetItem *item);

    void on_search_start_selectionChanged();

    void on_search_end_selectionChanged();

private:
    Ui::UserView *ui;
    unordered_map<string, bool> genedyBuilding;
    QStringList roomsList;

};

#endif // USER_VIEW_H
