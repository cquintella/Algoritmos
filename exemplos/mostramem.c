//mostramem.c
/* Este prequeno programa mostra como um programa se organiza na memória 
*/


#include <stdio.h>
#include <stdlib.h>

// Variável global não inicializada (armazenada na área BSS)
int global_bss;

int main() {
    // Variável local (armazenada na área stack)
    int local_stack = 10;

    // Alocação dinâmica de memória (armazenada na área heap)
    int* ptr_heap = (int*) malloc(sizeof(int));
    *ptr_heap = 20;

    // Variável estática não inicializada (armazenada na área BSS)
    static int static_bss;

    // Variável estática inicializada (armazenada na área data)
    static int static_data = 30;

    // Calcula o endereço final de cada bloco de memória
    void* end_text = main;
    void* end_heap = ptr_heap + sizeof(int);
    void* end_bss = &static_bss + sizeof(int);
    void* end_stack = &local_stack + sizeof(int);
    void* end_data = &static_data + sizeof(int);

    // Imprime o endereço inicial e final de cada bloco de memória
    printf("ESte programam exemplo mostra como se organiza o programa na memória.");
    printf("Text\n");
    printf("Endereço inicial da função main(): %p\n", main);
    printf("Endereço final da função main(): %p\n", end_text);
    printf("\nHeap\n");
    printf("Endereço inicial da variável alocada dinamicamente: %p\n", ptr_heap);
    printf("Conteúdo da variável alocada dinamicamente: %d\n", *ptr_heap);
    printf("Endereço final da variável alocada dinamicamente: %p\n", end_heap);
    printf("\nBSS\n");
    printf("Endereço inicial da variável global não inicializada: %p\n", &global_bss);
    printf("Endereço inicial da variável estática não inicializada: %p\n", &static_bss);
    printf("Endereço final da variável estática não inicializada: %p\n", end_bss);
    printf("\nStack\n");
    printf("Endereço inicial da variável local: %p\n", &local_stack);
    printf("Endereço final da variável local: %p\n", end_stack);
    printf("\nData\n");
    printf("Endereço inicial da variável estática inicializada: %p\n", &static_data);
    printf("Endereço final da variável estática inicializada: %p\n", end_data);

    // Libera a memória alocada dinamicamente
    free(ptr_heap);

    return 0;
}
