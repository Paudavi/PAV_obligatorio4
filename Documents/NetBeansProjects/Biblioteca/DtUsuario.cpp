#include "DtUsuario.h"
#include <string>

//Constructores
DtUsuario::DtUsuario(){}

DtUsuario::DtUsuario(std::string i, std::string n, std::string p) {
    this->identificador = i;
    this->nombre = n;
    this->password = p;
}
DtUsuario::DtUsuario(DtUsuario& DtU){
    this->identificador = DtU.identificador;
    this->nombre = DtU.nombre;
    this->password = DtU.password;
}

//Getters
std::string DtUsuario::getIdentificador(){
    return this->identificador;
}

std::string DtUsuario::getNombre(){
    return this->nombre;
}
std::string DtUsuario::getPassword(){
    return this->password;
}