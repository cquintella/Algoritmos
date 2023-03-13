#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000

int main() {
    float numbers[ARRAY_SIZE];
    
    // abrir o arquivo binário para leitura
    FILE *fptr;
    fptr = fopen("numeros.bin", "rb");
    if(fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    
    // ler os números do arquivo e carregar no vetor
    fread(numbers, sizeof(float), ARRAY_SIZE, fptr);
    
    fclose(fptr);
    
    // exibir os números carregados
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%.2f ", numbers[i]);
    }
    
    return 0;
}
