#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vacuna.h"


struct Vacuna {
    int codigo;
    char nombre[30];
};


VacunaPtr crearVacuna(int codigo, char nombre[30]) {
    VacunaPtr vacuna = (VacunaPtr) malloc(sizeof(struct Vacuna));

    vacuna->codigo = codigo;
    strcpy(vacuna->nombre, nombre);

    return vacuna;
}

void destruirVacuna(VacunaPtr vacuna) {
    free(vacuna);
}

void mostrarVacuna(VacunaPtr vacuna) {
    printf("--- VACUNA ---\n");
    printf("Codigo: %d - Nombre: %s\n\n", vacuna->codigo, vacuna->nombre);
}

void mostrarVacunaVoid(void *vacuna) {
    mostrarVacuna((VacunaPtr)vacuna);
}

int compararCodigosVacunas(VacunaPtr vacuna1, VacunaPtr vacuna2) {
    return (vacuna1->codigo > vacuna2->codigo) ? 1 : (vacuna1->codigo < vacuna2->codigo) ? -1 : 0;
}

int compararCodigosVacunasVoid(void *vacuna1, void *vacuna2) {
    return compararCodigosVacunas((VacunaPtr)vacuna1, (VacunaPtr)vacuna2);
}

int compararNombreVacunaConCadena(VacunaPtr vacuna, char cadena[30]) {
    return strcmp(vacuna->nombre, cadena);
}

int compararNombreVacunaConCadenaVoid(void *vacuna, void *cadena) {
    return compararNombreVacunaConCadena((VacunaPtr)vacuna, (char *)cadena);
}
