#include "hoja.h";

Hoja::Hoja(int Hoja,int rama,int hoja){
    this->tallo = tallo;
    this->rama = rama;
    this->hoja = hoja;
}

Hoja::~Hoja(){

}

void Hoja::setSemaforoPadre(sem_t& semPadre){
    this->semPadre = semPadre;
}

void Hoja::iniciarEspera(){
    while(true){
        sem_wait(&semPadre);
        printf("Verificamos la rama %d-%d-%d",this->tallo, this->rama, this->hoja);
        sem_post(&semPadre);
    }
}