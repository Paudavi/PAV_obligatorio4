
#ifndef CTRLSESION_H
#define CTRLSESION_H

#include <string>
#include "ICtrlSesion.h"
#include "../dominio/Sesion.h"
#include "../manejadores/ManejadorUsuario.h"

class CtrlSesion : public ICtrlSesion {
private:
    static CtrlSesion* instancia;
    CtrlSesion();
    ~CtrlSesion();
    Sesion* sesion;
    ManejadorUsuario* manejador;
    Usuario* usuarioRecordado;
    
public:
    static CtrlSesion* getInstancia();
    
    //procedimientos
    
    bool ingresarDatos(std::string id, std::string pass);
    
    void iniciarSesion();
    
    void cancelarInicio();
    
    void cerrarSesion();
        
};


#endif /* CTRLSESION_H */

