#include "proceso.h"

Proceso::Proceso(int tipo, int tallo, int rama, int hoja){
    this->tipo = tipo;
    this->tallo = tallo;
    this->rama = rama;
    this->hoja = hoja;
}

void Proceso::iniciarEspera(){
    switch(this->tipo){
        case 0:{
            while(true){

            }
            break;
        }
        case 1:{
            while(true){

            }
            break;
        }
        case 2:{
            while(true){

            }
            break;
        }
    }
}
