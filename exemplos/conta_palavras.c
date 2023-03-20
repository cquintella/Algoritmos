#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRA 100

typedef struct {
    char texto[MAX_PALAVRA];
    int ocorrencias;
} Palavra;

void ordena_palavras(Palavra *palavras, int n) {
    int i, j;
    Palavra temp;

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (palavras[i].ocorrencias < palavras[j].ocorrencias) {
                temp = palavras[i];
                palavras[i] = palavras[j];
                palavras[j] = temp;
            }
        }
    }
}

int main() {
    char nome_arquivo_entrada[MAX_PALAVRA], nome_arquivo_saida[MAX_PALAVRA], palavra[MAX_PALAVRA];
    FILE *arquivo_entrada, *arquivo_saida;
    int i, n, encontrada;
    Palavra *palavras = NULL;

    // Lê o nome do arquivo de entrada
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nome_arquivo_entrada);

    // Abre o arquivo de entrada
    arquivo_entrada = fopen(nome_arquivo_entrada, "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir arquivo de entrada.\n");
        exit(EXIT_FAILURE);
    }

    // Lê as palavras do arquivo de entrada e armazena na estrutura de dados
    n = 0;
    while (fscanf(arquivo_entrada, "%s", palavra) == 1) {
        // Verifica se a palavra já está na lista
        encontrada = 0;
        for (i = 0; i < n; i++) {
            if (strcmp(palavras[i].texto, palavra) == 0) {
                encontrada = 1;
                palavras[i].ocorrencias++;
                break;
            }
        }

        // Se a palavra não foi encontrada, adiciona na lista
        if (!encontrada) {
            n++;
            palavras = realloc(palavras, n * sizeof(Palavra));
            strcpy(palavras[n-1].texto, palavra);
            palavras[n-1].ocorrencias = 1;
        }
    }

    // Fecha o arquivo de entrada
    fclose(arquivo_entrada);

    // Ordena as palavras pelo número de ocorrências
    ordena_palavras(palavras, n);

    // Pede o nome do arquivo de saída
    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nome_arquivo_saida);

    // Abre o arquivo de saída
    arquivo_saida = fopen(nome_arquivo_saida, "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar arquivo de saída.\n");
        exit(EXIT_FAILURE);
    }

    // Grava a lista de palavras ordenada no arquivo de saída
    for (i = 0; i < n; i++) {
        fprintf(arquivo_saida, "%s: %d\n", palavras[i].texto, palavras[i].ocorrencias);
    }

    // Fecha o arquivo de saída
    fclose(arquivo_saida);

    // Libera a memória alocada para a estrutura de dados
    free(palavras);

    return 0;
  }
