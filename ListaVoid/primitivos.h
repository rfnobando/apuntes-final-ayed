#ifndef PRIMITIVOS_H_INCLUDED
#define PRIMITIVOS_H_INCLUDED


// int
void mostrarInt(int a);
void mostrarIntVoid(void *a);
int compararInt(int a, int b);
int compararIntVoid(void *a, void *b);

// float
void mostrarFloat(float a);
void mostrarFloatVoid(void *a);
int compararFloat(float a, float b);
int compararFloatVoid(void *a, void *b);

// char
void mostrarChar(char a);
void mostrarCharVoid(void *a);
int compararChar(char a, char b);
int compararCharVoid(void *a, void *b);

// char *
void mostrarCadena(char *a);
void mostrarCadenaVoid(void *a);
int compararCadena(char *a, char *b);
int compararCadenaVoid(void *a, void *b);


#endif // PRIMITIVOS_H_INCLUDED
