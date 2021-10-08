#ifndef TASK_H
#define TASK_H

#include <QString>

class Task
{
public:
    int id;
    QString nameTask;
    QString dateIn;
    QString timeIn;
    QString dateOut;
    int status;
    Task(int id, QString nameTask, QString dateIn, QString timeIn, QString dateOut, int status = 0);

};

#endif // TASK_H
