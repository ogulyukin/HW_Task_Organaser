#include "setcolorsdialog.h"
#include "ui_setcolorsdialog.h"

setColorsDialog::setColorsDialog(QList<Priority>* priorities, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setColorsDialog), priorities(priorities)
{
    ui->setupUi(this);
    setTableVidget();
}

setColorsDialog::~setColorsDialog()
{
    delete ui;
}

void setColorsDialog::on_addButton_clicked()
{
    addEditTaskDialog *dialog = new addEditTaskDialog(this);
    dialog->setModal(true);
    int ret = dialog->exec();
    if(ret == dialog->Accepted)
    {
        int mid = priorities->last().id + 1;
        Priority priority(mid, dialog->getChosenName(), dialog->getChosenColor());
        priorities->append(priority);
        setTableVidget();
    }
}


void setColorsDialog::on_editButton_clicked()
{
    int cRow = ui->tableWidget->currentRow();
    Priority tempPr = priorities->at(cRow);
    addEditTaskDialog *dialog = new addEditTaskDialog(tempPr.name, tempPr.color, this);
    dialog->setModal(true);
    int ret = dialog->exec();
    if(ret == dialog->Accepted)
    {
        auto it = priorities->begin();
        for(int i = 0; i < cRow; i++){
            it++;
        }
        it->name = dialog->getChosenName();
        it->color = dialog->getChosenColor();
        setTableVidget();
    }
}


void setColorsDialog::on_deleteButton_clicked()
{
    int cRow = ui->tableWidget->currentRow();
//    qDebug() << "CRow = " << cRow;
//    qDebug() << "priorities->count() = " << priorities->count();
    if(cRow > 0 && cRow < priorities->count())
    {
        priorities->removeAt(cRow);
    }
    setTableVidget();
}


void setColorsDialog::on_quitButton_clicked()
{
    this->close();
}

void setColorsDialog::setTableVidget()
{
    ui->tableWidget->clear();
    int count = 0;
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->setRowCount(priorities->count());
    for(auto it = priorities->begin(); it != priorities->end(); it++)
    {
        //ui->tableWidget->insertRow(count);
        ui->tableWidget->setItem(count, 0, new QTableWidgetItem(QString::number(it->id)));
        QTableWidgetItem* item = new QTableWidgetItem(it->name);
        item->setBackground(QBrush(it->color));
        ui->tableWidget->setItem(count, 1, item);
        count++;
    }
    QStringList list;
    list << "ID" << "Наименование";
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->resizeColumnsToContents();
}

