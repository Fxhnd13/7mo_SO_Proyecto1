#include <proceso.h>
#include <stdio.h>
#include <pthread.h>

vector<Proceso> procesos;
vector<sem_t> semaforos;
sem_t semaforo;

void iniciarEspera();
static void * entrada(void* arg);
static void * actualizacion(void* arg);
static void crear(int,int,int);
static void modificar(int,int,int);

int main(int argc, char *argv[]){

    pthread_t hilo1, hilo2;
    sem_init(&semaforo,0,1);

    pthread_create(&hilo1,NULL,*entrada,NULL);
    pthread_create(&hilo2,NULL,*actualizacion,NULL);

    pthread_join(hilo1,NULL);
    pthread_join(hilo2,NULL);

    printf("Valor del contador es: %d",contador);

    return 0;
}

void iniciarEspera(){

}

static void * entrada(void* arg){
    for(int i = 0; i < 1000; i++){
        sem_wait(&semaforo);
        contador-=1;
        sem_post(&semaforo);
    }
    /*while(true){
        printf("Ingrese el comando (tres parametros): ");
        char ingreso[10];
        scanf("%s",ingreso);
        QString cadena = QString(ingreso);
        sem_wait(&semaforo);
        QStringList parametros = cadena.split(',');
        if(parametros.at(0).toInt() > procesos.size()){
            crear(
                  parametros.at(0).toInt(),
                  (parametros.size()>1)?parametros.at(1).toInt():0,
                  (parametros.size()>2)?parametros.at(2).toInt():0);
        }else{
            modificar(
                  parametros.at(0).toInt(),
                  (parametros.size()>1)?parametros.at(1).toInt():0,
                  (parametros.size()>2)?parametros.at(2).toInt():0);
        }
    } */
}

static void * actualizacion(void* arg){
    for(int i = 0; i < 1000; i++){
        sem_wait(&semaforo);
        contador+=1;
        sem_post(&semaforo);
    }
}

static void crear(int tallo, int rama, int hoja){

}

static void modificar(int tallo, int rama, int hoja){

}
