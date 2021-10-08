#include "taskadddialog.h"
#include "ui_taskadddialog.h"

taskAddDialog::taskAddDialog(QList<Priority>& priorities, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::taskAddDialog), priorities(priorities)
{
    ui->setupUi(this);
    for(auto it = priorities.begin(); it != priorities.end(); it++)
    {
        ui->comboBox->addItem(it->name);
    }
    ui->dateEdit->setDate(QDate::currentDate());
}

taskAddDialog::taskAddDialog(Task &task, QList<Priority> &priorities, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::taskAddDialog), priorities(priorities)
{
    ui->setupUi(this);
    for(auto it = priorities.begin(); it != priorities.end(); it++)
    {
        ui->comboBox->addItem(it->name);
    }
    ui->dateEdit->setDate(QDate::currentDate());
    ui->lineEdit->text() = task.nameTask;
    //ui->dateEdit->date() = QDate(); //todo conversion to QDate from QString
}

taskAddDialog::~taskAddDialog()
{
    delete ui;
}

QString taskAddDialog::getTaskName()
{
    return ui->lineEdit->text();
}

QString taskAddDialog::getTimeOut()
{
    return ui->dateEdit->date().toString();
}

int taskAddDialog::getPriorityId()
{
    for(auto it = priorities.begin(); it != priorities.end(); it++)
    {
        if (it->name == ui->comboBox->currentText())
            return it->id;
    }
    return 0;
}

void taskAddDialog::on_saveButton_clicked()
{
    accept();
}


void taskAddDialog::on_cancelButton_clicked()
{
    reject();
}

