#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED


struct Nodo;
typedef struct Nodo * NodoPtr;
typedef void * DatoPtr;

// Constructor y destructor
NodoPtr crearNodo(DatoPtr dato);
void destruirNodo(NodoPtr nodo);

// Funcion para insertar datos en el arbol
void insertar(NodoPtr nodo, DatoPtr dato, int (*compararDatos)(DatoPtr, DatoPtr));

// Funciones para mostrar los datos del arbol
void preorden(NodoPtr nodo, void (*mostrarDato)(DatoPtr));
void inorden(NodoPtr nodo, void (*mostrarDato)(DatoPtr));
void postorden(NodoPtr nodo, void (*mostrarDato)(DatoPtr));

// Funcion de busqueda
int buscar(NodoPtr nodo, DatoPtr dato, int (*compararDatos)(DatoPtr, DatoPtr));


#endif // ARBOL_H_INCLUDED
