#ifndef FABRICA_H
#define FABRICA_H

#include "controladores/ICtrlSesion.h"
#include "controladores/ICtrlUsuario.h"
#include "controladores/ICtrlMaterial.h"
#include "controladores/ICtrlPrestamo.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();
    
public:
    static Fabrica* getInstancia();
    
    ICtrlUsuario* getICtrlUsuario();
    ICtrlSesion* getICtrlSesion();
    ICtrlMaterial* getICtrlMaterial();
    ICtrlPrestamo* getICtrlPrestamo();

};

#endif /* FABRICA_H */

