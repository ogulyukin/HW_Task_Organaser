#ifndef ADDEDITTASKDIALOG_H
#define ADDEDITTASKDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class addEditTaskDialog;
}

class addEditTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addEditTaskDialog(QWidget *parent = nullptr);
    addEditTaskDialog(QString name, QColor color, QWidget *parent = nullptr);
    ~addEditTaskDialog();

    const QColor getChosenColor();

    const QString getChosenName();

private slots:
    void on_colorButton_clicked();

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::addEditTaskDialog *ui;
    QColor chosenColor;
    QString chosenName;
};

#endif // ADDEDITTASKDIALOG_H
