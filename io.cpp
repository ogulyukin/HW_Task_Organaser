#include "io.h"

int IO::loadData(QMultiMap<int, Task*> &tasks, QList<Priority> &priorities)
{
    QFile file("tasks.dat");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Невозможно открыть файл с тасками!";
            return 0;
        }
        QTextStream istr(&file);
        QString line = istr.readLine();
        int lastId = 0;
        while(!line.isNull())
        {
            qDebug() << line;
            if (line != "")
            {
                QList<QString> list;
                list = (line.split(";"));
                int foundId = list.at(0).toInt();
                Task* task = new Task(foundId,list.at(2),list.at(3),list.at(4), list.at(5));
                tasks.insert(list.at(1).toInt(), task);
                foundId > lastId ? lastId = foundId : 0;
            }
            line = istr.readLine();
        }
        file.close();
        file.setFileName("priority.dat");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Невозможно открыть файл с приоритетами!";
            return lastId;
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
    return lastId;
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
        ostr << QString::number(it.value()->id) << ";" << it.key() << ";" << it.value()->nameTask << ";" << it.value()->dateIn << ";" << it.value()->timeIn
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
