#include "massive.h"
Massive::Massive(QObject *parent) :
    QThread(parent)
{
    vector.resize(size);
    QRandomGenerator *gen = new QRandomGenerator();
    std::generate(vector.begin(), vector.end(), [&]() {
        return gen->bounded(-500000,500000);
    });
    gen->~QRandomGenerator();
}

QVector<int> Massive::returnMassive()
{

    return {vector.begin(), vector.end()};
}

void Massive::run()
{
    for (int i = size - 1; i > 0; --i){
        for (int j = 0; j < i; ++j){
            if (vector[j] > vector[j + 1]){
                std::swap(vector[j],vector[j+1]);
            }
        }
    }
}
/*

*/
