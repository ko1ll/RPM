/**
* @file main.cpp
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
