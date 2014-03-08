#include "strangebrew.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StrangeBrew w;
    w.show();

    return a.exec();
}
