#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

struct Nodo {
    DatoPtr dato;
    NodoPtr siguiente;
};


NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente) {
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;
}

void destruirNodo(NodoPtr nodo) {
    free(nodo);
}

// Getters y Setters
DatoPtr getDato(NodoPtr nodo) {
    return nodo->dato;
}

NodoPtr getSiguiente(NodoPtr nodo) {
    return nodo->siguiente;
}

void setDato(NodoPtr nodo, DatoPtr dato) {
    nodo->dato = dato;
}

void setSiguiente(NodoPtr nodo, NodoPtr siguiente) {
    nodo->siguiente = siguiente;
}
