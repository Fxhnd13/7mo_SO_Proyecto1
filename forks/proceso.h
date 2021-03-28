#ifndef PROCESO_H
#define PROCESO_H

#include <semaphore.h>
#include <vector>

class Proceso
{
public:
    Proceso(int,int,int);
    void iniciarEspera();
    void setPid(int);
    int getPid();

private:
    vector<sem_t> semaforos; //para enviar señales a todos los hijos
    vector<int> pids; //para matar a los hijos o añadir los pids por si son útiles
    int pid,tallo,rama,hoja,color; //básicamente su identificador para el archivo de texto.
};

#endif // PROCESO_H
