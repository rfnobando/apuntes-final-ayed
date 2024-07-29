#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "nodo.h"

struct Cola;
typedef struct Cola * ColaPtr;


ColaPtr crearCola();
void encolar(ColaPtr cola, DatoPtr dato);
DatoPtr desencolar(ColaPtr cola);
void destruirCola(ColaPtr cola);


#endif // COLA_H_INCLUDED
