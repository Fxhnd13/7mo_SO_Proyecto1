#include "proceso.h"

Proceso::Proceso(int tipo, int comunicacion[2], int cantidadHijos){
    this->tipo = tipo;
    this->cantidadHijos = cantidadHijos;
    this->comunicacion[0] = comunicacion[0];
    this->comunicacion[1] = comunicacion[1];
    this->hijos = QVector<Proceso>();
}

Proceso::~Proceso(){

}

void Proceso::iniciarEspera(){
    char buffer[2];
    int nbytes;
    switch(tipo){
        case 0:{
            while (true){
                if ((nbytes = read(comunicacion[0], buffer, 2)) > 0){
                    int cantidadRamas = atoi(buffer);
                    if(cantidadRamas > this->cantidadHijos){

                    }else if(cantidadRamas < this->cantidadHijos){
                        //eliminamos las ramas necesarias
                    }
                }
            }
            break;
        }
        case 1:{
            while (true){
                if((nbytes = read(comunicacion[0], buffer, 2)) > 0){
                    int cantidadHojas = atoi(buffer);
                    if(cantidadHojas < 0 ){ //si queremos eliminar la rama
                        exit(0);
                    } else if(cantidadHojas > this->cantidadHijos){
                        //creamos más hojas
                    }else if(cantidadHojas < this->cantidadHijos){
                        //eliminamos las hojas necesarias
                    }
                }
            }
            break;
        }
        case 2:{
            while (true){
                if((nbytes = read(comunicacion[0], buffer, 2)) > 0) exit(0);
            }
            break;
        }
    }
}

int Proceso::getCantidadHijos(){
    return this->cantidadHijos;
}

int Proceso::getTipo(){
    return this->tipo;
}

int Proceso::getComunicacionEnviar(){
    return this->comunicacion[1];
}

int Proceso::getComunicacionRecibir(){
    return this->comunicacion[0];
}

QVector <Proceso> Proceso::getHijos(){
    return this->hijos;
}

void Proceso::setCantidadHijos(int param){
    this->cantidadHijos = param;
}

void Proceso::setTipo(int param){
    this->tipo = param;
}

void Proceso::setComunicacionEnviar(int param){
    this->comunicacion[1] = param;
}

void Proceso::setComunicacionRecibir(int param){
    this->comunicacion[0] = param;
}

void Proceso::setHijos(QVector<Proceso> param){
    this->hijos = param;
}
