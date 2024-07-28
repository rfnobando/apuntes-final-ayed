#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"


struct Matriz {
    int filas;
    int columnas;
    int **data;
};


// Constructor y destructor
MatrizPtr crearMatriz(int filas, int columnas) {
    MatrizPtr matriz = (MatrizPtr) malloc(sizeof(struct Matriz));

    matriz->filas = filas;
    matriz->columnas = columnas;

    matriz->data = (int **) malloc(sizeof(int *) * filas);

    for(int i=0; i<filas; i++) {
        matriz->data[i] = (int *) malloc(sizeof(int) * columnas);
    }

    return matriz;
}

void destruirMatriz(MatrizPtr matriz) {
    for(int i=0; i<matriz->filas; i++) {
        free(matriz->data[i]);
    }

    free(matriz->data);
    free(matriz);
}

// Operaciones con la matriz
void inicializarMatriz(MatrizPtr matriz) {
    for(int i=0; i<matriz->filas; i++) {
        for(int j=0; j<matriz->columnas; j++) {
            matriz->data[i][j] = 0;
        }
    }
}

void mostrarMatriz(MatrizPtr matriz) {
    for(int i=0; i<matriz->filas; i++) {
        for(int j=0; j<matriz->columnas; j++) {
            printf("[%d]", matriz->data[i][j]);
        }
        printf("\n");
    }
}

void cambiarTamanio(MatrizPtr matriz, int filas, int columnas) {
    if(filas < 1 || columnas < 1) {
        return;
    }

    for(int i=0; i<matriz->filas; i++) {
        free(matriz->data[i]);
    }

    free(matriz->data);

    matriz->filas = filas;
    matriz->columnas = columnas;

    matriz->data = (int **) malloc(sizeof(int *) * filas);

    for(int i=0; i<matriz->filas; i++) {
        matriz->data[i] = (int *) malloc(sizeof(int) * columnas);
    }

}

void llenarMatrizAleatorios(MatrizPtr matriz, int minimo, int maximo) {
    for(int i=0; i<matriz->filas; i++) {
        for(int j=0; j<matriz->columnas; j++) {
            matriz->data[i][j] = minimo + (rand() % (maximo - minimo + 1));
        }
    }
}

void llenarMatrizAleatoriosSinRepetir(MatrizPtr matriz, int minimo, int maximo) {
    int tamVectorAux = matriz->filas * matriz->columnas;
    int vectorAux[tamVectorAux];

    for(int i=0; i<tamVectorAux; i++) {
        vectorAux[i] = minimo + (rand() % (maximo - minimo + 1));
        for(int j=0; j<i; j++) {
            if(vectorAux[i] == vectorAux[j]) {
                vectorAux[i] = minimo + (rand() % (maximo - minimo + 1));
                j = -1;
            }
        }
    }


    int vectorAuxIndex = 0;
    for(int i=0; i<matriz->filas; i++) {
        for(int j=0; j<matriz->columnas; j++) {
            matriz->data[i][j] = vectorAux[vectorAuxIndex];
            vectorAuxIndex++;
        }
    }
}

// Getters y Setters
int getFilas(MatrizPtr matriz) {
    return matriz->filas;
}

int getColumnas(MatrizPtr matriz) {
    return matriz->columnas;
}

int **getData(MatrizPtr matriz) {
    return matriz->data;
}

int getPosicion(MatrizPtr matriz, int fila, int columna) {
    if(fila >= matriz->filas || columna >= matriz->columnas) {
        return -1; // No existe
    }

    if(fila < 0 || columna < 0) {
        return -1;
    }

    return matriz->data[fila][columna];

}

void setPosicion(MatrizPtr matriz, int fila, int columna, int nuevoDato) {
    if(fila >= matriz->filas || columna >= matriz->columnas) {
        return; // No existe
    }

    if(fila < 0 || columna < 0) {
        return;
    }

    matriz->data[fila][columna] = nuevoDato;
}
