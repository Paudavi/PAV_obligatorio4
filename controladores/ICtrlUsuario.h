
#ifndef ICTRLUSUARIO_H
#define ICTRLUSUARIO_H
#include "../dt/DtLector.h"
#include "../dt/DtFuncionario.h"

class ICtrlUsuario {
public:
    virtual DtLector* ingresarDatosLector(std::string id, std::string nombre,
    std::string pass, DtFecha* fecha) = 0;
    
    virtual void confirmarRegistroLector() = 0;
    
    virtual void cancelarRegistroLector() = 0;
    
    virtual DtFuncionario* registrarFuncionarioNuevo(std::string id, std::string nombre, 
    std::string pass, int nroEmpleado) = 0;
    
    virtual void confirmarRegistro() = 0;
    
    virtual void cancelarRegistro() = 0;
};


#endif /* ICTRLUSUARIO_H */

