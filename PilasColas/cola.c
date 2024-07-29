#include <stdio.h>
#include <stdlib.h>

#include "cola.h"


struct Cola {
    NodoPtr primero;
    NodoPtr ultimo;
};


ColaPtr crearCola() {
    ColaPtr cola = (ColaPtr) malloc(sizeof(struct Cola));

    cola->primero = NULL;
    cola->ultimo = NULL;

    return cola;
}

void encolar(ColaPtr cola, DatoPtr dato) {
    if(cola == NULL) {
        return;
    }

    NodoPtr nodoNuevo = crearNodo(dato, NULL);

    if(cola->primero == NULL) {
        cola->primero = nodoNuevo;
        cola->ultimo = nodoNuevo;
    } else {
        setSiguiente(cola->ultimo, nodoNuevo);
        cola->ultimo = nodoNuevo;
    }

}

DatoPtr desencolar(ColaPtr cola) {
    if(cola == NULL) {
        return NULL;
    }

    if(cola->primero == NULL) {
        return NULL;
    }

    NodoPtr eliminado = cola->primero;
    DatoPtr datoDesencolado = getDato(cola->primero);
    cola->primero = getSiguiente(cola->primero);
    destruirNodo(eliminado);

    if(cola->primero == NULL) {
        cola->ultimo = NULL;
    }

    return datoDesencolado;
}

void destruirCola(ColaPtr cola) {
    if(cola == NULL) {
        return;
    }

    DatoPtr datoDesencolado = desencolar(cola);

    while(datoDesencolado != NULL) {
        datoDesencolado = desencolar(cola);
    }

    free(cola);
}

