#include "tallo.h"

Tallo::Tallo(){

}

Tallo::Tallo(int idTallo, int ramas, int hojas){
    this->idTallo = idTallo;
    this->ramas = ramas;
    this->hojas = hojas;
}

Tallo::Tallo(int ramas,int hojas,QVector<Pipe> pipes){
    this->ramas = ramas;
    this->hojas = hojas;
    this->pipes = pipes;
}

Tallo::~Tallo(){}

int Tallo::getRamas(){
    return this->ramas;
}

int Tallo::getHojas(){
    return this->hojas;
}

void Tallo::setRamas(int param){
    this->ramas = param;
}

void Tallo::setHojas(int param){
    this->hojas = param;
}

QVector<Pipe> Tallo::getPipes(){
    return this->pipes;
}

void Tallo::setPipes(QVector<Pipe> param){
    this->pipes = param;
}
