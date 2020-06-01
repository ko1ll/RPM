#include "webserver.h"
#include <QWebSocket>
webserver::webserver(QObject *parent) :
    QWebSocketServer("MyServer",QWebSocketServer::SslMode::NonSecureMode,parent)
{
    connect(this,SIGNAL(newConnection()),this,SLOT(NextConnection()));
    connect(this,&QWebSocketServer::closed,[&](){
        for(const auto& item : listOfSockets){
            item->close();
        }
    });
}

void webserver::NextConnection(){
    auto user = nextPendingConnection();
    listOfSockets.push_back(user);

    //Прислать 10 сообщений из бд
    auto smth = bd->lastTen();
    std::reverse(smth.begin(),smth.end());
    for(const auto& item : (smth)){
        user->sendTextMessage(item);
    }
    connect(user,&QWebSocket::textMessageReceived,[&](const QString& msg){
        userAction(msg);
    });
    connect(user,&QWebSocket::stateChanged,[&](QAbstractSocket::SocketState state){
        if(state == QAbstractSocket::SocketState::UnconnectedState){
            std::for_each(listOfSockets.begin(),listOfSockets.end(),[&](QWebSocket* socket){
                if(socket->state() == QAbstractSocket::SocketState::UnconnectedState){
                    listOfSockets.removeOne(socket);
                }
            });
        }
    });
}

void webserver::userAction(const QString& msg){
     qInfo() << bd->insert(msg);
    for(const auto& item : listOfSockets){
        item->sendTextMessage(msg);
    }
}


