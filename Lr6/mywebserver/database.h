#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr,const QString& d = "QMYSQL");
private:
     QSqlDatabase* db;
     QSqlQuery result;
public slots:
     QSqlDatabase Base();
     bool insert(const QString&);
     QList<QString> lastTen();
signals:

};

#endif // DATABASE_H
