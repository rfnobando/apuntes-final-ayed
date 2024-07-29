#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;
typedef struct Nodo * NodoPtr;
typedef void * DatoPtr;


NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);
void destruirNodo(NodoPtr nodo);

// Getters y Setters
DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);
void setDato(NodoPtr nodo, DatoPtr dato);
void setSiguiente(NodoPtr nodo, NodoPtr siguiente);


#endif // NODO_H_INCLUDED
