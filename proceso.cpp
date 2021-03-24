#include "proceso.h"
#include <QStringList>

Proceso::Proceso(){}
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
    int nbytes;
    switch(tipo){
        case 0:{
            while (true){
                char buffer[5];
                if ((nbytes = read(comunicacion[0], buffer, 5)) > 0){
                    QString cadena = QString(buffer);
                    int cantidadRamas = cadena.split(',').at(0).toInt();
                    if(cantidadRamas > this->cantidadHijos){
                        for(int i = 0; i < (cantidadRamas - this->cantidadHijos); i++){
                            int comunicacion[2];
                            pipe(comunicacion);
                            Proceso procesoHijo = Proceso(1,comunicacion,0);
                            int pid_p = fork();
                            if(pid_p < 0 ){
                                //error
                            }else if(pid_p == 0){
                                procesoHijo.iniciarEspera();
                            }
                            this->hijos.append(procesoHijo);
                            this->cantidadHijos++;
                        }
                    }else if(cantidadRamas < this->cantidadHijos){
                        for(int i = this->cantidadHijos; i > cantidadRamas; i--){
                            Proceso procesoHijo = this->hijos.at(i-1);
                            write(procesoHijo.getComunicacionEnviar(),"-1,00",5);
                            this->hijos.removeLast();
                        }
                        this->cantidadHijos = cantidadRamas;
                    }
                    for(int i = 0; i < this->cantidadHijos; i++){
                        //Por cada rama verificamos que tengan ahora las hojas correspondientes
                    }
                }
            }
            break;
        }
        case 1:{
            while (true){
                char buffer[5];
                if((nbytes = read(comunicacion[0], buffer, 5)) > 0){
                    QString cadena = QString(buffer);
                    if(cadena.split(',').at(0).toInt() < 0 ){
                        for (int i = (this->cantidadHijos-1); i >= 0; i++) {
                            Proceso procesoHijo = this->hijos.at(i);
                            write(procesoHijo.getComunicacionEnviar(),"-1",2);
                            this->hijos.removeLast();
                        }
                        exit(0);
                    }else{
                        int cantidadHojas = cadena.split(',').at(2).toInt();
                        if(cantidadHojas > this->cantidadHijos){
                            for(int i = 0; i < (cantidadHojas - this->cantidadHijos); i++){
                                int comunicacion[2];
                                pipe(comunicacion);
                                Proceso procesoHijo = Proceso(2,comunicacion,0);
                                int pid_p = fork();
                                if(pid_p < 0 ){
                                    //error
                                }else if(pid_p == 0){
                                    procesoHijo.iniciarEspera();
                                }
                                this->hijos.append(procesoHijo);
                                this->cantidadHijos++;
                            }
                        }else if(this->cantidadHijos > cantidadHojas){
                            for(int i = this->cantidadHijos; i > cantidadHojas; i--){
                                Proceso procesoHijo = this->hijos.at(i-1);
                                write(procesoHijo.getComunicacionEnviar(),"-1",2);
                                this->hijos.removeLast();
                            }
                            this->cantidadHijos = cantidadHojas;
                        }
                    }
                }
            }
            break;
        }
        case 2:{
            while (true){
                char buffer[2];
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
