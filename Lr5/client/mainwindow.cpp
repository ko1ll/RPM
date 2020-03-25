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
    user = new QTcpSocket(this);

    connect(user, &QTcpSocket::readyRead,
         [&](){
         ui->textBrowser->append(user->readAll());
    });

    connect(ui->pushButton,&QPushButton::clicked,
            [&] () {
        qInfo() << user->write(("<"+nickName+">" +ui->lineEdit->text()).toUtf8());
    });
    connect(ui->Connect,&QPushButton::clicked,[&](){
        SetNickName b(this);
        if (b.exec() == QDialog::Accepted){
            user->connectToHost(b.ip(),b.port(),QTcpSocket::ReadWrite);
            if(user->waitForConnected(30000)) {
                  qInfo() << "Connected!";
                  qInfo() << user->peerAddress();
                  nickName = b.nick();
                  user->write(nickName.toUtf8()+" joined this chat");
              }

        } else return;

    });
    connect(ui->LogIn, &QPushButton::clicked, [&](){
        user->write(nickName.toUtf8()+" left this chat");
        user->disconnectFromHost();

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


