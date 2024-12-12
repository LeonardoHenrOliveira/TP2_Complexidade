#include "sonda.h"

#include <stdio.h>
#include <stdlib.h>


void Inicializar_Sonda(Tsonda* sonda, int capacidade){
    sonda->capacidade = capacidade;
    FLvazia(&sonda->compartimento);
}
