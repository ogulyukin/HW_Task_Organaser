#ifndef STATUSCHANGEDIALOG_H
#define STATUSCHANGEDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class statuschangeDialog;
}

class statuschangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit statuschangeDialog(QList<QString> *statuses, QWidget *parent = nullptr);
    ~statuschangeDialog();
    int getStatusId();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::statuschangeDialog *ui;
    QList<QString> *statuses;
};

#endif // STATUSCHANGEDIALOG_H
