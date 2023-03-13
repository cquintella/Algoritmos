#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

int main() {
    float numbers[ARRAY_SIZE];
    srand(time(NULL)); // seed o gerador de números aleatórios com o tempo atual
    
    // gerar mil números aleatórios entre 0 e 1
    for(int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = (float)rand()/(float)(RAND_MAX);
    }
    
    // salvar os números em um arquivo binário
    FILE *fptr;
    fptr = fopen("numeros.bin", "wb");
    if(fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fwrite(numbers, sizeof(float), ARRAY_SIZE, fptr);
    fclose(fptr);
    
    printf("Os números foram gerados, ordenados e salvos como arquivo binário.\n");
    
    return 0;
}
