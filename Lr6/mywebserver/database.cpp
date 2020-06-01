#include "database.h"

DataBase::DataBase(QObject *parent,const QString& name) : QObject(parent)
{
    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase(name);
    db->setDatabaseName("base.sqlite");
    db->open();
    db->exec("CREATE TABLE msges ('msg' TEXT, 'id' INTEGER PRIMARY KEY AUTOINCREMENT);");
}
QSqlDatabase DataBase::Base()
{
    return *db;
}

bool DataBase::insert(const QString& msg)
{
    QSqlQuery query;
    return query.exec("INSERT INTO msges(msg) VALUES('"+msg+"');");
}


QList<QString> DataBase::lastTen()
{
     QSqlQuery query;
     QList<QString> list;
     qInfo() << query.exec("SELECT * FROM msges ORDER BY id DESC LIMIT 10");
     while(query.next()){
         list.push_back(query.value(0).toString());
     }
     return list;
}
