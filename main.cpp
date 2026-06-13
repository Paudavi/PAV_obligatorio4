#include <iostream>
#include <set>
#include "controladores/ICtrlSesion.h"
#include "controladores/ICtrlUsuario.h"
#include "controladores/CtrlSesion.h"
#include "controladores/CtrlUsuario.h"
#include "manejadores/ManejadorUsuario.h"
#include "dt/DtFuncionario.h"
#include "Fabrica.h"

int main() {
    Fabrica* f = Fabrica::getInstancia();
    ICtrlUsuario* icUsuario = f->getICtrlUsuario();
    ICtrlSesion* icSesion = f->getICtrlSesion();
    
    DtFuncionario* DtRoot = icUsuario->registrarFuncionarioNuevo("root","root","root",0);
    icUsuario->confirmarRegistro();
    
    std::cout << "1 - Iniciar Sesion\n" ;
    std::cout << "2 - Salir\n" ;
    std::cout << "Opcion: " ;
    int num = 0;
    std::cin >> num;
    std::cout << "\n \n" ;
    
    switch (num) {
        case 1:{
            std::string id;
            std::string pass;
            std::cout << "ID: " ;
            std::cin >> id;
            
            std::cout << "PASSWORD: " ;
            std::cin >> pass;
            std::cout << "\n" ;
            
            bool ingresarDatos = icSesion->ingresarDatos(id,pass);
            bool cancela = false;
            
            if (ingresarDatos == true) {
                icSesion->iniciarSesion();
            } else { 
                while (!ingresarDatos && !cancela) {
                    int opcion;
                    std::cout << "Las credenciales no son correctas.\n\n" ;
                    std::cout << "1 - Intentar nuevamente\n" ;
                    std::cout << "2 - Salir\n" ;
                    std::cout << "Opcion: " ;
                    std::cin >> opcion;
                    std::cout << "\n" ;
                    if (opcion == 1) {
                        std::cout << "ID: " ;
                        std::cin >> id;
                        std::cout << "PASSWORD: " ;
                        std::cin >> pass;
                        std::cout << "\n" ;
                        
                        ingresarDatos = icSesion->ingresarDatos(id,pass);
                        if (ingresarDatos == true) {
                            icSesion->iniciarSesion();
                        }
                    } else {
                        cancela = true;
                    }
                }
            }
            break;
        }
        case 2:{
            break;
         }
}    
    
    
    
    
    
    
    
    
}

