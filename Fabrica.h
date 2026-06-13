#ifndef FABRICA_H
#define FABRICA_H

#include "controladores/ICtrlSesion.h"
#include "controladores/ICtrlUsuario.h"

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

