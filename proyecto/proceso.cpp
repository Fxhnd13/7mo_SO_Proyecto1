#include "proceso.h"

Proceso::Proceso(int tallo, int rama, int hoja){
    this->pids = QVector<int>();
    this->semaforos = QVector<sem_t>();
    this->tallo = tallo;
    this->rama = rama;
    this->hoja = hoja;
    this->color = 0;
}

void Proceso::iniciarEspera(){

}

void Proceso::setPid(int param){
    this->pid = param;
}

int Proceso::getPid(){
    return this->pid;
}
