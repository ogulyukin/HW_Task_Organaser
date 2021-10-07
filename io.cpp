#include "io.h"

bool IO::loadData(QMultiMap<int, Task*> &tasks, QList<Priority> &priorities)
{
    QFile file("tasks.dat");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Невозможно открыть файл с тасками!";
            return false;
        }
        QTextStream istr(&file);
        QString line = istr.readLine();
        while(!line.isNull())
        {
            qDebug() << line;
            if (line != "")
            {
                QList<QString> list;
                list = (line.split(";"));
                Task* task = new Task(list.at(1),list.at(2),list.at(3),list.at(4));
                tasks.insert(list.at(0).toInt(), task);
            }
            line = istr.readLine();
        }
        file.close();
        file.setFileName("priority.dat");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Невозможно открыть файл с приоритетами!";
            return false;
        }
        QTextStream istr2(&file);
        line = istr2.readLine();
        while(!line.isNull())
        {
            qDebug() << line;
            if (line != "")
            {
                QList<QString> list;
                list = (line.split(";"));
                Priority* priority = new Priority(list.at(0).toInt(),list.at(1),QColor(list.at(2)));
                priorities.append(*priority);
            }
            line = istr2.readLine();
        }
        file.close();
    return true;
}

bool IO::saveData(QMultiMap<int, Task*> &tasks, QList<Priority> &priorities)
{
    QFile file("tasks.dat");
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text))
    {
        qDebug() << "Не открывается файл с тасками";
        return false;
    }
    QTextStream ostr(&file);
    for(auto it = tasks.begin(); it != tasks.end(); it++){
        ostr << it.key() << ";" << it.value()->nameTask << ";" << it.value()->dateIn << ";" << it.value()->timeIn
             << ";" << it.value()->dateOut << ";" << QString::number(it.value()->status) << Qt::endl;
    }
    ostr.flush();
    file.close();
    file.setFileName("priority.dat");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Не открывается файл с приоритетами";
        return false;
    }
    ostr.flush();
    for(auto it = priorities.begin(); it != priorities.end(); it++)
    {
        ostr << it->id << ";" << it->name << ";" << it->color.name() << ";" << Qt::endl;
    }
    ostr.flush();
    file.close();
    return true;
}
