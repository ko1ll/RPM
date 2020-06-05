#ifndef MASSIVE_H
#define MASSIVE_H

#include <QVector>
#include <QObject>
#include <QRandomGenerator>
#include <QThread>
#include <QDebug>
class Massive : public QThread
{
    Q_OBJECT
public:
    explicit Massive(QObject *parent = nullptr);
    QVector<int> returnMassive();
private:
        QVector<int> vector;
        int size = 500000;

private slots:
    void run();


};

#endif // MASSIVE_H
