#include "CtrlPrestamo.h"
#include "../dt/DtPrestamo.h"
#include "../dominio/Prestamo.h"
#include <string>
using namespace std;

CtrlPrestamo* CtrlPrestamo::instancia = nullptr;

CtrlPrestamo::CtrlPrestamo() {
    this->manejador = ManejadorPrestamo::getInstancia();
    this->dtLectorRecordado = nullptr;
    this->dtMaterialRecordado = nullptr;
    this->fechaPrestamoRecordada = nullptr;
    this->cantDiasPrestamoRecordada = 0;
}

CtrlPrestamo::~CtrlPrestamo() {}

CtrlPrestamo* CtrlPrestamo::getInstancia() {
    if (instancia == nullptr) {
        instancia = new CtrlPrestamo();
    }
    return instancia;
}

DtLector* CtrlPrestamo::recordarLector(string idLector) {
    ManejadorUsuario* mU = ManejadorUsuario::getInstancia();
    Usuario* u = mU->getUsuario(idLector);

    if (u != nullptr) {
        Lector* l = dynamic_cast<Lector*>(u);
        if (l != nullptr) {
            this->dtLectorRecordado = l->getDatosLector();
            return this->dtLectorRecordado;
        }
    }
    return nullptr;
}

DtMaterial* CtrlPrestamo::recordarMaterial(string codigoMaterial) {
    ManejadorMaterial* mM = ManejadorMaterial::getInstancia();
    Material* m = mM->getMaterial(codigoMaterial);

    if (m != nullptr) {
        this->dtMaterialRecordado = new DtMaterial(m->getCodigo(), m->getTitulo(), m->getAnioPublicacion());
        return this->dtMaterialRecordado;
    }
    return nullptr;
}

DtPrestamo CtrlPrestamo::recodarDatosPrestamo(DtFecha* fechaPrestamo, int cantDiasPrestamo) {
    this->fechaPrestamoRecordada = fechaPrestamo;
    this->cantDiasPrestamoRecordada = cantDiasPrestamo;
    return DtPrestamo(fechaPrestamo, cantDiasPrestamo, dtLectorRecordado, dtMaterialRecordado);
}

void CtrlPrestamo::confirmarPrestamo() {
    if (dtLectorRecordado != nullptr && dtMaterialRecordado != nullptr &&
        fechaPrestamoRecordada != nullptr && cantDiasPrestamoRecordada > 0) {

        ManejadorUsuario* mU = ManejadorUsuario::getInstancia();
        Usuario* u = mU->getUsuario(dtLectorRecordado->getIdentificador());
        if (u != nullptr) {
            Lector* l = dynamic_cast<Lector*>(u);
            if (l != nullptr) {
                Prestamo* p = l->crearPrestamo(fechaPrestamoRecordada, cantDiasPrestamoRecordada,
                                               dtMaterialRecordado->getCodigo());
                this->manejador->agregarPrestamo(p);
            }
        }
    }
    eliminarDatosPrestamo();
}

void CtrlPrestamo::eliminarDatosPrestamo() {
    delete dtLectorRecordado;
    delete dtMaterialRecordado;
    dtLectorRecordado = nullptr;
    dtMaterialRecordado = nullptr;
    fechaPrestamoRecordada = nullptr;
    cantDiasPrestamoRecordada = 0;
}