
#include "Fabrica.h"
#include "controladores/CtrlUsuario.h"
#include "controladores/CtrlSesion.h"
#include "controladores/CtrlMaterial.h"
#include "controladores/CtrlPrestamo.h"

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

ICtrlMaterial* Fabrica::getICtrlMaterial() {
    return CtrlMaterial::getInstancia();
}

ICtrlPrestamo* Fabrica::getICtrlPrestamo() {
    return CtrlPrestamo::getInstancia();
}