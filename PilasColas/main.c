#include <stdio.h>
#include <stdlib.h>

#include "pila.h"
#include "cola.h"


int main() {

    int n1 = 45;
    int n2 = 31;
    int n3 = 67;
    int n4 = 52;
    int n5 = 12;

    char s1[15] = "Rodrigo";
    char s2[15] = "Dario";
    char s3[15] = "Maria";
    char s4[15] = "Esteban";
    char s5[15] = "Nicolas";

    PilaPtr pila = crearPila();
    ColaPtr cola = crearCola();

    apilar(pila, &n1);
    apilar(pila, &n2);
    apilar(pila, &n3);
    apilar(pila, &n4);
    apilar(pila, &n5);

    printf("Dato desapilado: %d\n", *(int *)desapilar(pila));
    printf("Dato desapilado: %d\n", *(int *)desapilar(pila));
    printf("Dato desapilado: %d\n", *(int *)desapilar(pila));
    printf("Dato desapilado: %d\n", *(int *)desapilar(pila));
    printf("Dato desapilado: %d\n", *(int *)desapilar(pila));

    printf("\n\n");

    apilar(pila, s1);
    apilar(pila, s2);
    apilar(pila, s3);
    apilar(pila, s4);
    apilar(pila, s5);

    printf("Dato desapilado: %s\n", (char *)desapilar(pila));
    printf("Dato desapilado: %s\n", (char *)desapilar(pila));
    printf("Dato desapilado: %s\n", (char *)desapilar(pila));
    printf("Dato desapilado: %s\n", (char *)desapilar(pila));
    printf("Dato desapilado: %s\n", (char *)desapilar(pila));

    printf("\n\n\n");

    encolar(cola, &n1);
    encolar(cola, &n2);
    encolar(cola, &n3);
    encolar(cola, &n4);
    encolar(cola, &n5);

    printf("Dato desencolado: %d\n", *(int *)desencolar(cola));
    printf("Dato desencolado: %d\n", *(int *)desencolar(cola));
    printf("Dato desencolado: %d\n", *(int *)desencolar(cola));
    printf("Dato desencolado: %d\n", *(int *)desencolar(cola));
    printf("Dato desencolado: %d\n", *(int *)desencolar(cola));

    encolar(cola, s1);
    encolar(cola, s2);
    encolar(cola, s3);
    encolar(cola, s4);
    encolar(cola, s5);

    printf("\n\n");

    printf("Dato desencolado: %s\n", (char *)desencolar(cola));
    printf("Dato desencolado: %s\n", (char *)desencolar(cola));
    printf("Dato desencolado: %s\n", (char *)desencolar(cola));
    printf("Dato desencolado: %s\n", (char *)desencolar(cola));
    printf("Dato desencolado: %s\n", (char *)desencolar(cola));

    destruirPila(pila);
    destruirCola(cola);


    return 0;
}



