#include <stdio.h>

void quick_sort(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while (i <= right && arr[i] < pivot) {
            i++;
        }
        while (j >= left + 1 && arr[j] >= pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    int temp = arr[j];
    arr[j] = arr[left];
    arr[left] = temp;
    printf("Vetor após particionamento: ");
    int k;
    for (k = left; k <= right; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

int main() {
    int meu_vetor[12] = {1, 66, 132, 1024, 322, 4, 2, 7, 8, 77, 37, 33};
    int i;
    int size = 12;
    printf("Vetor inicial: ");
    for (i = 0; i < size; i++) {
        printf("%d ", meu_vetor[i]);
    }
    printf("\n");
    quick_sort(meu_vetor, 0, size - 1);
    printf("Vetor Ordenado: ");
    for (i = 0; i < size; i++) {
        printf("%d ", meu_vetor[i]);
    }
    printf("\n");
    return 0;
}
