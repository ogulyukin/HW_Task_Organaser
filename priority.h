#ifndef PRIORITY_H
#define PRIORITY_H

#include <QString>
#include <QColor>

class Priority
{
public:
    int id;
    QString name;
    QColor color;
    Priority(int id, QString name, QColor color);
};

#endif // PRIORITY_H
