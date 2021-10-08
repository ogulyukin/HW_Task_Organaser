#ifndef TASKADDDIALOG_H
#define TASKADDDIALOG_H

#include <QDialog>
#include "priority.h"
#include "task.h"
namespace Ui {
class taskAddDialog;
}

class taskAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit taskAddDialog(QList<Priority>& priorities, QWidget *parent = nullptr);
    taskAddDialog(Task &task, QList<Priority>& priorities, QWidget *parent = nullptr);
    ~taskAddDialog();
    QString getTaskName();
    QString getTimeOut();
    int getPriorityId();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::taskAddDialog *ui;
    QList<Priority> priorities;
};

#endif // TASKADDDIALOG_H
