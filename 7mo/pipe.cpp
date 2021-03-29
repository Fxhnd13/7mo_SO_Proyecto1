#include "pipe.h"

Pipe::Pipe(){}
Pipe::Pipe(int param[2]){
    this->pipes[0] = param[0];
    this->pipes[1] = param[1];
}
Pipe::~Pipe(){

}

int Pipe::getPipesEnvio(){
    return this->pipes[1];
}

int Pipe::getPipeRecibir(){
    return this->pipes[0];
}

void Pipe::setPipes(int param[2]){
    this->pipes[0] = param[0];
    this->pipes[1] = param[1];
}
