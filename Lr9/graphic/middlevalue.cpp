#include "middlevalue.h"

MiddleValue::MiddleValue(QObject *parent) :
    QThread(parent)
{
}

QList<int> MiddleValue::returnValues(QVector<int> vec)
{
 QList<int> smth;
 smth.reserve(500);
 for (int i = 0; i != 500000; i+=1000){
     smth.push_back(std::accumulate(vec.begin()+i,vec.begin()+i+1000,0)/1000);
 }
 return smth;
}

MiddleValue::~MiddleValue()
{

}
QList<int> MiddleValue::retrunBuff(QVector<int> vec){
    returnValues(vec);
    return buff;
}
