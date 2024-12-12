#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "combinacao.h"

int main() {
    clock_t inicio = clock();
    int capacidade = 40;  
    int num_sondas = 3;   
    int posicao = 0;
    int n, peso, valor;              
    Tlista lista_rochas;
    
    FILE *arquivo = fopen("arquivo.txt", "r");

    fscanf(arquivo, "%d", &n);
    
    FLvazia(&lista_rochas);
    for (int i = 0; i < n; i++) {
        Rocha rochas;
        fscanf(arquivo, "%d %d", &peso, &valor);
        InicializaRocha(&rochas, valor, peso , posicao);
        LInsere(&lista_rochas, rochas);
        posicao++;
    }

    fclose(arquivo);    
    
    melhor_combinacao(&lista_rochas, n, capacidade, num_sondas);
    clock_t fim = clock();

    
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Gasto: %.2f segundos\n", tempo_execucao);
}




/*
void avaliar_combinacao(Tlista* lista_rochas, int n, int *indices, int *valor_total, int *peso_total) {
    *valor_total = 0;
    *peso_total = 0;
    for (int i = 0; i < n; i++) {
        if (indices[i] == 1) { // Verifica se a rocha i está na combinação
            *valor_total += lista_rochas->rocha[i].valor;
            *peso_total += lista_rochas->rocha[i].peso;
        }
    }
}

void resolver_problema(Tlista* lista_rochas, int n, int capacidade, int num_sondas) {
    int usadas[n];
    for (int i = 0; i < n; i++) usadas[i] = 0; 

    for (int sonda = 0; sonda < num_sondas; sonda++) {
        int melhor_valor = 0, melhor_peso = 0;
        int melhor_comb[n];
        for (int i = 0; i < n; i++) {
            melhor_comb[i] = 0; 
        }
        
        int total_combinacoes = pow(2, n);
        for (int comb = 0; comb < total_combinacoes; comb++) {
            int indices[n];
            for (int i = 0; i < n; i++) {
                indices[i] = (comb >> i) & 1; // Extrai o bit i de comb (1 = incluído, 0 = excluído)
            }

            // Avaliar a combinação atual
            int valor_total, peso_total;
            avaliar_combinacao(lista_rochas, n, indices, &valor_total, &peso_total);

            // Verificar se é válida e melhor que a atual
            if (peso_total <= capacidade && valor_total > melhor_valor) {
                melhor_valor = valor_total;
                melhor_peso = peso_total;
                for (int i = 0; i < n; i++) {
                    melhor_comb[i] = indices[i];
                }
            }
        }
        
        // Exibir a melhor solução encontrada para a sonda
        printf("Sonda %d: Peso %d, Valor %d, Solução [", sonda + 1, melhor_peso, melhor_valor);
        for (int i = 0; i < n; i++) {
            if (melhor_comb[i] == 1) {
                printf("%d", i);
                usadas[i] = 1; // Marca a rocha como usada
                if (i < n - 1) printf(", ");
            }
        }
        printf("]\n");

        // Marcar as rochas usadas (removendo-as)
        for (int i = 0; i < n; i++) {
            if (usadas[i] == 1) {
                lista_rochas->rocha[i].peso = 0; // Marca peso 0 para evitar reutilização
                lista_rochas->rocha[i].valor = 0;
            }
        }
    }
}

*/












