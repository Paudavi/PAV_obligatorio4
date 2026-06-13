
#ifndef DTFUNCIONARIO_H
#define DTFUNCIONARIO_H

#include "DtUsuario.h"
#include <string>

class DtFuncionario : public DtUsuario {
private:
    int numeroEmpleado;
    
public:
    //Construcores
    DtFuncionario();
    DtFuncionario(std::string i, std::string n, std::string p, int numeroEmpleado);
    DtFuncionario(DtFuncionario& DtF);
    
    //Getters
    int getNumeroEmpleado();
};



#endif /* DTFUNCIONARIO_H */

