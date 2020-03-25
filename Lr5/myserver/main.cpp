/**
* @file main.cpp
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/

#include <QCoreApplication>
#include <server.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server serv;
    return a.exec();
}
