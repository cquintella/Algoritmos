#include <stdio.h>
#include <stdlib.h>

void lerArquivoLinhaPorLinha(const char *nomeArquivo) {
    FILE *arquivo;
    char linha[1000];

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        exit(1);
    }

    while (fscanf(arquivo, "%[^\n]%*c", linha) != EOF) {
        printf("%s\n", linha);
    }

    fclose(arquivo);
}

int main() {
    lerArquivoLinhaPorLinha("arquivo.txt");
    return 0;
}
