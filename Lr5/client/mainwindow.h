/**
* @file mainwindow.h
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
private:
    Ui::MainWindow *ui;
    //Пользователь
    QTcpSocket* user;
    //Ник пользователя и IP сервера
    QString nickName,hostIP;
    //Порт сервера
    int hostPort;
};
#endif // MAINWINDOW_H
