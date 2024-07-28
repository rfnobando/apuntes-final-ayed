#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"


int main() {

    MatrizPtr matriz = crearMatriz(3, 5);

    inicializarMatriz(matriz);
    llenarMatrizAleatoriosSinRepetir(matriz, 0, 14);

    mostrarMatriz(matriz);



    return 0;
}
