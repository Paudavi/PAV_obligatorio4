
#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string identificador;
    std::string nombre;
    std::string password;
    
public:
    //Constructores
    Usuario();
    Usuario(std::string i, std::string n, std::string p);
    Usuario(Usuario& u);
    
    //Getters
    std::string getIdentificador();
    std::string getNombre();
    std::string getPassword();
    
    //Setters
    void setIdentificador(std::string idNuevo);
    void setNombre(std::string nombreNuevo);
    void setPassword(std::string passNueva);
    
    //procedimientos
    bool verificarPassword(std::string pass);
    
};

#endif /* USUARIO_H */

