#include <stdio.h>
#include <stdlib.h>

#include "primitivos.h"
#include "animal.h"



int main() {

    AnimalPtr animal = crearAnimal("Gato", "Juana", 5);
    VacunaPtr vacuna1 = crearVacuna(51952, "FeLV");
    VacunaPtr vacuna2 = crearVacuna(12313, "FVRCP");
    VacunaPtr vacuna3 = crearVacuna(34521, "Rabia");
    VacunaPtr vacuna4 = crearVacuna(15523, "FIP");
    VacunaPtr vacuna5 = crearVacuna(89726, "Clamidiosis");

    agregarVacuna(animal, vacuna1);
    agregarVacuna(animal, vacuna2);
    agregarVacuna(animal, vacuna3);
    agregarVacuna(animal, vacuna4);
    agregarVacuna(animal, vacuna5);

    ordenarVacunasPorCodigo(animal);


    eliminarVacunaPorNombre(animal, "Clamidiosis");

    mostrarAnimal(animal);



    return 0;
}
