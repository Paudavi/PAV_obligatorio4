#ifndef DTLECTOR_H
#define DTLECTOR_H

#include "DtUsuario.h"
#include "DtFecha.h"
#include <string>
#include <set>

class DtLector : public DtUsuario {
private:
    DtFecha* fechaRegistro;
    //set<DtPrestamo*> DtPrestamos;
    
public:
    //Construcores
    DtLector();
    DtLector(std::string i, std::string n, std::string p, DtFecha* fechaRegistro);
    DtLector(DtLector& DtL);
    
    //Getters
    DtFecha* getFecha();
    
    //Procedimientos
    DtLector* getDatosLector();
    //set<DtPrestamo*> obtenerDtPrestamos();
    
    
};


#endif /* DTLECTOR_H */

