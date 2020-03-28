/**
* @file database.cpp
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/
#include "database.h"

DataBase::DataBase(QObject *parent,const QString& name) : QObject(parent)
{
    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase(name);
    db->setDatabaseName("base.sqlite");
    db->open();
}

QSqlDatabase DataBase::Base()
{
    return *db;
}

void DataBase::useTable(const QString& table)
{
    QSqlQuery query;
    inUse = table;
    query.exec(" CREATE TABLE '"+table+"' ('Name' TEXT,'LastName' TEXT ,'id' INTEGER PRIMARY KEY AUTOINCREMENT);");
    update(whatisnext::now);
    emit SetResult(table);
}

void DataBase::update(const whatisnext& value)
{
    switch (value) {
    case 0:{
        //Next
        if(countmin != countmax){
        countmin++;
        QSqlQuery count;
        qInfo() << count.exec("select Name,LastName from " + inUse +" where id = " + QString::number(countmin));
        if (count.next()){
            emit up_date(count.value(0).toString(),count.value(1).toString(),QString::number(countmin),QString::number(countmax));
        };
        }
        break;};
    case 1:{
        //Prev
        if(countmin != 1){
        countmin--;
        QSqlQuery count;
        qInfo() << count.exec("select Name,LastName from " + inUse +" where id = " + QString::number(countmin));
        if (count.next()){
            emit up_date(count.value(0).toString(),count.value(1).toString(),QString::number(countmin),QString::number(countmax));
        };
        }
        break;};
    case 2:{
        //Update
        QSqlQuery count;
        qInfo() << count.exec("select count(*) from " + inUse);
        count.next();
        countmax =  count.value(0).toInt();
        qInfo() << count.exec("select Name,LastName from " + inUse +" where id = " + QString::number(countmin));
        if (count.next()){
            emit up_date(count.value(0).toString(),count.value(1).toString(),QString::number(countmin),QString::number(countmax));
        };
        break;};
    }


}

void DataBase::insert(const QString& first, const QString& second)
{
    QSqlQuery insert("INSERT INTO "+inUse+"(Name,LastName) VALUES('"+first+"','"+second+"');");
    update(whatisnext::now);
}

void DataBase::next()
{
    update(whatisnext::next);
}


void DataBase::prev()
{
    update(whatisnext::prev);
}
void DataBase::del(){
    QSqlQuery del;
    qInfo() << del.exec("delete from " + inUse + " where id = " + QString::number(countmin));
    if(countmin != 1){
    countmin--;
    }
    update(whatisnext::now);
}
