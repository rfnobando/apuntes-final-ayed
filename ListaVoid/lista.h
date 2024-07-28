#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"


struct Lista;
typedef struct Lista * ListaPtr;

// Constructor y destructor
ListaPtr crearLista();
void destruirLista(ListaPtr lista);

// Funciones basicas de la lista
int obtenerTamanio(ListaPtr lista);
void mostrarListaVoid(ListaPtr lista, void (*mostrarDato)(DatoPtr));

// Funciones para insertar datos en la lista
void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);
// insertarEnOrden -> PRE: La lista tiene que estar ordenada ascendentemente
void insertarEnOrden(ListaPtr lista, DatoPtr dato, int (*comparar)(DatoPtr, DatoPtr));

// Funciones para obtener datos de la lista
DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int posicion);

// Funciones para eliminar datos de la lista
void eliminarPrimero(ListaPtr lista);
void eliminarUltimo(ListaPtr lista);
void eliminarPosicion(ListaPtr lista, int posicion);

// Funciones para modificar datos de la lista
void modificarPrimero(ListaPtr lista, DatoPtr dato);
void modificarUltimo(ListaPtr lista, DatoPtr dato);
void modificarPosicion(ListaPtr lista, DatoPtr dato, int posicion);

// Operaciones con la lista
ListaPtr duplicarLista(ListaPtr lista);
void ordenarListaBurbujaAsc(ListaPtr lista, int (*compararDatos)(DatoPtr, DatoPtr));
void ordenarListaSeleccionAsc(ListaPtr lista, int (*compararDatos)(DatoPtr, DatoPtr));
int busquedaSecuencial(ListaPtr lista, DatoPtr datoBuscado, int (*comparar)(DatoPtr, DatoPtr));
// busquedaBinaria -> PRE: La lista tiene que estar ordenada ascendentemente
int busquedaBinaria(ListaPtr lista, DatoPtr datoBuscado, int inicio, int fin, int (*comparar)(DatoPtr, DatoPtr));
// busquedaBinariaRecursiva -> PRE: La lista tiene que estar ordenada ascendentemente
int busquedaBinariaRecursiva(ListaPtr lista, DatoPtr datoBuscado, int inicio, int fin, int (*comparar)(DatoPtr, DatoPtr));


#endif // LISTA_H_INCLUDED
