#ifndef SETCOLORSDIALOG_H
#define SETCOLORSDIALOG_H

#include <QDialog>
#include <QDialog>
#include "priority.h"
#include "addedittaskdialog.h"
#include <QLabel>
#include <QTabWidget>

namespace Ui {
class setColorsDialog;
}

class setColorsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setColorsDialog(QList<Priority>* priorities, QWidget *parent = nullptr);
    ~setColorsDialog();

private slots:
    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_deleteButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::setColorsDialog *ui;
    QList<Priority>* priorities;
    void setTableVidget();
};

#endif // SETCOLORSDIALOG_H
