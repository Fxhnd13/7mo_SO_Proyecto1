#ifndef RAMA_H
#define RAMA_H

#include "hoja.cpp"

class Rama
{
public:
    Rama(int,int,int);
    ~Rama();
    void setSemaforoPadre(sem_t& semPadre);
    void crearHojas(int);
    void iniciarEspera();

private:
    int tallo, rama, hoja;
    sem_t semPadre;
    sem_t sem0,sem1,sem2,sem3,sem4,sem5,sem6,sem7,sem8,sem9;
    vector<int> pidHijos;
};

#endif // TALLO_H