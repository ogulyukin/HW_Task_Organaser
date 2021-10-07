#ifndef TASLLIST_H
#define TASLLIST_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QColorDialog>
#include "io.h"
#include "priority.h"
#include "setcolorsdialog.h"
#include "taskadddialog.h"
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui { class TaslList; }
QT_END_NAMESPACE

class TaslList : public QMainWindow
{
    Q_OBJECT

public:
    TaslList(QWidget *parent = nullptr);
    ~TaslList();

private slots:
    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_Qt_triggered();

    void on_addTaskButton_clicked();

    void on_removeTaskButton_clicked();

    void on_priorityButton_clicked();

    void on_statusButton_clicked();

    void on_editTaskButton_clicked();

    void on_action_7_triggered();

private:
    Ui::TaslList *ui;
    QMultiMap<int, Task*> tasks;
    QList<Priority> priorities;
    void setTableWidget();
    QString statuses[3]{"Не определен", "Выполнено", "В работе"};
};
#endif // TASLLIST_H
