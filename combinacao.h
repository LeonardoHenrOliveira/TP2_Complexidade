#include <stdio.h>
#include <stdlib.h>
#include "L_sondas.h"

void avaliar(Tlista* rochas, int n, int *indices, int *valor_total, int *peso_total);
void combinacoes(int n, int *indices, int pos, Tlista* rochas, int capacidade, int *melhor_valor, int *melhor_peso, int melhor_comb[], int *usadas);
void melhor_combinacao(Tlista* rochas, L_sondas* lista_sondas, int n, int capacidade, int num_sondas);
