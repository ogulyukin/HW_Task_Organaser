#ifndef IO_H
#define IO_H

#include <QDebug>
#include <QString>
#include <QMultiMap>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QList>
#include "task.h"
#include "priority.h"
class IO
{
public:
    static int loadData(QMultiMap<int, Task*>& tasks, QList<Priority>& priorities);
    static bool saveData(QMultiMap<int, Task*>& tasks, QList<Priority>& priorities);
};

#endif // IO_H
