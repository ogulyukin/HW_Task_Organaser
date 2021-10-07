#include "tasllist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TaslList w;
    w.show();
    return a.exec();
}
