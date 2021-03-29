#ifndef TALLO_H
#define TALLO_H

#include "rama.cpp"
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

class Tallo
{
public:
    Tallo(int,int,int);
    Tallo();
    ~Tallo();
    void setSemaforoPadre(sem_t& semPadre);
    void crearRamas(int,int);
    void iniciarEspera();
    void agregarSemaforo(Rama&);
    void waitSemaforo(int);
    void postSemaforo(int);

private:
    int tallo, rama, hoja, hijos;
    sem_t semPadre;
    sem_t sem0,sem1,sem2,sem3,sem4;
    int pidHijos[10];
};

#endif // TALLO_H