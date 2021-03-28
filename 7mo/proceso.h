#include <QVector>
#include <stdio.h>
#include <unistd.h>
#include <pipe.h>

#ifndef PROCESO_H
#define PROCESO_H

class Proceso
{
public:
    Proceso(Pipe);
    Proceso();
    ~Proceso();
    void iniciarEspera();
    void setComunicacion(Pipe);
    int getComunicacionEnviar();
    int getComunicacionRecibir();

private:
    int comunicacion[2];
};

#endif // PROCESO_H
