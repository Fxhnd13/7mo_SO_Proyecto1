#include "rama.h"

Rama::Rama(int tallo,int rama,int hoja){
    this->tallo = Rama;
    this->rama = rama;
    this->hoja = hoja;
}

Rama::~Rama(){

}

void Rama::setSemaforoPadre(sem_t& semPadre){
    this->semPadre = semPadre;
}

void Rama::crearHojas(int hoja){
    int pid = 1;
    for(int i = 0; i < hoja; i++){
        Hoja hoja = Hoja(this->tallo,this->rama,i+1);
        agregarSemaforo(&hoja);
        pid = fork();
        if(pid < 0 ){
            //error
        }else if(pid == 0){
            hoja.iniciarEspera();
            break;
        }
    }
    iniciarEspera();
}

void Rama::iniciarEspera(){
    while(true){
        sem_wait(&semPadre);
        for(int i = 0; i < pidHijos.size(); i++){
            //mandamos la señal al semaforo correspondiente
            postSemaforo(i);
            waitSemaforo(i);
        }
        printf("Verificamos la rama %d-%d-%d",this->tallo, this->rama, this->hoja);
        sem_post(&semPadre);
    }
}

void Rama::agregarSemaforo(Hoja& hoja){
    switch(pidHijos.size()){
        case 0:{
            sem_init(&sem0,1,1);
            hoja.setSemaforoPadre(&sem0);
            break;
        }
        case 1:{
            sem_init(&sem1,1,1);
            hoja.setSemaforoPadre(&sem1);
            break;
        }
        case 2:{
            sem_init(&sem2,1,1);
            hoja.setSemaforoPadre(&sem2);
            break;
        }
        case 3:{
            sem_init(&sem3,1,1);
            hoja.setSemaforoPadre(&sem3);
            break;
        }
        case 4:{
            sem_init(&sem4,1,1);
            hoja.setSemaforoPadre(&sem4);
            break;
        }
        case 5:{
            sem_init(&sem5,1,1);
            hoja.setSemaforoPadre(&sem5);
            break;
        }
        case 6:{
            sem_init(&sem6,1,1);
            hoja.setSemaforoPadre(&sem6);
            break;
        }
        case 7:{
            sem_init(&sem7,1,1);
            hoja.setSemaforoPadre(&sem7);
            break;
        }
        case 8:{
            sem_init(&sem8,1,1);
            hoja.setSemaforoPadre(&sem8);
            break;
        }
        case 9:{
            sem_init(&sem9,1,1);
            hoja.setSemaforoPadre(&sem9);
            break;
        }
    }
}

void Rama::waitSemaforo(int valor){
    switch(valor){
        case 0:{
            sem_wait(&sem0);
            break;
        }
        case 1:{
            sem_wait(&sem1);
            break;
        }
        case 2:{
            sem_wait(&sem2);
            break;
        }
        case 3:{
            sem_wait(&sem3);
            break;
        }
        case 4:{
            sem_wait(&sem4);
            break;
        }
        case 5:{
            sem_wait(&sem5);
            break;
        }
        case 6:{
            sem_wait(&sem6);
            break;
        }
        case 7:{
            sem_wait(&sem7);
            break;
        }
        case 8:{
            sem_wait(&sem8);
            break;
        }
        case 9:{
            sem_wait(&sem9);
            break;
        }
    }
}

void Rama::postSemaforo(int valor){
    switch(valor){
        case 0:{
            sem_post(&sem0);
            break;
        }
        case 1:{
            sem_post(&sem1);
            break;
        }
        case 2:{
            sem_post(&sem2);
            break;
        }
        case 3:{
            sem_post(&sem3);
            break;
        }
        case 4:{
            sem_post(&sem4);
            break;
        }
        case 5:{
            sem_post(&sem5);
            break;
        }
        case 6:{
            sem_post(&sem6);
            break;
        }
        case 7:{
            sem_post(&sem7);
            break;
        }
        case 8:{
            sem_post(&sem8);
            break;
        }
        case 9:{
            sem_post(&sem9);
            break;
        }
    }
}