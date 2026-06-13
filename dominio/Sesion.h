
#ifndef SESION_H
#define SESION_H

#include "Usuario.h"


class Sesion {
private:
    static Sesion* instancia;
    Sesion();
    ~Sesion();
    Usuario* usuario;
    
public:
    static Sesion* getInstancia();
    //Getter
    Usuario* getUsuario();
    
    //Setter
    void setUsuario(Usuario* u);
    
};

#endif /* SESION_H */

