#include "smartclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SmartClient w;
    w.show();

    return a.exec();
}
