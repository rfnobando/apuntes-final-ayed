#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED


struct Nodo;
typedef struct Nodo * NodoPtr;
typedef void * DatoPtr;

// Constructor y destructor
NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);
void destruirNodo(NodoPtr nodo);


// Getters y Setters
NodoPtr getSiguiente(NodoPtr nodo);
DatoPtr getDato(NodoPtr nodo);
void setSiguiente(NodoPtr nodo, NodoPtr siguiente);
void setDato(NodoPtr nodo, DatoPtr dato);


#endif // NODO_H_INCLUDED
