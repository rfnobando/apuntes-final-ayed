#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "primitivos.h"


// int
void mostrarInt(int a) {
    printf("{ %d }", a);
}

void mostrarIntVoid(void *a) {
    mostrarInt(*(int *)a);
}

int compararInt(int a, int b) {
    return (a > b) ? 1 : (a < b) ? -1 : 0;
}

int compararIntVoid(void *a, void *b) {
    return compararInt(*(int *)a, *(int *)b);
}

// float
void mostrarFloat(float a) {
    printf("{ %.2f }", a);
}

void mostrarFloatVoid(void *a) {
    mostrarFloat(*(float *)a);
}

int compararFloat(float a, float b) {
    return (a > b) ? 1 : (a < b) ? -1 : 0;
}

int compararFloatVoid(void *a, void *b) {
    return compararFloat(*(float *)a, *(float *)b);
}

// char
void mostrarChar(char a) {
    printf("{ %c }", a);
}

void mostrarCharVoid(void *a) {
    mostrarChar(*(char *)a);
}

int compararChar(char a, char b) {
    return (a > b) ? 1 : (a < b) ? -1 : 0;
}

int compararCharVoid(void *a, void *b) {
    return compararChar(*(char *)a, *(char *)b);
}

// char *
void mostrarCadena(char *a) {
    printf("{ %s }", a);
}

void mostrarCadenaVoid(void *a) {
    mostrarCadena((char *)a);
}

int compararCadena(char *a, char *b) {
    return strcmp(a, b);
}

int compararCadenaVoid(void *a, void *b) {
    return compararCadena((char *)a, (char *)b);
}
