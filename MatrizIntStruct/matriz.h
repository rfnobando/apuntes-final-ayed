#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED


struct Matriz;
typedef struct Matriz * MatrizPtr;

// Constructor y destructor
MatrizPtr crearMatriz(int filas, int columnas);
void destruirMatriz(MatrizPtr matriz);

// Operaciones con la matriz
void inicializarMatriz(MatrizPtr matriz);
void mostrarMatriz(MatrizPtr matriz);
void cambiarTamanio(MatrizPtr matriz, int filas, int columnas);
void llenarMatrizAleatorios(MatrizPtr matriz, int minimo, int maximo);
void llenarMatrizAleatoriosSinRepetir(MatrizPtr matriz, int minimo, int maximo);

// Getters y Setters
int getFilas(MatrizPtr matriz);
int getColumnas(MatrizPtr matriz);
int **getData(MatrizPtr matriz);
int getPosicion(MatrizPtr matriz, int fila, int columna);
void setPosicion(MatrizPtr matriz, int fila, int columna, int nuevoDato);


#endif // MATRIZ_H_INCLUDED
