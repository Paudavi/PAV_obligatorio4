
#ifndef ICTRLSESION_H
#define ICTRLSESION_H

#include <string>

class ICtrlSesion {
public:
    virtual bool ingresarDatos(std::string id, std::string pass) = 0;
    
    virtual void iniciarSesion() = 0;
    
    virtual void cancelarInicio() = 0;
    
    virtual void cerrarSesion() = 0;
};


#endif /* ICTRLSESION_H */

