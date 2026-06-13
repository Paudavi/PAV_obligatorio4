
#ifndef CTRLUSUARIO_H
#define CTRLUSUARIO_H

#include "ICtrlUsuario.h"
#include "../manejadores/ManejadorUsuario.h"
#include "../dt/DtFecha.h"
#include "../dt/DtFuncionario.h"
#include "../dt/DtLector.h"
#include <string>


class CtrlUsuario : public ICtrlUsuario {
private:
    static CtrlUsuario* instancia;
    CtrlUsuario();
    ~CtrlUsuario();
    ManejadorUsuario* manejador;
    DtLector* dtLectorRecordado;
    DtFuncionario* dtFuncionarioRecordado;
    
public:
    static CtrlUsuario* getInstancia();
    
    //procedimientos
    //heredados
    
    DtLector* ingresarDatosLector(std::string id, std::string nombre,
    std::string pass, DtFecha* fecha);
    
    void confirmarRegistroLector();
    
    void cancelarRegistroLector();
    
    DtFuncionario* registrarFuncionarioNuevo(std::string id, std::string nombre, 
    std::string pass, int nroEmpleado);
    
    void confirmarRegistro();
    
    void cancelarRegistro();
    
    //propios
    
    DtFuncionario* recuerdaDatosFuncionario(std::string id, std::string nombre,
    std::string pass, int nroEmpleado);
    
    DtLector* recuerdaDatosLector(std::string id, std::string nombre,
    std::string pass, DtFecha* fecha);
    
    void eliminarDatosRecordados();
    
    
};



#endif /* CTRLUSUARIO_H */

