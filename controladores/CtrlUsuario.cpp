#include "CtrlUsuario.h"
#include "ICtrlUsuario.h"
#include "../manejadores/ManejadorUsuario.h"
#include "../dt/DtFecha.h"
#include "../dt/DtFuncionario.h"
#include "../dt/DtLector.h"
#include "../dominio/Lector.h"
#include "../dominio/Funcionario.h"
#include <string>

CtrlUsuario* CtrlUsuario::instancia = nullptr;
CtrlUsuario::CtrlUsuario(){
    this->manejador = ManejadorUsuario::getInstancia();
    this->dtFuncionarioRecordado = nullptr;
    this->dtLectorRecordado = nullptr;
}
CtrlUsuario::~CtrlUsuario(){}

CtrlUsuario* CtrlUsuario::getInstancia(){
    if(instancia == nullptr){
        instancia = new CtrlUsuario();
    }
    return instancia;
}

//procedimientos

//heredados
DtLector* CtrlUsuario::ingresarDatosLector(std::string id, std::string nombre,
std::string pass, DtFecha* fecha){
    return this->recuerdaDatosLector(id,nombre,pass,fecha);
}

void CtrlUsuario::confirmarRegistroLector(){
    Lector* l = new Lector(this->dtLectorRecordado->getIdentificador(), this->dtLectorRecordado->getNombre(),
            this->dtLectorRecordado->getPassword(),this->dtLectorRecordado->getFecha());
    this->manejador->agregarUsuario(l);
    this->eliminarDatosRecordados();
}

void CtrlUsuario::cancelarRegistroLector(){
    this->eliminarDatosRecordados();
}

DtFuncionario* CtrlUsuario::registrarFuncionarioNuevo(std::string id, std::string nombre, 
std::string pass, int nroEmpleado){
    return this->recuerdaDatosFuncionario(id,nombre,pass,nroEmpleado);
}

void CtrlUsuario::confirmarRegistro(){
    Funcionario* f = new Funcionario(this->dtFuncionarioRecordado->getIdentificador(), this->dtFuncionarioRecordado->getNombre(),
            this->dtFuncionarioRecordado->getPassword(),this->dtFuncionarioRecordado->getNumeroEmpleado());
    this->manejador->agregarUsuario(f);
    this->eliminarDatosRecordados();
}

void CtrlUsuario::cancelarRegistro(){
    this->eliminarDatosRecordados();
}

//propios
DtFuncionario* CtrlUsuario::recuerdaDatosFuncionario(std::string id, std::string nombre,
std::string pass, int nroEmpleado){
    DtFuncionario* DtF = new DtFuncionario(id,nombre,pass,nroEmpleado);
    this->dtFuncionarioRecordado = DtF;
    return DtF;
}

DtLector* CtrlUsuario::recuerdaDatosLector(std::string id, std::string nombre,
std::string pass, DtFecha* fecha){
    DtLector* DtL = new DtLector(id,nombre,pass,fecha);
    this->dtLectorRecordado = DtL;
    return DtL;
}

void CtrlUsuario::eliminarDatosRecordados(){
    DtLector* DtL = this->dtLectorRecordado;
    DtFuncionario* DtF = this->dtFuncionarioRecordado;
    
    delete DtL;
    delete DtF;
    
    this->dtFuncionarioRecordado = nullptr;
    this->dtLectorRecordado = nullptr;
}


