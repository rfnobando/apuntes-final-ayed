#include <stdio.h>
#include <stdlib.h>

#include "pila.h"


struct Pila {
    NodoPtr primero;
};


PilaPtr crearPila() {
    PilaPtr pila = (PilaPtr) malloc(sizeof(struct Pila));

    pila->primero = NULL;

    return pila;
}

void apilar(PilaPtr pila, DatoPtr dato) {
    if(pila == NULL) {
        return;
    }

    NodoPtr nuevoNodo = crearNodo(dato, pila->primero);
    pila->primero = nuevoNodo;
}

DatoPtr desapilar(PilaPtr pila) {
    if(pila == NULL) {
        return NULL;
    }

    if(pila->primero == NULL) {
        return NULL;
    }

    NodoPtr eliminado = pila->primero;
    DatoPtr datoDesapilado = getDato(eliminado);

    pila->primero = getSiguiente(pila->primero);
    destruirNodo(eliminado);

    return datoDesapilado;
}

void destruirPila(PilaPtr pila) {
    if(pila == NULL) {
        return;
    }

    DatoPtr datoDesapilado = desapilar(pila);

    while(datoDesapilado != NULL) {
        datoDesapilado = desapilar(pila);
    }

    free(pila);
}
