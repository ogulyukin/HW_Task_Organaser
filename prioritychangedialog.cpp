#include "prioritychangedialog.h"
#include "ui_prioritychangedialog.h"

priorityChangeDialog::priorityChangeDialog(QList<Priority>* priorities, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::priorityChangeDialog), priorities(priorities)
{
    ui->setupUi(this);
    for(auto it = priorities->begin(); it != priorities->end(); it++)
    {
        ui->comboBox->addItem(it->name);
    }
}

priorityChangeDialog::~priorityChangeDialog()
{
    delete ui;
}

Priority priorityChangeDialog::getNewPriority()
{
    for(auto it = priorities->begin(); it != priorities->end(); it++)
    {
        if(it->name == ui->comboBox->currentText())
        {
            return *it;
        }
    }
    return priorities->at(0);
}

void priorityChangeDialog::on_saveButton_clicked()
{
    accept();
}


void priorityChangeDialog::on_cancesButton_clicked()
{
    reject();
}

