#ifndef L_SONDAS_H
#define L_SONDAS_H

#include "sonda.h"
#define Maxtam 100

typedef struct{
    Tsonda item[Maxtam];
    int primeiro;
    int ultimo;
}L_sondas;

void FLvazia_s(L_sondas* lista_s);
int LEhVazia_s(L_sondas* lista_s);
int LInsere_s(L_sondas* lista_s, Tsonda x);
int Lretira_s(L_sondas* lista_s, int p, Tsonda *px);

#endif