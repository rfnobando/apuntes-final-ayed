#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include "lista.h"
#include "vacuna.h"

struct Animal;
typedef struct Animal * AnimalPtr;

AnimalPtr crearAnimal(char tipo[20], char nombre[20], int edad);
void destruirAnimal(AnimalPtr animal);

void mostrarAnimal(AnimalPtr animal);

void agregarVacuna(AnimalPtr animal, VacunaPtr vacuna);
void ordenarVacunasPorCodigo(AnimalPtr animal);
void eliminarVacunaPorNombre(AnimalPtr animal, char nombreVacuna[30]);


#endif // ANIMAL_H_INCLUDED
