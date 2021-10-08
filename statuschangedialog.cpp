#include "statuschangedialog.h"
#include "ui_statuschangedialog.h"

statuschangeDialog::statuschangeDialog(QList<QString> *statuses, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statuschangeDialog), statuses(statuses)
{
    ui->setupUi(this);
    qDebug() << statuses->count() << " " << statuses->size();
    for(int i = 0; i < statuses->count(); i++)
    {
        ui->comboBox->addItem(statuses->at(i));
    }
}

statuschangeDialog::~statuschangeDialog()
{
    delete ui;
}

int statuschangeDialog::getStatusId()
{
    for(int i = 0; i < statuses->size(); i++)
    {
        if(ui->comboBox->currentText() == statuses->at(i))
            return i;
    }
    return 0;
}

void statuschangeDialog::on_saveButton_clicked()
{
    accept();
}


void statuschangeDialog::on_cancelButton_clicked()
{
    reject();
}

