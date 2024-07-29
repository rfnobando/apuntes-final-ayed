#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"


struct Animal {
    char tipo[20];
    char nombre[20];
    int edad;
    ListaPtr listaVacunas;
};


AnimalPtr crearAnimal(char tipo[20], char nombre[20], int edad) {
    AnimalPtr animal = (AnimalPtr) malloc(sizeof(struct Animal));

    strcpy(animal->tipo, tipo);
    strcpy(animal->nombre, nombre);
    animal->edad = edad;
    animal->listaVacunas = crearLista();

    return animal;
}

void destruirAnimal(AnimalPtr animal) {
    destruirLista(animal->listaVacunas);
    free(animal);
}

void mostrarAnimal(AnimalPtr animal) {
    printf("----- ANIMAL -----\n");
    printf("Tipo: %s - Nombre: %s - Edad: %d\n\n", animal->tipo, animal->nombre, animal->edad);

    if(obtenerTamanio(animal->listaVacunas) > 0) {
        printf("---- VACUNAS ----\n");
        mostrarListaVoid(animal->listaVacunas, mostrarVacunaVoid);
    }
}

void agregarVacuna(AnimalPtr animal, VacunaPtr vacuna) {
    insertarUltimo(animal->listaVacunas, vacuna);
}

void ordenarVacunasPorCodigo(AnimalPtr animal) {
    if(obtenerTamanio(animal->listaVacunas) > 1) {
        ordenarListaBurbujaAsc(animal->listaVacunas, compararCodigosVacunasVoid);
    }
}

void eliminarVacunaPorNombre(AnimalPtr animal, char nombreVacuna[30]) {
    int posBuscado = busquedaSecuencial(animal->listaVacunas, nombreVacuna, compararNombreVacunaConCadenaVoid);

    if(posBuscado != -1) {
        eliminarPosicion(animal->listaVacunas, posBuscado);
    }
}

