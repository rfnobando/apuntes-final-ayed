#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"


int main() {
    srand(time(0));

    int tamanio = 5;
    VectorPtr vector = crearVector(tamanio);

    inicializarVector(vector);
    llenarVectorAleatoriosSinRepetir(vector, 11, 15);
    ordenamientoBurbuja(vector, "asc");

    mostrarVector(vector);

    int posBuscado = busquedaSecuencial(vector, 10);

    printf("\n\nEl elemento buscado esta en: %d\n", posBuscado);




    return 0;
}
