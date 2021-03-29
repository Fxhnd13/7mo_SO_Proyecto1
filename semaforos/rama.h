#ifndef RAMA_H
#define RAMA_H

#include "hoja.cpp"
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

class Rama
{
public:
    Rama(int,int,int);
    Rama();
    ~Rama();
    void setSemaforoPadre(sem_t& semPadre);
    void crearHojas(int);
    void iniciarEspera();
    void agregarSemaforo(Hoja&);
    void waitSemaforo(int);
    void postSemaforo(int);

private:
    int tallo, rama, hoja, hijos;
    sem_t semPadre;
    sem_t sem0,sem1,sem2,sem3,sem4,sem5,sem6,sem7,sem8,sem9;
    int pidHijos[10];
};

#endif // TALLO_H