#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"


struct Nodo {
    DatoPtr dato;
    NodoPtr izquierdo;
    NodoPtr derecho;
};


// Constructor y destructor
NodoPtr crearNodo(DatoPtr dato) {
    NodoPtr nodo = (NodoPtr)malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;

    return nodo;
}

void destruirNodo(NodoPtr nodo) {
    if(nodo != NULL) {
        destruirNodo(nodo->izquierdo);
        destruirNodo(nodo->derecho);
        free(nodo);
    }
}

// Funcion para insertar datos en el arbol
void insertar(NodoPtr nodo, DatoPtr dato, int (*compararDatos)(DatoPtr, DatoPtr)) {
    int comparacion = (*compararDatos)(dato, nodo->dato);

    if(comparacion == -1) {
        if(nodo->izquierdo == NULL) {
            nodo->izquierdo = crearNodo(dato);
        } else {
            insertar(nodo->izquierdo, dato, compararDatos);
        }
    } else if(comparacion == 1) {
        if(nodo->derecho == NULL) {
            nodo->derecho = crearNodo(dato);
        } else {
            insertar(nodo->derecho, dato, compararDatos);
        }
    }
}

// Funciones para mostrar los datos del arbol
void preorden(NodoPtr nodo, void (*mostrarDato)(DatoPtr)) {
    if(nodo != NULL) {
        (*mostrarDato)(nodo->dato);
        preorden(nodo->izquierdo, mostrarDato);
        preorden(nodo->derecho, mostrarDato);
    }
}


void inorden(NodoPtr nodo, void (*mostrarDato)(DatoPtr)) {
    if(nodo != NULL) {
        inorden(nodo->izquierdo, mostrarDato);
        (*mostrarDato)(nodo->dato);
        inorden(nodo->derecho, mostrarDato);
    }
}


void postorden(NodoPtr nodo, void (*mostrarDato)(DatoPtr)) {
    if(nodo != NULL) {
        postorden(nodo->izquierdo, mostrarDato);
        postorden(nodo->derecho, mostrarDato);
        (*mostrarDato)(nodo->dato);
    }
}

// Funcion de busqueda
int buscar(NodoPtr nodo, DatoPtr dato, int (*compararDatos)(DatoPtr, DatoPtr)) {
    if(nodo == NULL) {
        return -1;
    }

    int comparacion = (*compararDatos)(dato, nodo->dato);

    if(comparacion == -1) {
        return buscar(nodo->izquierdo, dato, compararDatos);
    }

    if(comparacion == 1) {
        return buscar(nodo->derecho, dato, compararDatos);
    }

    return 1;
}
