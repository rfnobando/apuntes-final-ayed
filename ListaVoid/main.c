#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "primitivos.h"


int main() {

    ListaPtr lista = crearLista();

    int n1 = 54;
    int n2 = 32;
    int n3 = 47;
    int n4 = 21;
    int n5 = 17;
    int n6 = 68;
    int nMod = 70;

    insertarUltimo(lista, &n1);
    insertarUltimo(lista, &n2);
    insertarUltimo(lista, &n3);
    insertarUltimo(lista, &n4);
    insertarUltimo(lista, &n5);
    insertarPosicion(lista, &n6, 4);

    ordenarListaBurbujaAsc(lista, compararIntVoid);
    mostrarListaVoid(lista, mostrarIntVoid);

    printf("\n\n");

    printf("Dato primero: %d\n", *(int *)obtenerPrimero(lista));
    printf("Dato ultimo: %d\n", *(int *)obtenerUltimo(lista));
    printf("Dato posicion 5: %d\n", *(int *)obtenerPosicion(lista, 5));




    return 0;
}
