#ifndef VACUNA_H_INCLUDED
#define VACUNA_H_INCLUDED

struct Vacuna;
typedef struct Vacuna * VacunaPtr;


VacunaPtr crearVacuna(int codigo, char nombre[30]);
void destruirVacuna(VacunaPtr vacuna);

void mostrarVacuna(VacunaPtr vacuna);
void mostrarVacunaVoid(void *vacuna);
int compararCodigosVacunas(VacunaPtr vacuna1, VacunaPtr vacuna2);
int compararCodigosVacunasVoid(void *vacuna1, void *vacuna2);
int compararNombreVacunaConCadena(VacunaPtr vacuna, char cadena[30]);
int compararNombreVacunaConCadenaVoid(void *vacuna, void *cadena);


#endif // VACUNA_H_INCLUDED
