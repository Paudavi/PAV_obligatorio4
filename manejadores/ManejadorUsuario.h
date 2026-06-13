

#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <set>
#include <string>
#include "../dominio/Usuario.h"

class ManejadorUsuario {
private:
    static ManejadorUsuario* instancia;
    
    std::set<Usuario*> usuarios;
    
    ManejadorUsuario();
    ~ManejadorUsuario();
    
public:
    static ManejadorUsuario* getInstancia();
    
    std::set<Usuario*> getUsuarios();
    
    Usuario* getUsuario(std::string identificador);
    
    void agregarUsuario(Usuario* u);
};


#endif /* MANEJADORUSUARIO_H */

