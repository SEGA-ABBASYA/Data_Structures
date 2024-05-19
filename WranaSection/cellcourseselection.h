#ifndef CELLCOURSESELECTION_H
#define CELLCOURSESELECTION_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class CellCourseSelection;
}

class CellCourseSelection : public QDialog
{
    Q_OBJECT

public:
    explicit CellCourseSelection(QWidget *parent = nullptr);
    ~CellCourseSelection();

private slots:
    void on_Exit_clicked();

    void on_CoursesList_itemPressed(QListWidgetItem *item);

    //void on_CoursesList_itemClicked(QListWidgetItem *item);

private:
    Ui::CellCourseSelection *ui;
};

#endif // CELLCOURSESELECTION_H
