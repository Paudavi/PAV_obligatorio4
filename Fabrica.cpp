
#include "Fabrica.h"
#include "controladores/CtrlUsuario.h"
#include "controladores/CtrlSesion.h"


Fabrica* Fabrica::instancia = nullptr;

Fabrica* Fabrica::getInstancia(){
    if(instancia == nullptr){
        instancia = new Fabrica();
    }
    return instancia;
}

Fabrica::Fabrica(){}

ICtrlUsuario* Fabrica::getICtrlUsuario(){
    return CtrlUsuario::getInstancia();
}

ICtrlSesion* Fabrica::getICtrlSesion(){
    return CtrlSesion::getInstancia();
}