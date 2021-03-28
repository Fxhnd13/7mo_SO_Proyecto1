#ifndef PROCESO_H
#define PROCESO_H


class Proceso
{
public:
    Proceso(int,int,int,int);
    void iniciarEspera();

private:
    int tipo, tallo, rama, hoja;
};

#endif // PROCESO_H
