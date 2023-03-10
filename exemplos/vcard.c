#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variáveis para armazenar os dados do usuário
    char nome[50], sobrenome[50], email[100];

    // Pedir ao usuário para inserir os dados de contato
    printf("Digite o nome: ");
    scanf("%s", nome);

    printf("Digite o sobrenome: ");
    scanf("%s", sobrenome);

    printf("Digite o email: ");
    scanf("%s", email);

    // Abrir o arquivo para gravação
    FILE *arquivo = fopen("contato.vcf", "w");

    // Verificar se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Gravar o vCard no arquivo
    fprintf(arquivo, "BEGIN:VCARD\n");
    fprintf(arquivo, "VERSION:3.0\n");
    fprintf(arquivo, "N:%s;%s;;;\n", sobrenome, nome);
    fprintf(arquivo, "FN:%s %s\n", nome, sobrenome);
    fprintf(arquivo, "EMAIL:%s\n", email);
    fprintf(arquivo, "END:VCARD\n");

    // Fechar o arquivo
    fclose(arquivo);

    // Exibir mensagem de sucesso
    printf("vCard gravado com sucesso em contato.vcf\n");

    return 0;
}

// https://en.wikipedia.org/wiki/VCard
