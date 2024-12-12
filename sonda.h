#ifndef Sonda_h
#define Sonda_h

#include "Compartimento.h"


typedef struct{
    Tlista compartimento;
    int capacidade;
}Tsonda;

void Inicializar_Sonda(Tsonda* sonda, int capacidade);

#endif