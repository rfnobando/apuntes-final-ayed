#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"


struct Lista {
    NodoPtr primero;
};

// Constructor y destructor
ListaPtr crearLista() {
    ListaPtr lista = (ListaPtr) malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
}

void destruirLista(ListaPtr lista) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero != NULL) {
        NodoPtr actual = lista->primero;
        NodoPtr eliminado;

        while(actual != NULL) {
            eliminado = actual;
            actual = getSiguiente(actual);
            destruirNodo(eliminado);
        }
    }

    free(lista);
}

// Funciones basicas de la lista
int obtenerTamanio(ListaPtr lista) {
    if(lista == NULL) {
        return -1; // No hay lista
    }

    NodoPtr actual = lista->primero;
    int contador = 0;

    while(actual != NULL) {
        actual = getSiguiente(actual);
        contador++;
    }

    return contador;
}

void mostrarListaVoid(ListaPtr lista, void (*mostrarDato)(DatoPtr)) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero == NULL) {
        return;
    }

    printf("---------- LISTA ----------\n");

    NodoPtr actual = lista->primero;

    while(actual != NULL) {
        (*mostrarDato)(getDato(actual));
        actual = getSiguiente(actual);
    }

    printf("\n");
}

// Funciones para insertar datos en la lista
void insertarPrimero(ListaPtr lista, DatoPtr dato) {
    if(lista == NULL) {
        return;
    }

    NodoPtr nuevo = crearNodo(dato, lista->primero);
    lista->primero = nuevo;
}

void insertarUltimo(ListaPtr lista, DatoPtr dato) {
    if(lista == NULL) {
        return;
    }

    NodoPtr nuevo = crearNodo(dato, NULL);

    if(lista->primero == NULL) {
        lista->primero = nuevo;
    } else {
        NodoPtr actual = lista->primero;

        while(getSiguiente(actual) != NULL) {
            actual = getSiguiente(actual);
        }

        setSiguiente(actual, nuevo);
    }

}

void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion) {
    if(lista == NULL) {
        return;
    }

    if(posicion < 0 || posicion >= obtenerTamanio(lista)) {
        return;
    }

    if(posicion == 0) {
        insertarPrimero(lista, dato);
        return;
    }

    NodoPtr actual = lista->primero;

    for(int i=0; i<posicion-1; i++) {
        actual = getSiguiente(actual);
    }

    NodoPtr nuevo = crearNodo(dato, getSiguiente(actual));
    setSiguiente(actual, nuevo);

}

// insertarEnOrden -> PRE: La lista tiene que estar ordenada ascendentemente
void insertarEnOrden(ListaPtr lista, DatoPtr dato, int (*comparar)(DatoPtr, DatoPtr)) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero == NULL) {
        insertarPrimero(lista, dato);
        return;
    }

    if((*comparar)(getDato(lista->primero), dato) == 1) {
        insertarPrimero(lista, dato);
        return;
    }

    NodoPtr actual = lista->primero;
    NodoPtr siguiente = getSiguiente(actual);

    while(siguiente != NULL) {
        if((*comparar)(getDato(siguiente), dato) == 1) {
            NodoPtr nuevo = crearNodo(dato, siguiente);
            setSiguiente(actual, nuevo);
            return;
        }

        actual = siguiente;
        siguiente = getSiguiente(actual);
    }

    insertarUltimo(lista, dato);
}

// Funciones para obtener datos de la lista
DatoPtr obtenerPrimero(ListaPtr lista) {
    if(lista == NULL) {
        return NULL;
    }

    if(lista->primero == NULL) {
        return NULL;
    }

    return getDato(lista->primero);
}

DatoPtr obtenerUltimo(ListaPtr lista) {
    if(lista == NULL) {
        return NULL;
    }

    if(lista->primero == NULL) {
        return NULL;
    }

    NodoPtr actual = lista->primero;

    while(getSiguiente(actual) != NULL) {
        actual = getSiguiente(actual);
    }

    return getDato(actual);
}


DatoPtr obtenerPosicion(ListaPtr lista, int posicion) {
    if(lista == NULL) {
        return NULL;
    }

    if(lista->primero == NULL) {
        return NULL;
    }

    int tamLista = obtenerTamanio(lista);

    if(posicion < 0 || posicion >= tamLista) {
        return NULL;
    }

    NodoPtr actual = lista->primero;

    for(int i=0; i<posicion; i++) {
        actual = getSiguiente(actual);
    }

    return getDato(actual);

}

// Funciones para eliminar datos de la lista
void eliminarPrimero(ListaPtr lista) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero == NULL) {
        return;
    }

    NodoPtr eliminado = lista->primero;
    lista->primero = getSiguiente(lista->primero);
    destruirNodo(eliminado);
}

void eliminarUltimo(ListaPtr lista) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero == NULL) {
        return;
    }

    int tamLista = obtenerTamanio(lista);

    if(tamLista == 1) {
        destruirNodo(lista->primero);
        lista->primero = NULL;

        return;
    }

    NodoPtr actual = lista->primero;
    NodoPtr siguiente = getSiguiente(actual);

    while(getSiguiente(siguiente) != NULL) {
        actual = siguiente;
        siguiente = getSiguiente(actual);
    }

    destruirNodo(siguiente);
    setSiguiente(actual, NULL);

}

