#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"


struct Nodo {
    int dato;
    NodoPtr izquierdo;
    NodoPtr derecho;
};


NodoPtr crearNodo(int dato) {
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;

    return nodo;
}

void insertar(NodoPtr *nodo, int dato){
    if(*nodo == NULL) {
        *nodo = crearNodo(dato);
    } else {
        if((*nodo)->dato == dato) {
            return;
        }

        if((*nodo)->dato < dato) {
            insertar(&((*nodo)->derecho), dato);
        }

        if((*nodo)->dato > dato) {
            insertar(&((*nodo)->izquierdo), dato);
        }
    }

    balancerArbol(nodo);
}





/*
int buscar(NodoPtr nodo, int dato){
    if(nodo == NULL){
        return 0;
    }
    if(nodo->dato == dato){
        return 1;
    }

    if(nodo->dato < dato){
        return buscar(nodo->derecho, dato);
    }
    else{
        return buscar(nodo->izquierdo, dato);
    }
}
*/
/*
int eliminar(NodoPtr *nodo, int dato){
    NodoPtr * aux = NULL;
    if(nodo == NULL){
        return 0;
    }

    if((*nodo)->dato == dato){
        if((*nodo)->derecho == NULL){
            (*nodo) = (*nodo)->izquierdo;
            balancerArbol(nodo);
        }
        else if((*nodo)->izquierdo == NULL){
            (*nodo) = (*nodo)->derecho;
            balancerArbol(nodo);
        }
        else{
            aux = nodo;
            reordenar(&((*nodo)->izquierdo), aux);
            balancerArbol(&((*nodo)->izquierdo));
        }
    }
    else if((*nodo)->dato < dato){
        if((*nodo)->derecho == NULL){
            return 0;
        }
        return eliminar(&((*nodo)->derecho), dato);
    }
    else{
        if((*nodo)->izquierdo == NULL){
            return 0;
        }
        return eliminar(&((*nodo)->izquierdo), dato);
    }

    return 1;
}
*/

void preorden(NodoPtr nodo) {
    if(nodo == NULL){
        return;
    }

    printf(" \t%d ", nodo->dato);
    inorden(nodo->izquierdo);
    inorden(nodo->derecho);
}

void inorden(NodoPtr nodo) {
    if(nodo == NULL){
        return;
    }

    inorden(nodo->izquierdo);
    printf(" \t%d ", nodo->dato);
    inorden(nodo->derecho);
}

void postorden(NodoPtr nodo) {
    if(nodo == NULL){
        return;
    }

    inorden(nodo->izquierdo);
    inorden(nodo->derecho);
    printf(" \t%d ", nodo->dato);
}

int obtenerAltura(NodoPtr nodo){
    int alturaIzquierdo = 0;
    int alturaDerecho = 0;

    if(nodo == NULL){
        return 0;
    }

    alturaIzquierdo = obtenerAltura(nodo->izquierdo);
    alturaDerecho = obtenerAltura(nodo->derecho);

    if(alturaDerecho > alturaIzquierdo){
        return alturaDerecho + 1;
    } else {
        return alturaIzquierdo + 1;
    }
}

void balancerArbol(NodoPtr *nodo) {
    int diferenciaAltura = 0;

    if(nodo == NULL){
        return;
    }

    diferenciaAltura = obtenerDiferenciaAltura(*nodo);

    if(diferenciaAltura > 1) {
        if(obtenerDiferenciaAltura((*nodo)->derecho) >= 1) {
            rotacionSimpleIzquierda(nodo);
        } else {
            rotacionSimpleDerecha(&((*nodo)->derecho));
            rotacionSimpleIzquierda(nodo);
        }
    } else if(diferenciaAltura < -1) {
        if(obtenerDiferenciaAltura((*nodo)->izquierdo) <= -1) {
            rotacionSimpleDerecha(nodo);
        } else {
            rotacionSimpleIzquierda(&((*nodo)->izquierdo));
            rotacionSimpleDerecha(nodo);
        }
    }
}

int obtenerDiferenciaAltura(NodoPtr nodo){
    int altura = 0;

    if(nodo == NULL){
        return 0;
    }

    altura = obtenerAltura(nodo->derecho) - obtenerAltura(nodo->izquierdo);

    return altura;
}

void rotacionSimpleDerecha(NodoPtr *nodo){
    NodoPtr auxiliar = NULL;
    NodoPtr raiz = NULL;
    NodoPtr raizNueva = NULL;


    if(nodo == NULL){
        return;
    }

    raiz = (*nodo);
    raizNueva = (*nodo)->izquierdo;
    auxiliar = (*nodo)->izquierdo->derecho;

    (*nodo) = raizNueva;
    raizNueva->derecho = raiz;
    raiz->izquierdo = auxiliar;
}

void rotacionSimpleIzquierda(NodoPtr *nodo){
    NodoPtr auxiliar = NULL;
    NodoPtr raiz = NULL;
    NodoPtr raizNueva = NULL;

    if(nodo == NULL){
        return;
    }

    raiz = *nodo;
    raizNueva = (*nodo)->derecho;
    auxiliar = (*nodo)->derecho->izquierdo;

    *nodo = raizNueva;
    (*nodo)->izquierdo = raiz;
    raiz->derecho = auxiliar;
}

/*
int reordenar(NodoPtr * nodo, NodoPtr * aux_arbol) {
    if ((*nodo)->derecho == NULL){
        (*aux_arbol)->dato = (*nodo)->dato;
        *nodo = (*nodo)->izquierdo;
    }else
        reordenar(&(*nodo)->derecho, aux_arbol);
    return 1;
}
*/
