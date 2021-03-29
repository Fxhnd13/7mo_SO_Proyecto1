#include "tallo.cpp"
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t semaforo;
static Tallo tallo0,tallo1,tallo2,tallo3,tallo4,tallo5,tallo6,tallo7,tallo8,tallo9;
sem_t sem0,sem1,sem2,sem3,sem4,sem5,sem6,sem7,sem8,sem9;
static int pidHijos[10];
static int hijos = 0;

void iniciarEspera();
static void * entrada(void* arg);
static void * actualizacion(void* arg);
static void crear(int,int,int);
static void modificar(int,int,int);
static void agregarTallo(Tallo&);
static void waitSemaforo(int);
static void postSemaforo(int);
static void agregarSemaforo(Tallo&);

int main(int argc, char *argv[]){

    pthread_t hilo1, hilo2;
    sem_init(&semaforo,0,1);

    pthread_create(&hilo1,NULL,*entrada,NULL);
    pthread_create(&hilo2,NULL,*actualizacion,NULL);

    pthread_join(hilo1,NULL);
    pthread_join(hilo2,NULL);

    return 0;
}

static void * entrada(void* arg){
    while(true){
        int tallo, ramas, hojas;
        scanf("%d",&tallo);
        scanf("%d",&ramas);
        scanf("%d",&hojas);
        sem_wait(&semaforo);
        if(tallo > hijos){
            crear(tallo, ramas, hojas);
        }else{
            modificar(tallo, ramas, hojas);
        }
        sem_post(&semaforo);    
    }
}

static void * actualizacion(void* arg){
    sem_wait(&semaforo);
    for(int i = 0; i < hijos; i++){
        postSemaforo(i);
        waitSemaforo(i);
    }
    printf("Actualizar interfaz\n");
    sleep(5);
    sem_post(&semaforo);
}

static void crear(int tallo, int rama, int hoja){
    Tallo objetoTallo = Tallo(tallo,0,0);
    agregarSemaforo(objetoTallo);
    int p = fork();
    if(p < 0){
        //error
    }else if(p == 0){
        objetoTallo.crearRamas(rama,hoja);
    }
    pidHijos[hijos++] = p;
    agregarTallo(objetoTallo);
}

static void modificar(int tallo, int rama, int hoja){
    //accedemos al archivo de texto a modificarlo (mas complejo)
}

static void agregarSemaforo(Tallo& tallo){
    switch(hijos){
        case 0:{
            sem_init(&sem0,1,1);
            tallo.setSemaforoPadre(sem0);
            break;
        }
        case 1:{
            sem_init(&sem1,1,1);
            tallo.setSemaforoPadre(sem1);
            break;
        }
        case 2:{
            sem_init(&sem2,1,1);
            tallo.setSemaforoPadre(sem2);
            break;
        }
        case 3:{
            sem_init(&sem3,1,1);
            tallo.setSemaforoPadre(sem3);
            break;
        }
        case 4:{
            sem_init(&sem4,1,1);
            tallo.setSemaforoPadre(sem4);
            break;
        }
        case 5:{
            sem_init(&sem5,1,1);
            tallo.setSemaforoPadre(sem5);
            break;
        }
        case 6:{
            sem_init(&sem6,1,1);
            tallo.setSemaforoPadre(sem6);
            break;
        }
        case 7:{
            sem_init(&sem7,1,1);
            tallo.setSemaforoPadre(sem7);
            break;
        }
        case 8:{
            sem_init(&sem8,1,1);
            tallo.setSemaforoPadre(sem8);
            break;
        }
        case 9:{
            sem_init(&sem9,1,1);
            tallo.setSemaforoPadre(sem9);
            break;
        }
    }
}

static void agregarTallo(Tallo& tallo){
    switch(hijos){
        case 0:{
            tallo0 = tallo;
            break;
        }
        case 1:{
            tallo1 = tallo;
            break;
        }
        case 2:{
            tallo2 = tallo;
            break;
        }
        case 3:{
            tallo3 = tallo;
            break;
        }
        case 4:{
            tallo4 = tallo;
            break;
        }
        case 5:{
            tallo5 = tallo;
            break;
        }
        case 6:{
            tallo6 = tallo;
            break;
        }
        case 7:{
            tallo7 = tallo;
            break;
        }
        case 8:{
            tallo8 = tallo;
            break;
        }
        case 9:{
            tallo9 = tallo;
            break;
        }
    }
}

static void waitSemaforo(int valor){
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

static void postSemaforo(int valor){
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