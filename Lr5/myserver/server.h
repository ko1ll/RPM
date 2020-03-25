/**
* @file server.h
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/
#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
#include <QList>
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject* parent = nullptr);
private:
    //Сервер
    QTcpServer* server;
    //Пользователи
    QList<QTcpSocket*> users;
    //Сообщения
    QQueue<QString> msges;
private slots:
    void updateUsers(const QString&);
    void connectUser();
    void userAction();
};

#endif // SERVER_H
