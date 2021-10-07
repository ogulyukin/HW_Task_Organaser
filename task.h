#ifndef TASK_H
#define TASK_H

#include <QString>

class Task
{
public:
    QString nameTask;
    QString dateIn;
    QString timeIn;
    QString dateOut;
    int status;
    Task(QString nameTask, QString dateIn, QString timeIn, QString dateOut, int status = 0);

};

#endif // TASK_H
