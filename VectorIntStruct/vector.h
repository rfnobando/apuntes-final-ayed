#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED


struct Vector;
typedef struct Vector * VectorPtr;


// Constructor y destructor
VectorPtr crearVector(int t);
void destruirVector(VectorPtr v);

// Operaciones con el vector
void mostrarVector(VectorPtr v);
void inicializarVector(VectorPtr v); // Inicializa en 0 todas las posiciones
void cambiarTamanio(VectorPtr v, int t);
void llenarVectorAleatorios(VectorPtr v, int minimo, int maximo);
void llenarVectorAleatoriosSinRepetir(VectorPtr v, int minimo, int maximo);
void ordenamientoBurbuja(VectorPtr v, char s[10]);
int busquedaSecuencial(VectorPtr v, int d);
int busquedaBinaria(VectorPtr v, int d, int ini, int fin);
int busquedaBinariaRecursiva(VectorPtr v, int d, int ini, int fin);

// Funciones booleanas
int posicionExiste(VectorPtr v, int p);

// Getters y Setters
int getTamanio(VectorPtr v);
int *getDatos(VectorPtr v);
int getDatoPosicion(VectorPtr v, int p);

void setDatoPosicion(VectorPtr v, int d, int p);



#endif // VECTOR_H_INCLUDED
