#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "primitivos.h"


/// Int
void mostrarInt(int a) {
    printf("{ %d }", a);
}

void mostrarIntVoid(void *a) {
    mostrarInt(*(int *)a);
}

int compararInt(int a, int b) {
    return (a < b) ? -1 : (a > b) ? 1 : 0;
}

int compararIntVoid(void *a, void *b) {
    return compararInt(*(int *)a, *(int *)b);
}


/// String (char *)
void mostrarString(char a[]) {
    printf("{ %s }", a);
}

void mostrarStringVoid(void *a) {
    mostrarString((char *)a);
}

int compararString(char a[], char b[]) {
    return strcmp(a, b);
}

int compararStringVoid(void *a, void *b) {
    return compararString((char *)a, (char *)b);
}
