#ifndef FABRICA_H
#define FABRICA_H

#include "ICtrlSesion.h"
#include "ICtrlUsuario.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();
    
public:
    static Fabrica* getInstancia();
    
    ICtrlUsuario* getICtrlUsuario();
    ICtrlSesion* getICtrlSesion();
};

#endif /* FABRICA_H */

