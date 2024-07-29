#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "nodo.h"

struct Pila;
typedef struct Pila * PilaPtr;

PilaPtr crearPila();
void apilar(PilaPtr pila, DatoPtr dato);
DatoPtr desapilar(PilaPtr pila);
void destruirPila(PilaPtr pila);


#endif // PILA_H_INCLUDED
