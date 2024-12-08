#include "L_sondas.h"
#include <stdio.h>

void FLvazia_s(L_sondas* lista_s){
    lista_s->primeiro = 0;
    lista_s->ultimo = lista_s->primeiro;
};

int LEhVazia_s(L_sondas* lista_s){
    return(lista_s->primeiro == lista_s->ultimo);
};

int LInsere_s(L_sondas* lista_s, Tsonda x){
    if(lista_s->ultimo == Maxtam)
        return 0;
    lista_s->item[lista_s->ultimo++] = x;
    return 1;
};
int Lretira_s(L_sondas* lista_s, int p, Tsonda *px){
    int cont;
    if(LEhVazia_s(lista_s) || p >= lista_s->ultimo || p < 0)
        return 0;
    
    *px = lista_s->item[p];
    for(cont = p+1; cont <= lista_s->ultimo; cont++){
        lista_s->item[cont - 1] = lista_s->item[cont];
    }
    return 1;
};