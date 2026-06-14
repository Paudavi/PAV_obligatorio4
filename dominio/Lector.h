
#ifndef LECTOR_H
#define LECTOR_H

#include "Usuario.h"
#include "../dt/DtFecha.h"
#include "../dt/DtLector.h"
#include <string>
#include <set>
#include "Prestamo.h"


class Lector : public Usuario {
private:
    DtFecha* fechaRegistro;
    std::set<Prestamo*> Prestamos;
    
public:
    //Construcores
    Lector();
    Lector(std::string i, std::string n, std::string p, DtFecha* fechaRegistro);
    Lector(Lector& l);
    
    //Getters
    DtFecha* getFecha();
    
    //Setters
    void setFecha(DtFecha* fechaNueva);
    
    //Procedimientos
    DtLector* getDatosLector();
    std::set<Prestamo*> obtenerPrestamos();
    Prestamo* crearPrestamo(DtFecha* fecha, int cantDias, std::string codigoMaterial);
    
    
};
#endif /* LECTOR_H */

