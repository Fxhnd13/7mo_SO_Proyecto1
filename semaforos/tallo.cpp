#include "tallo.h"

Tallo::Tallo(int tallo,int rama,int hoja){
    this->tallo = tallo;
    this->rama = rama;
    this->hoja = hoja;
}

Tallo::~Tallo(){

}

void Tallo::setSemaforoPadre(sem_t& semPadre){
    this->semPadre = semPadre;
}

void Tallo::crearRamas(int rama, int hoja){
    int pid = 1;
    for(int i = 0; i < rama; i++){
        Rama rama = Rama(this->tallo,i+1,0);
        agregarSemaforo(&rama);
        pid = fork();
        if(pid < 0 ){
            //error
        }else if(pid == 0){
            rama.crearHojas(hoja);
            rama.iniciarEspera();
        }
        pidHijos.push_back(pid);
    }
}

void Tallo::iniciarEspera(){
    while(true){
        sem_wait(&semPadre);
        for(int i = 0; i < pidHijos.size(); i++){
            //mandamos la señal al semaforo correspondiente
            postSemaforo(i);
            waitSemaforo(i);
        }
        printf("Verificamos el tallo %d-%d-%d",this->tallo, this->rama, this->hoja);
        sem_post(&semPadre);
    }
}

void Tallo::agregarSemaforo(Rama& rama){
    switch(pidHijos.size()){
        case 0:{
            sem_init(&sem0,1,1);
            rama.setSemaforoPadre(&sem0);
            break;
        }
        case 1:{
            sem_init(&sem1,1,1);
            rama.setSemaforoPadre(&sem1);
            break;
        }
        case 2:{
            sem_init(&sem2,1,1);
            rama.setSemaforoPadre(&sem2);
            break;
        }
        case 3:{
            sem_init(&sem3,1,1);
            rama.setSemaforoPadre(&sem3);
            break;
        }
        case 4:{
            sem_init(&sem4,1,1);
            rama.setSemaforoPadre(&sem4);
            break;
        }
    }
}

void Tallo::waitSemaforo(int valor){
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
    }
}

void Tallo::postSemaforo(int valor){
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
    }
}