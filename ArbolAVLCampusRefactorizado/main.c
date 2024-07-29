#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"


int main() {
    NodoPtr raiz = crearNodo(1);

    insertar(&raiz ,55);
    insertar(&raiz ,24);
    insertar(&raiz ,12);
    insertar(&raiz ,13);


    printf("PREORDEN\n");
    preorden(raiz);
    printf("\n\n");

    printf("INORDEN\n");
    inorden(raiz);
    printf("\n\n");

    printf("POSTORDEN\n");
    postorden(raiz);
    printf("\n\n");




    return 0;
}

