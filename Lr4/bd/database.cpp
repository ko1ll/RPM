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
    query.exec(" CREATE TABLE '"+table+"' ('Name' TEXT UNIQUE,'LastName' TEXT UNIQUE, PRIMARY KEY(Name,LastName));");

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
        } else return;
        if (result.next()){
            inName = result.value(0).toString();
            inLastName = result.value(1).toString();
            emit up_date(result.value(0).toString(),result.value(1).toString(),QString::number(countmin),QString::number(countmax));
        };
        break;};
    case 1:{
        //Prev
        if(countmin != 1){
        countmin--;
        } else return;
        if (result.previous()){
            inName = result.value(0).toString();
            inLastName = result.value(1).toString();
            emit up_date(result.value(0).toString(),result.value(1).toString(),QString::number(countmin),QString::number(countmax));
        };
        break;};
    case 2:{
        //Update
        QSqlQuery count;
        qInfo() << count.exec("select count(*) from " + inUse);
        if(count.next()){
            countmax =  count.value(0).toInt();
            countmin = 1;
        }

        qInfo() << count.exec("select * from " + inUse);
        result = count;
        if (result.next()){
            inName = result.value(0).toString();
            inLastName = result.value(1).toString();
            emit up_date(result.value(0).toString(),result.value(1).toString(),QString::number(countmin),QString::number(countmax));
        } else emit up_date("","",0,0);;
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
    qInfo() << del.exec("delete from "+inUse+" where Name = '"+inName+"' and LastName = '"+inLastName+"';");
    if(countmin != 1){
    countmin--;
    }
    update(whatisnext::now);
}

void DataBase::updated(const QString& first,const QString& second)
{
    QSqlQuery up;
    qInfo() << up.exec("update df set Name = '"+first+"', LastName = '"+second+"' where Name = '"+inName+"' and LastName = '"+inLastName+"';");
    update(whatisnext::now);
}
