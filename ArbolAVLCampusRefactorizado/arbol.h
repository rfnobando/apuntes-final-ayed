#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED


struct Nodo;
typedef struct Nodo * NodoPtr;


NodoPtr crearNodo(int dato);


void insertar(NodoPtr *nodo, int dato);
int buscar(NodoPtr nodo, int dato);
int eliminar(NodoPtr *nodo, int dato);

void preorden(NodoPtr nodo);
void inorden(NodoPtr nodo);
void postorden(NodoPtr nodo);

int obtenerAltura(NodoPtr nodo);
int obtenerDiferenciaAltura(NodoPtr nodo);

void balancerArbol(NodoPtr *nodo);
void rotacionSimpleDerecha(NodoPtr *nodo);
void rotacionSimpleIzquierda(NodoPtr *nodo);

int reordenar(NodoPtr *nodo, NodoPtr * aux_arbol);


#endif // ARBOL_H_INCLUDED
