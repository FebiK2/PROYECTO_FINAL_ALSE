#include "inventory_manager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    inventory_manager w;
    w.show();
    return a.exec();
}
