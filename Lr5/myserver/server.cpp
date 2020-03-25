/**
* @file server.cpp
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/
#include "server.h"
#include <QObject>
#include <QDebug>
#include <QtAlgorithms>
Server::Server(QObject* parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection,this, &Server::connectUser);
    if (server->listen(QHostAddress::Any, 55887)) {
            qInfo() << "Server started";
        } else {
            qWarning() << "Unable to start server";
        }
}

void Server::updateUsers(const QString& msg)
{
    foreach(const QTcpSocket* socket, users){
    QTextStream((QTcpSocket*)socket ) << msg;
    };
}

void Server::connectUser()
{
    auto user = server->nextPendingConnection();
    users.push_back(user);
    QTextStream stream(user);
    for(const auto& item : msges){
        stream << item + "\n";
    }
    connect(user, &QTcpSocket::readyRead,this, &Server::userAction);
    connect(user,&QAbstractSocket::stateChanged,[&](QAbstractSocket::SocketState state) {
    if (state == QAbstractSocket::SocketState::UnconnectedState){
        users.erase(std::find_if(users.begin(),users.end(),[&](QTcpSocket* socket){
               return socket->socketDescriptor() == -1;
               }));
    }
    });
}

void Server::userAction()
{
    QTcpSocket* usermsg = (QTcpSocket*) sender();
    QString msg = QTextStream(usermsg).readAll();
    if(msges.size() == 10){
       msges.removeFirst()  ;
    }
    msges.push_back(msg);
    this->updateUsers(msg);
}
