
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Usuario.h"
#include <string>

class Funcionario : public Usuario {
private:
    int numeroEmpleado;
    
public:
    //Construcores
    Funcionario();
    Funcionario(std::string i, std::string n, std::string p, int numeroEmpleado);
    Funcionario(Funcionario& f);
    
    //Getters
    int getNumeroEmpleado();
    
    //Setters
    void setNumeroEmpleado(int numeroNuevo);
    
    
};


#endif /* FUNCIONARIO_H */

