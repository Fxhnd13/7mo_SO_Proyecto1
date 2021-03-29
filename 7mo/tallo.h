#ifndef TALLO_H
#define TALLO_H

#include <QVector>
#include "pipe.h"

class Tallo
{
public:
    Tallo();
    Tallo(int,int,QVector<Pipe>);
    Tallo(int,int,int);
    ~Tallo();
    int getRamas();
    int getHojas();
    void setRamas(int);
    void setHojas(int);
    QVector<Pipe> getPipes();
    void setPipes(QVector<Pipe>);

private:
    int idTallo,ramas, hojas;
    QVector<Pipe> pipes;
};

#endif // TALLO_H
