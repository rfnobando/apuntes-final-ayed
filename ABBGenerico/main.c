#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbol.h"
#include "primitivos.h"


int main() {

    int n0 = 25;
    int n1 = 28;
    int n2 = 50;
    int n3 = 18;
    int n4 = 15;
    int n5 = 16;
    int n6 = 27;
    int n7 = 3;
    int n8 = 9;
    int nInexistente = 2;


    NodoPtr raiz = crearNodo(&n0);
    insertar(raiz, &n1, compararIntVoid);
    insertar(raiz, &n2, compararIntVoid);
    insertar(raiz, &n3, compararIntVoid);
    insertar(raiz, &n4, compararIntVoid);
    insertar(raiz, &n5, compararIntVoid);
    insertar(raiz, &n6, compararIntVoid);
    insertar(raiz, &n7, compararIntVoid);
    insertar(raiz, &n8, compararIntVoid);


    printf("PREORDEN\n");
    preorden(raiz, mostrarIntVoid);
    printf("\n\n");

    printf("INORDEN\n");
    inorden(raiz, mostrarIntVoid);
    printf("\n\n");


    printf("POSTORDEN\n");
    postorden(raiz, mostrarIntVoid);
    printf("\n\n");

    int existeEnteroBuscado = buscar(raiz, &nInexistente, compararIntVoid);
    printf("   1: Existe   |   -1: No existe   \n");
    printf("Resultado existe %d: %d\n", nInexistente, existeEnteroBuscado);

    destruirNodo(raiz);

    printf("\n\n\n\n");


    char s1[20] = "Rodrigo";
    char s2[20] = "Maria";
    char s3[20] = "Alberto";
    char s4[20] = "Lorena";
    char s5[20] = "Dario";
    char s6[20] = "Esteban";
    char s7[20] = "Pedro";
    char s8[20] = "Cinthia";
    char sInexistente[20] = "Roberto";


    raiz = crearNodo(s1);
    insertar(raiz, s2, compararCadenaVoid);
    insertar(raiz, s3, compararCadenaVoid);
    insertar(raiz, s4, compararCadenaVoid);
    insertar(raiz, s5, compararCadenaVoid);
    insertar(raiz, s6, compararCadenaVoid);
    insertar(raiz, s7, compararCadenaVoid);
    insertar(raiz, s8, compararCadenaVoid);


    printf("PREORDEN\n");
    preorden(raiz, mostrarCadenaVoid);
    printf("\n\n");

    printf("INORDEN\n");
    inorden(raiz, mostrarCadenaVoid);
    printf("\n\n");


    printf("POSTORDEN\n");
    postorden(raiz, mostrarCadenaVoid);
    printf("\n\n");


    int existeStringBuscado = buscar(raiz, sInexistente, compararCadenaVoid);
    printf("   1: Existe   |   -1: No existe   \n");
    printf("Resultado existe %s: %d\n\n", sInexistente, existeStringBuscado);


    return 0;
}
