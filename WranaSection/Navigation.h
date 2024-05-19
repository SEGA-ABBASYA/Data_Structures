#ifndef NAVIGATION_H
#define NAVIGATION_H
#include <vector>
#include <QDialog>
#include <QTableWidget>
#include <QVector>
#include <queue>
using namespace std;
namespace Ui {
class Navigation;
}

class Navigation : public QDialog
{
    Q_OBJECT

public:
    queue<pair<int, pair<int, int>>> moving;
    int steps;
    QVector<QTableWidget*> floorsTables;
    explicit Navigation(QWidget *parent = nullptr);
    void intializeVector();
    void navigate();
    ~Navigation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Navigation *ui;
};

#endif // NAVIGATION_H
