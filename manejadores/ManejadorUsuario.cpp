
#include "ManejadorUsuario.h"
#include <set>

ManejadorUsuario* ManejadorUsuario::instancia = nullptr;

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if(instancia == nullptr){
        instancia = new ManejadorUsuario();
    }
    return instancia;
}

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario::~ManejadorUsuario(){}

std::set<Usuario*> ManejadorUsuario::getUsuarios(){
    return this->usuarios;
}

Usuario* ManejadorUsuario::getUsuario(std::string identificador){
    std::set<Usuario*>::iterator it;
    it = this->usuarios.begin();
    
    while(it != this->usuarios.end()) {
        Usuario* itU = *it;
        if(itU->getIdentificador() == identificador){
            return itU;
        } else {
            ++it;
        }
    }
    return nullptr;
}

void ManejadorUsuario::agregarUsuario(Usuario* u){
    this->usuarios.insert(u);
}
