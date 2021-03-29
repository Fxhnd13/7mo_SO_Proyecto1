#include "proceso.h"
#include <QStringList>

Proceso::Proceso(){}
Proceso::Proceso(Pipe param){
    this->comunicacion[0] = param.getPipeRecibir();
    this->comunicacion[1] = param.getPipesEnvio();
}

Proceso::~Proceso(){

}

void Proceso::iniciarEspera(){
    while(true){
        sleep(1);
    }
}

int Proceso::getComunicacionEnviar(){
    return this->comunicacion[1];
}

int Proceso::getComunicacionRecibir(){
    return this->comunicacion[0];
}

void Proceso::setComunicacion(Pipe param){
    this->comunicacion[0] = param.getPipeRecibir();
    this->comunicacion[1] = param.getPipesEnvio();
}