void eliminarPosicion(ListaPtr lista, int posicion) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero == NULL) {
        return;
    }

    int tamLista = obtenerTamanio(lista);

    if(posicion < 0 || posicion >= tamLista) {
        return;
    }

    if(posicion == 0) {
        eliminarPrimero(lista);
        return;
    }

    NodoPtr actual = lista->primero;

    for(int i=0; i<posicion-1; i++) {
        actual = getSiguiente(actual);
    }

    NodoPtr eliminado = getSiguiente(actual);
    setSiguiente(actual, getSiguiente(eliminado));
    destruirNodo(eliminado);

}

// Funciones para modificar datos de la lista
void modificarPrimero(ListaPtr lista, DatoPtr dato) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero == NULL) {
        return;
    }

    setDato(lista->primero, dato);
}

void modificarUltimo(ListaPtr lista, DatoPtr dato) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero == NULL) {
        return;
    }

    NodoPtr actual = lista->primero;

    while(getSiguiente(actual) != NULL) {
        actual = getSiguiente(actual);
    }

    setDato(actual, dato);
}

void modificarPosicion(ListaPtr lista, DatoPtr dato, int posicion) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero == NULL) {
        return;
    }

    if(posicion == 0) {
        setDato(lista->primero, dato);
        return;
    }

    int tamLista = obtenerTamanio(lista);

    if(posicion > 0 && posicion < tamLista) {
        NodoPtr actual = lista->primero;
        int contador = 0;

        while(contador < tamLista) {
            if(posicion == contador) {
                break;
            }
            actual = getSiguiente(actual);
            contador++;
        }

        setDato(actual, dato);
    }
}

// Operaciones con la lista
ListaPtr duplicarLista(ListaPtr lista) {

    if(lista == NULL) {
        return NULL;
    }

    ListaPtr listaDuplicada = crearLista();
    NodoPtr actual = lista->primero;

    while(actual != NULL) {
        insertarUltimo(listaDuplicada, getDato(actual));
        actual = getSiguiente(actual);
    }

    return listaDuplicada;

}

void ordenarListaBurbujaAsc(ListaPtr lista, int (*compararDatos)(DatoPtr, DatoPtr)) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero == NULL) {
        return;
    }

    int tamLista = obtenerTamanio(lista);

    if(tamLista == 1) {
        return;
    }

    NodoPtr actual;
    NodoPtr siguiente;
    DatoPtr datoAux;

    for(int i=0; i<tamLista; i++) {
        actual = lista->primero;
        siguiente = getSiguiente(actual);

        for(int j=0; j<tamLista-1; j++) {
            if((*compararDatos)(getDato(actual), getDato(siguiente)) == 1) {
                datoAux = getDato(actual);
                setDato(actual, getDato(siguiente));
                setDato(siguiente, datoAux);
            }
            actual = siguiente;
            siguiente = getSiguiente(actual);
        }

    }

}

void ordenarListaSeleccionAsc(ListaPtr lista, int (*compararDatos)(DatoPtr, DatoPtr)) {
    if(lista == NULL) {
        return;
    }

    if(lista->primero == NULL) {
        return;
    }

    int tamLista = obtenerTamanio(lista);

    if(tamLista == 1) {
        return;
    }

    int posMenor;
    DatoPtr aux;

    for(int i=0; i<tamLista-1; i++) {
        posMenor = i;
        for(int j=i; j<tamLista; j++) {
            if((*compararDatos)(obtenerPosicion(lista, posMenor), obtenerPosicion(lista, j)) == 1) {
                posMenor = j;
            }
        }
        aux = obtenerPosicion(lista, i);
        modificarPosicion(lista, obtenerPosicion(lista, posMenor), i);
        modificarPosicion(lista, aux, posMenor);

    }
}

int busquedaSecuencial(ListaPtr lista, DatoPtr datoBuscado, int (*comparar)(DatoPtr, DatoPtr)) {

    if(lista == NULL) {
        return -1; // No existe el elemento
    }

    NodoPtr actual = lista->primero;
    int contador = 0;
    int posBuscado = -1;

    while(actual != NULL) {
        if((*comparar)(datoBuscado, getDato(actual)) == 0) {
            posBuscado = contador;
            break;
        }

        actual = getSiguiente(actual);
        contador++;
    }

    return posBuscado;
}

// busquedaBinaria - PRE: La lista tiene que estar ordenada ascendentemente
int busquedaBinaria(ListaPtr lista, DatoPtr datoBuscado, int inicio, int fin, int (*comparar)(DatoPtr, DatoPtr)) {
    if(lista == NULL) {
        return -1;
    }

    while(inicio <= fin) {
        int mitad = (inicio + fin) / 2;
        int comparacion = (*comparar)(datoBuscado, obtenerPosicion(lista, mitad));

        if(comparacion == 1) {
            inicio = mitad + 1;
        } else if(comparacion == -1) {
            fin = mitad - 1;
        } else {
            return mitad; // Posicion buscado
        }
    }

    return -1; // No encontrado
}

// busquedaBinariaRecursiva - PRE: La lista tiene que estar ordenada ascendentemente
int busquedaBinariaRecursiva(ListaPtr lista, DatoPtr datoBuscado, int inicio, int fin, int (*comparar)(DatoPtr, DatoPtr)) {
    if(lista == NULL) {
        return -1; // No existe
    }

    if(inicio > fin) {
        return -1;
    }

    int mitad = (inicio + fin) / 2;
    DatoPtr datoMitad = obtenerPosicion(lista, mitad);

    int comparacion = (*comparar)(datoBuscado, datoMitad);

    if(comparacion == 1) {
        return busquedaBinariaRecursiva(lista, datoBuscado, mitad + 1, fin, comparar);
    }

    if(comparacion == -1) {
        return busquedaBinariaRecursiva(lista, datoBuscado, inicio, mitad - 1, comparar);
    }

    return mitad;
}
