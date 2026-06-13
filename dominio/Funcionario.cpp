#include "Funcionario.h"
#include "Usuario.h"
#include <string>

//Construcores
Funcionario::Funcionario(){}

Funcionario::Funcionario(std::string i, std::string n, std::string p,
        int numeroEmpleado) : Usuario(i,n,p) {
    this->numeroEmpleado = numeroEmpleado;
}

Funcionario::Funcionario(Funcionario& f) : Usuario(f){
    this->numeroEmpleado = f.numeroEmpleado;
}

//Getters
int Funcionario::getNumeroEmpleado(){
    return this->numeroEmpleado;
}

//Setters
void Funcionario::setNumeroEmpleado(int numeroNuevo){
    this->numeroEmpleado = numeroNuevo;
}