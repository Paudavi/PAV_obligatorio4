#include "DtUsuario.h"
#include "DtFuncionario.h"
#include <string>

//Construcores
DtFuncionario::DtFuncionario() : DtUsuario(){}

DtFuncionario::DtFuncionario(std::string i, std::string n, std::string p, 
        int numeroEmpleado) : DtUsuario(i, n, p){
    this->numeroEmpleado = numeroEmpleado;
}
DtFuncionario::DtFuncionario(DtFuncionario& DtF) : DtUsuario(DtF) {
    this->numeroEmpleado = DtF.numeroEmpleado;
}

//Getters
int DtFuncionario::getNumeroEmpleado(){
    return this->numeroEmpleado;
}

