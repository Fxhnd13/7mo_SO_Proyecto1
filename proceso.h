#include <QVector>
#include <stdio.h>
#include <unistd.h>

#ifndef PROCESO_H
#define PROCESO_H

class Proceso
{
public:
    Proceso(int,int[2],int);
    ~Proceso();
    void iniciarEspera();

    int getCantidadHijos();
    void setCantidadHijos(int);
    int getTipo();
    void setTipo(int);
    int getComunicacionEnviar();
    void setComunicacionEnviar(int);
    int getComunicacionRecibir();
    void setComunicacionRecibir(int);
    QVector <Proceso> getHijos();
    void setHijos(QVector <Proceso>);

private:
    int cantidadHijos, tipo;// Tallo: 0, Rama: 1, Hoja: 2
    int comunicacion[2];
    QVector <Proceso> hijos;
};

#endif // PROCESO_H
