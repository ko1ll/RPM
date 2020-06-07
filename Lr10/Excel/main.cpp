#include "excelmain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    excelMain w;
    w.show();
    return a.exec();
}
