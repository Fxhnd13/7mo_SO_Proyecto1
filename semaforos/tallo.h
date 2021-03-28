#ifndef TALLO_H
#define TALLO_H

#include "rama.cpp"

class Tallo
{
public:
    Tallo(int,int,int);
    ~Tallo();
    void setSemaforoPadre(sem_t& semPadre);
    void crearRamas(int,int);
    void iniciarEspera();

private:
    int tallo, rama, hoja;
    sem_t semPadre;
    sem_t sem0,sem1,sem2,sem3,sem4;
    vector<int> pidHijos;
};

#endif // TALLO_H