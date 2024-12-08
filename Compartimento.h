#ifndef Compartimento_h
#define Compartimento_h
#include <stdio.h>
#include "Rocha.h"

typedef struct {
    Rocha rocha[1000];
    int primeiro;
    int ultimo;
}Tlista;



void FLvazia(Tlista* lista_s);
int LEhVazia(Tlista* lista_s);
int LInsere(Tlista* lista_s, Rocha x);
int Lretira(Tlista* lista_s, int p, Rocha *px);
void LImprime(Tlista* pLista);

#endif