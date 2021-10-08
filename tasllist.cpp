#include "tasllist.h"
#include "ui_tasllist.h"

TaslList::TaslList(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TaslList)
{
    ui->setupUi(this);
    IO::loadData(tasks, priorities);
    if(priorities.count() == 0)
    {
        Priority prior(0,"Не определена", Qt::white);
        priorities.append(prior);
    }
    statuses << "Не определен" << "Выполнено" << "В работе";
    setTableWidget();
}

TaslList::~TaslList()
{
    IO::saveData(tasks, priorities);
    delete ui;
}


void TaslList::on_action_triggered()
{
    priorities.clear();
    tasks.clear();
    IO::loadData(tasks, priorities);
    if(priorities.count() == 0)
    {
        Priority prior(0,"Не определена", Qt::white);
        priorities.append(prior);
    }
    setTableWidget();
}


void TaslList::on_action_2_triggered()
{
    bool result = IO::saveData(tasks, priorities);
    if (result)
    {
        QMessageBox::information(this, "Успех", "Задачи сохранены");
        return;
    }
    QMessageBox::information(this, "ОШИБКА", "Задачи сохраненить не удалось!");
}


void TaslList::on_action_5_triggered()
{
    this->close();
}


void TaslList::on_action_6_triggered()
{
    QMessageBox::about(this, "О Программе", "Гулюкин О.В. 2021 \nПрограмма планировщик задач");
}


void TaslList::on_action_Qt_triggered()
{
    QApplication::aboutQt();
}


void TaslList::on_addTaskButton_clicked()
{
    taskAddDialog* dialog = new taskAddDialog(priorities, this);
    int res = dialog->exec();
    if(res == dialog->Accepted)
    {
        qDebug() << " New task dialog Accepted";
        if(dialog->getTaskName() != "")
        {
            lastId++;
            Task* task = new Task(lastId, dialog->getTaskName(), QDate::currentDate().toString(), QTime::currentTime().toString(),
                      dialog->getTimeOut());
            tasks.insert(dialog->getPriorityId(), task);
            setTableWidget();
        }
    }
}

void TaslList::on_removeTaskButton_clicked()
{
    int cRow = ui->tableWidget->currentRow();
    int targetId = ui->tableWidget->itemAt(cRow, 0)->text().toInt();
    if(cRow >= 0 && cRow <= tasks.count())
    {
        qDebug() << "**************************************";
        qDebug() << ui->tableWidget->itemAt(cRow, 0)->text();
        for (auto it = tasks.begin(); it != tasks.end() ; it++)
        {
            if(it.value()->id == targetId)
            {
                tasks.remove(it.key(), it.value());
                setTableWidget();
                return;
            }
        }
    }
}


void TaslList::on_priorityButton_clicked()
{
    priorityChangeDialog* dialog = new priorityChangeDialog(&priorities, this);
    int ret = dialog->exec();
    if(ret == dialog->Accepted)
    {
        int cRow = ui->tableWidget->currentRow();
        int targetId = ui->tableWidget->itemAt(cRow, 0)->text().toInt();
        if(cRow >= 0 && cRow <= tasks.count())
        {
            qDebug() << "********priority change********";
            qDebug() << ui->tableWidget->itemAt(cRow, 0)->text();
            for (auto it = tasks.begin(); it != tasks.end() ; it++)
            {
                if(it.value()->id == targetId)
                {
                    Task* tempTask = it.value();
                    tasks.remove(it.key(),it.value());
                    tasks.insert(dialog->getNewPriority().id, tempTask);
                    setTableWidget();
                    return;
                }
            }
        }
    }
}


void TaslList::on_statusButton_clicked()
{
    statuschangeDialog* dialog = new statuschangeDialog(&statuses, this);
    int ret = dialog->exec();
    if(ret == dialog->Accepted)
    {
        int cRow = ui->tableWidget->currentRow();
        int targetId = ui->tableWidget->itemAt(cRow, 0)->text().toInt();
        if(cRow >= 0 && cRow <= tasks.count())
        {
            qDebug() << "********changing status********";
            qDebug() << ui->tableWidget->itemAt(cRow, 0)->text();
            for (auto it = tasks.begin(); it != tasks.end() ; it++)
            {
                if(it.value()->id == targetId)
                {
                    it.value()->status = dialog->getStatusId();
                    setTableWidget();
                    return;
                }
            }
        }
    }
}


void TaslList::on_editTaskButton_clicked()
{

}

void TaslList::setTableWidget()
{
    ui->tableWidget->clear();
    int count = 0;
    ui->tableWidget->setRowCount(tasks.count());
    ui->tableWidget->setColumnCount(7);
    for (auto it = tasks.begin(); it != tasks.end(); it++)
    {
        //ui->tableWidget->insertRow(count);
        QTableWidgetItem* item = new QTableWidgetItem(priorities.at(it.key()).name);
        item->setBackground(QBrush(priorities.at(it.key()).color));
        ui->tableWidget->setItem(count, 0, new QTableWidgetItem(QString::number(it.value()->id)));
        ui->tableWidget->setItem(count, 1, item);
        ui->tableWidget->setItem(count, 2, new QTableWidgetItem(it.value()->nameTask));
        ui->tableWidget->setItem(count, 3, new QTableWidgetItem(it.value()->dateIn));
        ui->tableWidget->setItem(count, 4, new QTableWidgetItem(it.value()->timeIn));
        ui->tableWidget->setItem(count, 5, new QTableWidgetItem(it.value()->dateOut));
        ui->tableWidget->setItem(count, 6, new QTableWidgetItem(statuses.at(it.value()->status)));
        count++;
    }
    QStringList list;
    list << "id" << "Важность" << "Содержание" << "Дата принятия" << "Время принятия" << "Дата испонения" << "Статус";
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->resizeColumnsToContents();
}


void TaslList::on_action_7_triggered()
{
    setColorsDialog* settings = new setColorsDialog(&priorities, this);
    settings->show();
}

