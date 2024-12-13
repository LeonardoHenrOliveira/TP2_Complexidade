#ifndef Sonda_h
#define Sonda_h

#include "Compartimento.h"


typedef struct{
    Tlista compartimento;
    int capacidade;
}Sonda;

void Inicializar_Sonda(Sonda* sonda, int capacidade);

#endif