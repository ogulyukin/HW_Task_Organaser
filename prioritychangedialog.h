#ifndef PRIORITYCHANGEDIALOG_H
#define PRIORITYCHANGEDIALOG_H

#include <QDialog>
#include "priority.h"

namespace Ui {
class priorityChangeDialog;
}

class priorityChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit priorityChangeDialog(QList<Priority>* priorities, QWidget *parent = nullptr);
    ~priorityChangeDialog();
    Priority getNewPriority();

private slots:
    void on_saveButton_clicked();

    void on_cancesButton_clicked();

private:
    Ui::priorityChangeDialog *ui;
    QList<Priority>* priorities;
};

#endif // PRIORITYCHANGEDIALOG_H
