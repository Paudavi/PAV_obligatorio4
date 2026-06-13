
#ifndef DATE_H
#define DATE_H


class DtFecha {
private :
    int dia;
    int mes;
    int anio;
public:
    DtFecha();
    DtFecha(int dia, int mes, int anio);
    DtFecha(DtFecha& DtF);
    bool esFechaValida(int dia, int mes, int anio);
    bool esAnteriorFecha(DtFecha* DtFecha);
    int cantDiasDif(DtFecha* DtFecha);
    
    int getDia();
    int getMes();
    int getAnio();
};



#endif /* DATE_H */

