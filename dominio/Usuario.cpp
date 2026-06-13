#include "Usuario.h"
#include <string>


//Constructores
Usuario::Usuario(){}

Usuario::Usuario(std::string i, std::string n, std::string p) {
    this->identificador = i;
    this->nombre = n;
    this->password = p;
}
Usuario::Usuario(Usuario& u){
    this->identificador = u.identificador;
    this->nombre = u.nombre;
    this->password = u.password;
}

//Getters
std::string Usuario::getIdentificador(){
    return this->identificador;
}

std::string Usuario::getNombre(){
    return this->nombre;
}
std::string Usuario::getPassword(){
    return this->password;
}
//Setters
void Usuario::setIdentificador(std::string idNuevo){
    this->identificador = idNuevo;
}

void Usuario::setNombre(std::string nombreNuevo){
    this->nombre = nombreNuevo;
}

void Usuario::setPassword(std::string passNueva){
    this->password = passNueva;
}

bool Usuario::verificarPassword(std::string pass){
    return (this->password == pass);
}