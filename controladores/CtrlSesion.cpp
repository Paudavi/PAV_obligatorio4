#include "CtrlSesion.h"
#include "../manejadores/ManejadorUsuario.h"
#include "../dt/DtUsuario.h"
#include "../dominio/Sesion.h"
#include <set>

CtrlSesion* CtrlSesion::instancia = nullptr;
CtrlSesion::CtrlSesion(){
    this->manejador = ManejadorUsuario::getInstancia();
    this->usuarioRecordado = nullptr;
    this->sesion = Sesion::getInstancia();
}
CtrlSesion::~CtrlSesion(){}

CtrlSesion* CtrlSesion::getInstancia(){
    if(instancia == nullptr){
        instancia = new CtrlSesion();
    }
    return instancia;
}

bool CtrlSesion::ingresarDatos(std::string id, std::string pass){
    Usuario* u = this->manejador->getUsuario(id);

    if (u != nullptr && u->verificarPassword(pass)) {
        this->usuarioRecordado = u;
        return true;
    }

    return false;
}
    
void CtrlSesion::iniciarSesion(){
    this->sesion->setUsuario(this->usuarioRecordado);
    this->usuarioRecordado = nullptr;
}

void CtrlSesion::cancelarInicio(){
    this->usuarioRecordado = nullptr;
}

void CtrlSesion::cerrarSesion(){
    this->sesion->setUsuario(nullptr);
}