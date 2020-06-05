#ifndef MIDDLEVALUE_H
#define MIDDLEVALUE_H

#include <QObject>
#include <QThread>
#include <QVector>
class MiddleValue : public QThread
{
    Q_OBJECT
public:
    explicit MiddleValue(QObject *parent = nullptr);
    QList<int> returnValues(QVector<int>);
    virtual ~MiddleValue();
    QList<int> retrunBuff(QVector<int> vec);
private:
    QList<int> buff;

};

#endif // MIDDLEVALUE_H
