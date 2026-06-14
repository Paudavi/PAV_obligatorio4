#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Material.h"
#include "Funcionario.h"
#include "../dt/DtFecha.h"
#include "../dt/DtLector.h"
#include "../dt/DtMaterial.h"
#include "../dt/DtPrestamo.h"
class Prestamo {
private:
    DtFecha* fechaPrestamo;
    int cantDiasPrestamo;
    std::string codigoMaterial;
public:
    Prestamo(DtFecha* fechaPrestamo, int cantDiasPrestamo, std::string codigoMaterial);
    ~Prestamo();
    DtFecha* getFechaPrestamo();
    int getCantDiasPrestamo();
    std::string getCodigoMaterial();
    DtPrestamo getDatosPrestamo(DtLector* lector, DtMaterial* material);
};
#endif /* PRESTAMO_H */