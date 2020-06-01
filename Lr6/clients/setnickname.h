/**
* @file setnickname.h
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/

#ifndef SETNICKNAME_H
#define SETNICKNAME_H

#include <QDialog>

namespace Ui {
class SetNickName;
}

class SetNickName : public QDialog
{
    Q_OBJECT

public:
    explicit SetNickName(QWidget *parent = nullptr);
    ~SetNickName();
    QString& ip(){
        return hostIP;
    }
    QString& nick(){
        return nickName;
    }
    QString& port(){
        return hostPort;
    }
private slots:

    void on_pushButton_clicked();

signals:
    void connectt();
private:
    Ui::SetNickName *ui;
    QString hostIP,nickName,hostPort;

};

#endif // SETNICKNAME_H
