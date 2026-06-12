#include "Lector.h"
#include "Usuario.h"
#include "DtLector.h"
#include <string>
#include <set>

//Construcores
Lector::Lector(){}

Lector::Lector(std::string i, std::string n, std::string p,
        DtFecha* fechaRegistro) : Usuario(i,n,p) {
    this->fechaRegistro = fechaRegistro;
}

Lector::Lector(Lector& l) : Usuario(l) {
    //this->Prestamos = l.Prestamos;
    this->fechaRegistro = l.fechaRegistro;
}

//Getters
DtFecha* Lector::getFecha(){
    return this->fechaRegistro;
}

//Setters
void Lector::setFecha(DtFecha* fechaNueva){
    this->fechaRegistro = fechaNueva;
}

//Procedimientos
DtLector* Lector::getDatosLector(){
    DtLector* DtL = new DtLector(this->getIdentificador(), this->getNombre(),
            this->getPassword(), this->fechaRegistro);
    return DtL;
}
//std::set<Prestamo*> Lector::obtenerPrestamos(){
   // return this->Prestamos;
//}

