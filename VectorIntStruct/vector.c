#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "vector.h"


struct Vector {
    int tamanio;
    int *datos;
};


// Constructor y destructor
VectorPtr crearVector(int t) {
    VectorPtr v = (VectorPtr) malloc(sizeof(struct Vector));

    v->tamanio = t;
    v->datos = (int *) malloc(sizeof(int) * t);

    return v;
}

void destruirVector(VectorPtr v) {
    free(v->datos);
    free(v);
}

// Operaciones con el vector
void mostrarVector(VectorPtr v) {
    for(int i=0; i<v->tamanio; i++) {
        printf("[%d]", v->datos[i]);
    }
}

void inicializarVector(VectorPtr v) {
    for(int i=0; i<v->tamanio; i++) {
        v->datos[i] = 0;
    }
}

void cambiarTamanio(VectorPtr v, int t) {
    if(t < 1) {
        return;
    }

    free(v->datos);

    v->datos = (int *) malloc(sizeof(int) * t);
    v->tamanio = t;

}

void llenarVectorAleatorios(VectorPtr v, int minimo, int maximo) {
    for(int i=0; i<v->tamanio; i++) {
        v->datos[i] = minimo + (rand() % (maximo - minimo + 1));
    }
}

void llenarVectorAleatoriosSinRepetir(VectorPtr v, int minimo, int maximo) {
    for(int i=0; i<v->tamanio; i++) {
        v->datos[i] = minimo + (rand() % (maximo - minimo + 1));

        for(int j=0; j<i; j++) {
            if(v->datos[i] == v->datos[j]) {
                v->datos[i] = minimo + (rand() % (maximo - minimo + 1));
                j = -1;
            }
        }
    }
}

void ordenamientoBurbuja(VectorPtr v, char s[10]) {
    int aux;

    for(int i=0; i<v->tamanio; i++) {
        for(int j=0; j<v->tamanio-1; j++) {
            if(strcmp(s, "desc") == 0) {
                if(v->datos[j] < v->datos[j+1]) {
                    aux = v->datos[j];
                    v->datos[j] = v->datos[j+1];
                    v->datos[j+1] = aux;
                }
            } else if(strcmp(s, "asc") == 0) {
                if(v->datos[j] > v->datos[j+1]) {
                    aux = v->datos[j];
                    v->datos[j] = v->datos[j+1];
                    v->datos[j+1] = aux;
                }
            }
        }
    }
}

int busquedaSecuencial(VectorPtr v, int d) {
    int posBuscado = -1;

    for(int i=0; i<v->tamanio; i++) {
        if(d == v->datos[i]) {
            posBuscado = i;
            break;
        }
    }

    return posBuscado;
}

int busquedaBinaria(VectorPtr v, int d, int ini, int fin) {

    if(!posicionExiste(v, ini) || !posicionExiste(v, fin)) {
        return -1; // No existe
    }

    int mitad;

    while(ini <= fin) {
        mitad = (ini + fin) / 2;

        if(d > v->datos[mitad]) {
            ini = mitad + 1;
        } else if(d < v->datos[mitad]) {
            fin = mitad - 1;
        } else {
            return mitad;
        }
    }

    return -1;
}

int busquedaBinariaRecursiva(VectorPtr v, int d, int ini, int fin) {

    if(!posicionExiste(v, ini) || !posicionExiste(v, fin)) {
        return -1; // No existe
    }

    if(ini > fin) {
        return -1; // No existe
    }

    int mitad = (ini + fin) / 2;

    if(d > v->datos[mitad]) {
        return busquedaBinariaRecursiva(v, d, mitad + 1, fin);
    }

    if(d < v->datos[mitad]) {
        return busquedaBinariaRecursiva(v, d, ini, mitad - 1);
    }

    return mitad;
}

// Funciones booleanas
int posicionExiste(VectorPtr v, int p) {
    return p >= 0 && p < v->tamanio;
}

// Getters y Setters
int getTamanio(VectorPtr v) {
    return v->tamanio;
}

int *getDatos(VectorPtr v) {
    return v->datos;
}

int getDatoPosicion(VectorPtr v, int p) {
    if(!posicionExiste(v, p)) {
        return -1; // No existe la posicion
    }

    return v->datos[p];
}

void setDatoPosicion(VectorPtr v, int d, int p) {
    if(!posicionExiste(v, p)) {
        return; // No existe la posicion
    }

    v->datos[p] = d;
}
