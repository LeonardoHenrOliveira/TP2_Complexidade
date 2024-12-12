#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compartimento.h"



void FLvazia(Tlista* comp){
    comp->primeiro = 0;
    comp->ultimo = comp->primeiro;
};

int LEhVazia(Tlista* comp){
    return(comp->primeiro == comp->ultimo);
};

int LInsere(Tlista* comp, Rocha x){
    if(comp->ultimo == 1000)
        return 0;
    comp->rocha[comp->ultimo++] = x;
    return 1;
};
int Lretira(Tlista* comp, int p, Rocha *px){
    int cont;
    if(LEhVazia(comp) || p >= comp->ultimo || p < 0)
        return 0;
    
    *px = comp->rocha[p];
    for(cont = p+1; cont <= comp->ultimo; cont++){
        comp->rocha[cont - 1] = comp->rocha[cont];
    }
    return 1;
};


void LImprime(Tlista* pLista)
{
 int i;
 for (i = pLista->primeiro; i < pLista->ultimo; i++)
 printf("%d : %d %d\n", pLista->rocha[i].posicao, pLista->rocha[i].peso, pLista->rocha[i].valor);
} 