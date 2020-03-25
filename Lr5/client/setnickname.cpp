/**
* @file setnickname.cpp
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/
#include "setnickname.h"
#include "ui_setnickname.h"

SetNickName::SetNickName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetNickName)
{
    ui->setupUi(this);
}

SetNickName::~SetNickName()
{
    delete ui;
}


void SetNickName::on_pushButton_clicked()
{
    hostIP = ui->HostIpLine->text();
    hostPort = ui->hostPort->value();
    nickName = ui->NicknameLine->text();
    accept();
}
