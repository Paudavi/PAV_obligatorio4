#include <iostream>
using namespace std;
#include <set>
#include <ctime>
#include "controladores/ICtrlSesion.h"
#include "controladores/ICtrlUsuario.h"
#include "controladores/CtrlSesion.h"
#include "controladores/CtrlUsuario.h"
#include "manejadores/ManejadorUsuario.h"
#include "dt/DtFuncionario.h"
#include "dt/DtFecha.h"
#include "Fabrica.h"

DtFecha* obtenerFechaActual() {
    time_t ahora = time(nullptr);
    struct tm* timeinfo = localtime(&ahora);
    int dia = timeinfo->tm_mday;
    int mes = timeinfo->tm_mon + 1;
    int anio = timeinfo->tm_year + 1900;
    return new DtFecha(dia, mes, anio);
}

int main()
{
    Fabrica *f = Fabrica::getInstancia();
    ICtrlUsuario *icUsuario = f->getICtrlUsuario();
    ICtrlSesion *icSesion = f->getICtrlSesion();
    ICtrlMaterial *icMaterial = f->getICtrlMaterial();
    ICtrlPrestamo *icPrestamo = f->getICtrlPrestamo();

    DtFuncionario *DtRoot = icUsuario->registrarFuncionarioNuevo("root", "root", "root", 0);
    icUsuario->confirmarRegistro();

    cout << "1 - Iniciar Sesion\n";
    cout << "2 - Salir\n";
    cout << "Opcion: ";
    int num = 0;
    cin >> num;
    cout << "\n \n";

    switch (num)
    {
    case 1:
    {
        string id;
        string pass;
        cout << "ID: ";
        cin >> id;

        cout << "PASSWORD: ";
        cin >> pass;
        cout << "\n";

        bool ingresarDatos = icSesion->ingresarDatos(id, pass);
        bool cancela = false;

        if (ingresarDatos == true)
        {
            icSesion->iniciarSesion();

            bool salirMenu = false;
            while (!salirMenu)
            {
                cout << "\n========== MENU PRINCIPAL ==========\n";
                cout << "1 - Registrar Lector\n";
                cout << "2 - Registrar Funcionario\n";
                cout << "3 - Registrar Material\n";
                cout << "4 - Registrar Prestamo\n";
                cout << "5 - Consultar Prestamos de Lector\n";
                cout << "6 - Ver Informacion de Material\n";
                cout << "7 - Cerrar Sesión\n";
                cout << "Opcion: ";
                int menuOpcion = 0;
                cin >> menuOpcion;
                cout << "\n";

                switch (menuOpcion)
                {
                case 1:
                {
                    cout << "--- Registrar Lector ---\n";
                    cout << "Ingrese ID: ";
                    string id;
                    cin >> id;
                    cout << "Ingrese Nombre: ";
                    string nombre;
                    cin >> nombre;
                    cout << "Ingrese Password: ";
                    string pass;
                    cin >> pass;

                    DtFecha* fechaActual = obtenerFechaActual();
                    DtLector* dtL = icUsuario->ingresarDatosLector(id, nombre, pass, fechaActual);

                    cout << "\n=== Confirmar Registro ===\n";
                    cout << "ID: " << dtL->getIdentificador() << "\n";
                    cout << "Nombre: " << dtL->getNombre() << "\n";
                    cout << "Fecha Registro: " << dtL->getFecha()->getDia() << "/"
                         << dtL->getFecha()->getMes() << "/" << dtL->getFecha()->getAnio() << "\n";
                    cout << "\n¿Confirmar registro? (1=Si, 2=No): ";
                    int confirmacion = 0;
                    cin >> confirmacion;

                    if (confirmacion == 1) {
                        icUsuario->confirmarRegistroLector();
                        cout << "Lector registrado exitosamente\n";
                    } else {
                        icUsuario->cancelarRegistroLector();
                        cout << "Registro cancelado\n";
                    }
                    break;
                }
                case 2:
                {
                    cout << "--- Registrar Funcionario ---\n";
                    // TODO: Implementar registro de funcionario
                    break;
                }
                case 3:
                {
                    cout << "--- Registrar Material ---\n";
                    // TODO: Implementar registro de material
                    break;
                }
                case 4:
                {
                    cout << "--- Registrar Prestamo ---\n";
                    // TODO: Implementar registro de prestamo
                    break;
                }
                case 5:
                {
                    cout << "--- Consultar Prestamos de Lector ---\n";
                    // TODO: Implementar consulta de prestamos
                    break;
                }
                case 6:
                {
                    cout << "--- Ver Informacion de Material ---\n";
                    // TODO: Implementar consulta de material
                    break;
                }
                case 7:
                {
                    icSesion->cerrarSesion();
                    salirMenu = true;
                    break;
                }
                default:
                {
                    cout << "Opcion invalida\n";
                }
                }
            }
        }
        else
        {
            while (!ingresarDatos && !cancela)
            {
                int opcion;
                cout << "Las credenciales no son correctas.\n\n";
                cout << "1 - Intentar nuevamente\n";
                cout << "2 - Salir\n";
                cout << "Opcion: ";
                cin >> opcion;
                cout << "\n";
                if (opcion == 1)
                {
                    cout << "ID: ";
                    cin >> id;
                    cout << "PASSWORD: ";
                    cin >> pass;
                    cout << "\n";

                    ingresarDatos = icSesion->ingresarDatos(id, pass);
                    if (ingresarDatos == true)
                    {
                        icSesion->iniciarSesion();
                    }
                }
                else
                {
                    cancela = true;
                }
            }
        }
        break;
    }
    case 2:
    {
        break;
    }
    }
}
