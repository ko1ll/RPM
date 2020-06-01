/**
* @file mainwdindow.cpp
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setnickname.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    user = new QWebSocket();

    connect(user, &QWebSocket::textMessageReceived,
         [&](const QString& message){
         ui->textBrowser->append(message);
    });

    connect(ui->pushButton,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" +ui->lineEdit->text()).toUtf8());
    });

    connect(ui->Connect,&QPushButton::clicked,[&](){
        SetNickName b(this);
        if (b.exec() == QDialog::Accepted){
            user->open(QUrl("ws://" + b.ip() + ":" + b.port()));
            nickName = b.nick();
            qInfo() << "ws://" + b.ip() + ":" + b.port() + nickName;

            connect(user,&QWebSocket::stateChanged,[&](QAbstractSocket::SocketState state){
                 if(state == QAbstractSocket::SocketState::ConnectedState){
                    qInfo() << "Connected!";
                    qInfo() << user->peerAddress();
                    user->sendTextMessage(nickName.toUtf8()+" joined this chat");
                 }
            });

        } else return;

    });
    connect(ui->LogIn, &QPushButton::clicked, [&](){
        ui->textBrowser->append("You were disconnected");
        user->sendTextMessage(nickName.toUtf8()+" left this chat");
        user->close(QWebSocketProtocol::CloseCode::CloseCodeNormal," left this chat");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


