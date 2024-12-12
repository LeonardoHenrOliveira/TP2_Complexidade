#include <stdio.h>
#include <stdlib.h>
#include "combinacao.h"

void avaliar(Tlista* rochas, int n, int *indices, int *valor_total, int *peso_total) {
    *valor_total = 0;
    *peso_total = 0;
    for (int i = 0; i < n; i++) {
        if (indices[i] == 1) { 
            *valor_total += rochas->rocha[i].valor;
            *peso_total += rochas->rocha[i].peso;
        }
    }
}

void combinacoes(int n, int *indices, int prox, Tlista* rochas, int capacidade, int *melhor_valor, int *melhor_peso, int melhor_comb[], int *usadas) {

    if (prox == n) {
        int valor_total;
        int peso_total;
        avaliar(rochas, n, indices, &valor_total, &peso_total);

        if (peso_total <= capacidade && valor_total > *melhor_valor) {
            *melhor_valor = valor_total;
            *melhor_peso = peso_total;
            for (int i = 0; i < n; i++) {
                melhor_comb[i] = indices[i];
            }
        }
        return;
    }

    if (usadas[prox] == 0) {
        indices[prox] = 1;
        combinacoes(n, indices, prox + 1, rochas, capacidade, melhor_valor, melhor_peso, melhor_comb, usadas);
    }

    indices[prox] = 0;
    combinacoes(n, indices, prox + 1, rochas, capacidade, melhor_valor, melhor_peso, melhor_comb, usadas);
}


void melhor_combinacao(Tlista* rochas, int n, int capacidade, int num_sondas) {
    int usadas[n];
    for (int i = 0; i < n; i++) {
        usadas[i] = 0; 
    }

    for (int sonda = 0; sonda < num_sondas; sonda++) {
        int melhor_valor = 0, melhor_peso = 0;
        int melhor_comb[n];
        int indices[n];

        for (int i = 0; i < n; i++) {
            melhor_comb[i] = 0;
            indices[i] = 0;
        }

        combinacoes(n, indices, 0, rochas, capacidade, &melhor_valor, &melhor_peso, melhor_comb, usadas);

        printf("Sonda %d: Peso %d, Valor %d, Solucao [", sonda + 1, melhor_peso, melhor_valor);
        int primeiro = 1; 
        for (int i = 0; i < n; i++) {
            if (melhor_comb[i]) {
                if (!primeiro) printf(", ");
                printf("%d", i); 
                primeiro = 0;
                usadas[i] = 1; 
            }
        }
        printf("]\n");
    }
}

