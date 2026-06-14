#include <iostream>
using namespace std;
#include <set>
#include <ctime>
#include "controladores/ICtrlSesion.h"
#include "controladores/ICtrlUsuario.h"
#include "controladores/ICtrlMaterial.h"
#include "controladores/ICtrlPrestamo.h"
#include "controladores/CtrlSesion.h"
#include "controladores/CtrlUsuario.h"
#include "controladores/CtrlMaterial.h"
#include "controladores/CtrlPrestamo.h"
#include "manejadores/ManejadorUsuario.h"
#include "manejadores/ManejadorMaterial.h"
#include "dominio/Lector.h"
#include "dominio/Prestamo.h"
#include "dominio/Libro.h"
#include "dominio/Revista.h"
#include "dt/DtFuncionario.h"
#include "dt/DtFecha.h"
#include "dt/DtLector.h"
#include "Fabrica.h"

DtFecha* obtenerFechaActual() {
    time_t ahora = time(nullptr);
    struct tm* timeinfo = localtime(&ahora);
    int dia = timeinfo->tm_mday;
    int mes = timeinfo->tm_mon + 1;
    int anio = timeinfo->tm_year + 1900;
    return new DtFecha(dia, mes, anio);
}

void cargarDatosDePrueba(ICtrlUsuario* icUsuario, ICtrlMaterial* icMaterial) {
    cout << "\n=== CARGANDO DATOS DE PRUEBA ===\n";

    // Crear lectores
    DtFecha* fecha1 = new DtFecha(15, 3, 2024);
    DtLector* dtL1 = icUsuario->ingresarDatosLector("juan123", "Juan Perez", "pass123", fecha1);
    icUsuario->confirmarRegistroLector();
    cout << "✓ Lector creado: Juan Perez\n";

    DtFecha* fecha2 = new DtFecha(20, 5, 2024);
    DtLector* dtL2 = icUsuario->ingresarDatosLector("maria456", "Maria Garcia", "pass456", fecha2);
    icUsuario->confirmarRegistroLector();
    cout << "✓ Lector creado: Maria Garcia\n";

    // Crear materiales (Libros)
    DtMaterial* dtM1 = icMaterial->recordarDatosMaterial("LIB001", "1984", 1949);
    DtLibro* dtLib1 = icMaterial->recordarDatosLibro(dtM1, "George Orwell", 328);
    icMaterial->confirmarAgregarMaterial();
    cout << "✓ Libro creado: 1984\n";

    DtMaterial* dtM2 = icMaterial->recordarDatosMaterial("LIB002", "El Principito", 1943);
    DtLibro* dtLib2 = icMaterial->recordarDatosLibro(dtM2, "Antoine de Saint-Exupéry", 96);
    icMaterial->confirmarAgregarMaterial();
    cout << "✓ Libro creado: El Principito\n";

    // Crear materiales (Revistas)
    DtMaterial* dtM3 = icMaterial->recordarDatosMaterial("REV001", "National Geographic", 2024);
    DtRevista* dtRev1 = icMaterial->recordarDatosRevista(dtM3, 5, true);
    icMaterial->confirmarAgregarMaterial();
    cout << "✓ Revista creada: National Geographic (Edicion 5, Mensual)\n";

    DtMaterial* dtM4 = icMaterial->recordarDatosMaterial("REV002", "Science Today", 2024);
    DtRevista* dtRev2 = icMaterial->recordarDatosRevista(dtM4, 12, false);
    icMaterial->confirmarAgregarMaterial();
    cout << "✓ Revista creada: Science Today (Edicion 12, No mensual)\n";

    cout << "=== DATOS DE PRUEBA CARGADOS ===\n\n";
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

    cargarDatosDePrueba(icUsuario, icMaterial);

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
                    cout << "Ingrese ID: ";
                    string id;
                    cin >> id;
                    cout << "Ingrese Nombre: ";
                    string nombre;
                    cin >> nombre;
                    cout << "Ingrese Password: ";
                    string pass;
                    cin >> pass;
                    cout << "Ingrese Nro Empleado: ";
                    int nroEmpleado;
                    cin >> nroEmpleado;
                    DtFuncionario* dtF = icUsuario->registrarFuncionarioNuevo(id, nombre, pass, nroEmpleado);
                    cout << "\n=== Confirmar Registro ===\n";
                    cout << "ID: " << dtF->getIdentificador() << "\n";
                    cout << "Nombre: " << dtF->getNombre() << "\n";
                    cout << "Nro Empleado: " << dtF->getNumeroEmpleado() << "\n";
                    cout << "\n¿Confirmar registro? (1=Si, 2=No): ";
                    int confirmacion = 0;
                    cin >> confirmacion;
                    if (confirmacion == 1) {
                        icUsuario->confirmarRegistro();
                        cout << "Funcionario registrado exitosamente\n";
                    } else {
                        icUsuario->cancelarRegistro();
                        cout << "Registro cancelado\n";
                    }
                    break;
                }
                case 3:
                {
                    cout << "--- Registrar Material ---\n";
                    string codigo, titulo;
                    int anio;
                    cout << "Ingrese Codigo: ";
                    cin >> codigo;
                    cout << "Ingrese Titulo: ";
                    cin >> titulo;
                    cout << "Ingrese Anio de Publicacion: ";
                    cin >> anio;

                    DtMaterial* dtM = icMaterial->recordarDatosMaterial(codigo, titulo, anio);

                    cout << "Tipo de Material (1=Libro, 2=Revista): ";
                    int tipo = 0;
                    cin >> tipo;

                    if (tipo == 1) {
                        string autor;
                        int cantPaginas;
                        cout << "Ingrese Autor: ";
                        cin >> autor;
                        cout << "Ingrese Cantidad de Paginas: ";
                        cin >> cantPaginas;

                        DtLibro* dtL = icMaterial->recordarDatosLibro(dtM, autor, cantPaginas);

                        cout << "\n=== Confirmar Registro de Libro ===\n";
                        cout << "Codigo: " << dtL->getCodigo() << "\n";
                        cout << "Titulo: " << dtL->getTitulo() << "\n";
                        cout << "Anio: " << dtL->getAnioPublicacion() << "\n";
                        cout << "Autor: " << dtL->getAutor() << "\n";
                        cout << "Paginas: " << dtL->getCantPaginas() << "\n";
                        cout << "\n¿Confirmar registro? (1=Si, 2=No): ";
                        int confirmacion = 0;
                        cin >> confirmacion;

                        if (confirmacion == 1) {
                            icMaterial->confirmarAgregarMaterial();
                            cout << "Libro registrado exitosamente\n";
                        } else {
                            icMaterial->cancelarAgregar();
                            cout << "Registro cancelado\n";
                        }
                    } else if (tipo == 2) {
                        int nroEdicion;
                        cout << "Ingrese Numero de Edicion: ";
                        cin >> nroEdicion;
                        cout << "¿Es Mensual? (1=Si, 0=No): ";
                        int mensual = 0;
                        cin >> mensual;
                        bool esMensual = (mensual == 1);

                        DtRevista* dtR = icMaterial->recordarDatosRevista(dtM, nroEdicion, esMensual);

                        cout << "\n=== Confirmar Registro de Revista ===\n";
                        cout << "Codigo: " << dtR->getCodigo() << "\n";
                        cout << "Titulo: " << dtR->getTitulo() << "\n";
                        cout << "Anio: " << dtR->getAnioPublicacion() << "\n";
                        cout << "Numero Edicion: " << dtR->getNroEdicion() << "\n";
                        cout << "Es Mensual: " << (dtR->getEsMensual() ? "Si" : "No") << "\n";
                        cout << "\n¿Confirmar registro? (1=Si, 2=No): ";
                        int confirmacion = 0;
                        cin >> confirmacion;

                        if (confirmacion == 1) {
                            icMaterial->confirmarAgregarMaterial();
                            cout << "Revista registrada exitosamente\n";
                        } else {
                            icMaterial->cancelarAgregar();
                            cout << "Registro cancelado\n";
                        }
                    } else {
                        cout << "Tipo de material invalido\n";
                        icMaterial->cancelarAgregar();
                    }
                    break;
                }
                case 4:
                {
                    cout << "--- Registrar Prestamo ---\n";
                    string idLector, codigoMaterial;
                    int dia, mes, anio, cantDias;

                    cout << "Ingrese ID del Lector: ";
                    cin >> idLector;
                    cout << "Ingrese Codigo del Material: ";
                    cin >> codigoMaterial;

                    DtLector* dtLec = icPrestamo->recordarLector(idLector);
                    DtMaterial* dtMat = icPrestamo->recordarMaterial(codigoMaterial);

                    if (dtLec == nullptr) {
                        cout << "Lector no encontrado\n";
                        break;
                    }
                    if (dtMat == nullptr) {
                        cout << "Material no encontrado\n";
                        break;
                    }

                    cout << "\n=== Datos del Lector ===\n";
                    cout << "ID: " << dtLec->getIdentificador() << "\n";
                    cout << "Nombre: " << dtLec->getNombre() << "\n";

                    cout << "\n=== Datos del Material ===\n";
                    cout << "Codigo: " << dtMat->getCodigo() << "\n";
                    cout << "Titulo: " << dtMat->getTitulo() << "\n";

                    cout << "\nIngrese Fecha del Prestamo (dia mes anio): ";
                    cin >> dia >> mes >> anio;
                    cout << "Ingrese Cantidad de Dias Permitidos: ";
                    cin >> cantDias;

                    DtFecha* fechaPrestamo = new DtFecha(dia, mes, anio);
                    DtPrestamo dtP = icPrestamo->recodarDatosPrestamo(fechaPrestamo, cantDias);

                    cout << "\n=== Confirmar Registro de Prestamo ===\n";
                    cout << "Lector: " << dtP.getLector()->getNombre() << "\n";
                    cout << "Material: " << dtP.getMaterial()->getTitulo() << "\n";
                    cout << "Fecha Prestamo: " << dtP.getFechaPrestamo()->getDia() << "/"
                         << dtP.getFechaPrestamo()->getMes() << "/" << dtP.getFechaPrestamo()->getAnio() << "\n";
                    cout << "Dias Permitidos: " << dtP.getCantDiasPrestamo() << "\n";
                    cout << "\n¿Confirmar registro? (1=Si, 2=No): ";
                    int confirmacion = 0;
                    cin >> confirmacion;

                    if (confirmacion == 1) {
                        icPrestamo->confirmarPrestamo();
                        cout << "Prestamo registrado exitosamente\n";
                    } else {
                        icPrestamo->eliminarDatosPrestamo();
                        cout << "Registro cancelado\n";
                    }
                    break;
                }
                case 5:
                {
                    cout << "--- Consultar Prestamos de Lector ---\n";
                    string idLector;
                    cout << "Ingrese ID del Lector: ";
                    cin >> idLector;

                    ManejadorUsuario* mU = ManejadorUsuario::getInstancia();
                    Usuario* u = mU->getUsuario(idLector);

                    if (u == nullptr) {
                        cout << "Lector no encontrado\n";
                        break;
                    }

                    Lector* lector = dynamic_cast<Lector*>(u);
                    if (lector == nullptr) {
                        cout << "Usuario no es un lector\n";
                        break;
                    }

                    cout << "\n=== Prestamos de " << lector->getNombre() << " ===\n";

                    set<Prestamo*> prestamos = lector->obtenerPrestamos();
                    if (prestamos.empty()) {
                        cout << "No tiene prestamos registrados\n";
                        break;
                    }

                    ManejadorMaterial* mM = ManejadorMaterial::getInstancia();
                    int contador = 1;
                    for (Prestamo* p : prestamos) {
                        Material* material = mM->getMaterial(p->getCodigoMaterial());
                        if (material != nullptr) {
                            cout << "\n" << contador << ". Material: " << material->getTitulo() << "\n";
                            cout << "   Codigo: " << material->getCodigo() << "\n";
                            cout << "   Fecha Prestamo: " << p->getFechaPrestamo()->getDia() << "/"
                                 << p->getFechaPrestamo()->getMes() << "/" << p->getFechaPrestamo()->getAnio() << "\n";
                            cout << "   Dias Permitidos: " << p->getCantDiasPrestamo() << "\n";
                            contador++;
                        }
                    }
                    break;
                }
                case 6:
                {
                    cout << "--- Ver Informacion de Material ---\n";
                    string codigoMaterial;
                    cout << "Ingrese Codigo del Material: ";
                    cin >> codigoMaterial;

                    ManejadorMaterial* mM = ManejadorMaterial::getInstancia();
                    Material* material = mM->getMaterial(codigoMaterial);

                    if (material == nullptr) {
                        cout << "Material no encontrado\n";
                        break;
                    }

                    cout << "\n=== Informacion del Material ===\n";
                    cout << "Codigo: " << material->getCodigo() << "\n";
                    cout << "Titulo: " << material->getTitulo() << "\n";
                    cout << "Anio Publicacion: " << material->getAnioPublicacion() << "\n";
                    cout << "Puntaje Promedio: " << material->getPuntajePromedio() << "\n";

                    if (material->esLibro()) {
                        Libro* libro = dynamic_cast<Libro*>(material);
                        if (libro != nullptr) {
                            cout << "Tipo: Libro\n";
                            cout << "Autor: " << libro->getAutor() << "\n";
                            cout << "Cantidad de Paginas: " << libro->getCantPaginas() << "\n";
                        }
                    } else {
                        Revista* revista = dynamic_cast<Revista*>(material);
                        if (revista != nullptr) {
                            cout << "Tipo: Revista\n";
                            cout << "Numero de Edicion: " << revista->getNroEdicion() << "\n";
                            cout << "Es Mensual: " << (revista->getEsMensual() ? "Si" : "No") << "\n";
                        }
                    }
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
