#include "Sesion.h"

Sesion* Sesion::instancia = nullptr;
Sesion::Sesion(){
    this->usuario = nullptr;
}
Sesion::~Sesion(){}

Sesion* Sesion::getInstancia(){
    if(instancia == nullptr){
        instancia = new Sesion();
    }
    return instancia;
}


//Getter
Usuario* Sesion::getUsuario(){
    return this->usuario;
}

//Setter
void Sesion::setUsuario(Usuario* u){
    this->usuario = u;
}


