/**
* @file database.h
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/
#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
enum whatisnext{
    next,prev,now
};
class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr,const QString& d = "QMYSQL");

public slots:

    QSqlDatabase Base();
    //Смена таблицы
    void useTable(const QString&);
    //Обновление
    void update(const whatisnext&);
    //Вставка
    void insert(const QString&,const QString&);
    //Next
    void next();
    //Prev
    void prev();
    //Del
    void del();
private:
     QSqlDatabase* db;
     QString inUse;
     int countmin = 1,countmax;
signals:
     void up_date(QString,QString,QString,QString);
     void SetResult(QString);

};

#endif // DATABASE_H
