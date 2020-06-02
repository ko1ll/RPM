#include "piaint.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    piaint w;
    w.show();
    return a.exec();
}
