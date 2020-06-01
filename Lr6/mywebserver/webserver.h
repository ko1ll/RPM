#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QObject>
#include <QWebSocketServer>
#include "database.h"
class webserver : public QWebSocketServer
{
    Q_OBJECT
public:
    explicit webserver(QObject *parent = 0);
    void userAction(const QString&);
private:
    QList<QWebSocket*> listOfSockets;
    DataBase *bd = new DataBase(this,"QSQLITE");
    private slots:
    void NextConnection();

};

#endif // WEBSERVER_H
