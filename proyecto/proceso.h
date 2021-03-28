#ifndef PROCESO_H
#define PROCESO_H

#include <semaphore.h>
#include <list>

class Proceso
{
public:
    Proceso(int,int,int);
    void iniciarEspera();
    void setPid(int);
    int getPid();

private:
    int pid,tallo,rama,hoja,color; //básicamente su identificador para el archivo de texto.
};

#endif // PROCESO_H
