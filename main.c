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
    L_sondas lista_sondas;

    FLvazia_s(&lista_sondas);
    for (int i = 0; i <= num_sondas; i++)
    {
        Sonda sonda;
        Inicializar_Sonda(&sonda, capacidade);
        LInsere_s(&lista_sondas, sonda);
    }
    
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
    
    melhor_combinacao(&lista_rochas, &lista_sondas, n, capacidade, num_sondas);
    clock_t fim = clock();

    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Gasto: %.2f segundos\n", tempo_execucao);
    printf("===================================================\n");
}


