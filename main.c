#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "L_sondas.h"

int mochila(int capacidade, Tlista* rochas, int n, int itens_selecionados[]) {
    // Criar tabela DP
    int dp[n + 1][capacidade + 1];
    int count[n + 1][capacidade + 1]; // Para desempate baseado no número de itens

    // Inicializar tabelas
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacidade; j++) {
            dp[i][j] = 0;
            count[i][j] = 0;
        }
    }

    // Preenchimento da tabela
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= capacidade; j++) {
            if (rochas->rocha[i - 1].usado || rochas->rocha[i - 1].peso > j) {
                // Não usar a rocha (incompatível ou já usada)
                dp[i][j] = dp[i - 1][j];
                count[i][j] = count[i - 1][j];
            } else {
                // Tentar incluir a rocha
                int valor_incluindo = rochas->rocha[i - 1].valor + dp[i - 1][j - rochas->rocha[i - 1].peso];
                int itens_incluindo = 1 + count[i - 1][j - rochas->rocha[i - 1].peso];

                if (valor_incluindo > dp[i - 1][j] ||
                    (valor_incluindo == dp[i - 1][j] && itens_incluindo > count[i - 1][j])) {
                    // Incluir a rocha
                    dp[i][j] = valor_incluindo;
                    count[i][j] = itens_incluindo;
                } else {
                    // Não incluir a rocha
                    dp[i][j] = dp[i - 1][j];
                    count[i][j] = count[i - 1][j];
                }
            }
        }
    }

    // Rastrear itens selecionados
    int capacidade_restante = capacidade;
    for (int i = n; i > 0 && capacidade_restante > 0; i--) {
        if (dp[i][capacidade_restante] != dp[i - 1][capacidade_restante]) {
            itens_selecionados[i - 1] = 1; // A rocha foi selecionada
            capacidade_restante -= rochas->rocha[i - 1].peso;
            rochas->rocha[i - 1].usado = 1; // Marcar como usada
        }
    }

    return dp[n][capacidade];
}


int main(int argc, char const *argv)
{
    clock_t inicio = clock();
    int sonda_capacidade = 40;
    int qnt_sondas = 3;
    int peso_rocha;
    int valor_rocha;
    int N;

    Tlista  entradas;
    L_sondas lista_sonda;

    FILE *arquivo = fopen("arquivo.txt", "r");
    fscanf(arquivo, "%d", &N);

    FLvazia(&entradas);
    FLvazia_s(&lista_sonda);
    
    for(int i = 0; i <= qnt_sondas; i++){
        Tsonda sonda;
        Inicializar_Sonda(&sonda, sonda_capacidade);
        lista_sonda.item[i] = sonda;
    }


    for (int i = 0; i < N; i++){
        Rocha rocha;
        rocha.usado = 0;
        fscanf(arquivo, "%d %d", &peso_rocha, &valor_rocha);
        InicializaRocha(&rocha, valor_rocha, peso_rocha, i);
        LInsere(&entradas, rocha);
    }

    for (int sonda = 1; sonda <= 3; sonda++) {
        int itens_selecionados[N];
        int m;
        for (int i = 0; i < N; i++) {
            itens_selecionados[i] = 0; // Inicializar seleção        
        }
        m = mochila(40, &entradas, N, itens_selecionados);
        printf("\nPESO MAX: %d; ROCHAS: ", m);
        for (int i = 0; i < N; i++) {
            if (itens_selecionados[i]) {
                printf("%d ", i);
            }
        }
    }

    fclose(arquivo);
    
    clock_t fim = clock();

    double execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTEMPO EXECUcao: %.2f\n", execucao);

}
