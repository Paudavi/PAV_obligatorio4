#include "Prestamo.h"
#include "../dt/DtPrestamo.h"
#include <string>
using namespace std;    

Prestamo::Prestamo(DtFecha* fechaPrestamo, int cantDiasPrestamo, string codigoMaterial) {
    this->fechaPrestamo = fechaPrestamo;
    this->cantDiasPrestamo = cantDiasPrestamo;
    this->codigoMaterial = codigoMaterial;
}
Prestamo::~Prestamo() {}

DtFecha* Prestamo::getFechaPrestamo() {
    return this->fechaPrestamo;
}
int Prestamo::getCantDiasPrestamo() {
    return this->cantDiasPrestamo;
}
string Prestamo::getCodigoMaterial() {
    return this->codigoMaterial;
}
DtPrestamo Prestamo::getDatosPrestamo(DtLector* lector, DtMaterial* material) {
    return DtPrestamo(this->fechaPrestamo, this->cantDiasPrestamo, lector, material);
}
