
#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <string>

class DtUsuario {
private:
    std::string identificador;
    std::string nombre;
    std::string password;
    
public:
    //Constructores
    DtUsuario();
    DtUsuario(std::string i, std::string n, std::string p);
    DtUsuario(DtUsuario& DtU);
    
    //Getters
    std::string getIdentificador();
    std::string getNombre();
    std::string getPassword();
};


#endif /* DTUSUARIO_H */

