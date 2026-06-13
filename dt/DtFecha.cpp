#include "DtFecha.h"
#include <ctime>
#include <stdexcept>

DtFecha::DtFecha() {
    time_t t = time(0);
    tm* now = localtime(&t);

    this->dia = now->tm_mday;
    this->mes = now->tm_mon + 1;    
    this->anio = now->tm_year + 1900;
}
DtFecha::DtFecha(int dia, int mes, int anio) {
    if (!esFechaValida(dia, mes, anio)) {
        throw std::invalid_argument("Fecha invalida");
    }

    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}
DtFecha::DtFecha(DtFecha& DtF){
    this->dia = DtF.dia;
    this->mes = DtF.mes;
    this->anio = DtF.anio;
}

bool DtFecha::esFechaValida(int dia, int mes, int anio) {
    if (anio <= 0) return false;
    if (mes < 1 || mes > 12) return false;
    if (dia < 1) return false;

    int diasMes;

    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasMes = 31;
            break;
        case 4: case 6: case 9: case 11:
            diasMes = 30;
            break;
        case 2:
            // año bisiesto
            if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
                diasMes = 29;
            else
                diasMes = 28;
            break;
    }

    return dia <= diasMes;
}


bool DtFecha::esAnteriorFecha(DtFecha* fecha) {
    if (this->anio < fecha->anio) return true;
    if (this->anio > fecha->anio) return false;

    if (this->mes < fecha->mes) return true;
    if (this->mes > fecha->mes) return false;

    if (this->dia < fecha->dia) return true;

    return false;
}

int DtFecha::cantDiasDif(DtFecha* fecha){
    int dias1 = this->anio * 365 + this->mes * 30 + this->dia;
    int dias2 = fecha->anio * 365 + fecha->mes * 30 + fecha->dia;

    int dif = dias1 - dias2;

    if (dif < 0) dif = -dif;

    return dif;
}

int DtFecha::getDia() {
    return this->dia;
}
int DtFecha::getMes() {
    return this->mes;
}
int DtFecha::getAnio() {
    return this->anio;
};
