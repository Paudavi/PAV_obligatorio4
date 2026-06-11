
#ifndef LECTOR_H
#define LECTOR_H

#include "Usuario.h"
#include "DtFecha.h"
#include <string>
#include <set>



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
    
    
};
#endif /* LECTOR_H */

