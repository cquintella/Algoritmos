#include <stdio.h>

void selection_sort(int *arr, int size) {
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        printf("Vetor após %dº passo: ", i+1);
        for (j = 0; j < size; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

int main() {
    int meu_vetor[12] = {1, 66, 132, 1024, 322, 4, 2, 7, 8, 77, 37, 33};
    const int size = 12;
    printf("Vetor inicial: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", meu_vetor[i]);
    }
    printf("\n");
    selection_sort(meu_vetor, size);
    printf("Vetor Ordenado: ");
    for (i = 0; i < size; i++) {
        printf("%d ", meu_vetor[i]);
    }
    printf("\n");
    return 0;
}
