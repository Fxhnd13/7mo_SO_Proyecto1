#ifndef HOJA_H
#define HOJA_H

#include <semaphore.h>

class Hoja
{
public:
    Hoja(int,int,int);
    ~Hoja();
    void setSemaforoPadre(sem_t& semPadre);
    void iniciarEspera();

private:
    int tallo, rama, hoja;
    sem_t semPadre;
};

#endif // TALLO_H