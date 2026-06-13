
#include "DtLector.h"
#include <string>

//Construcores
DtLector::DtLector() : DtUsuario() {}

DtLector::DtLector(std::string i, std::string n, std::string p,
        DtFecha* fechaRegistro) : DtUsuario(i, n, p){
    //this->DtPrestamos = nullptr;
    this->fechaRegistro = fechaRegistro;
}

DtLector::DtLector(DtLector& DtL) : DtUsuario(DtL){
    //this->DtPrestamos = nullptr;
    this->fechaRegistro = DtL.fechaRegistro;
}

//Getters
DtFecha* DtLector::getFecha() {
    return this->fechaRegistro;
}

//Procedimientos
//std::set<DtPrestamo*> DtLector::obtenerDtPrestamos() {
    //return this->DtPrestamos;
//}

