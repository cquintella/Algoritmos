
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int numSteps = 0;
    printf("Vetor de entrada: ");
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place   
        for (j = 0; j < n-i-1; j++) {
            printf("j:%d -> comparando arr[j]:%d com arr[j+1]:%d.\n",j,arr[j],arr[j+1]);
            if (arr[j] > arr[j+1]) {
                printf("\t %d é maior que %d, vamos trocar.\n",arr[j] , arr[j+1]);
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } else { 
              printf("\t Nada a fazer\n");
            }
            numSteps++;
        }
        printf("Iteração %d: ", i+1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    printf("Número de passos: %d\n", numSteps);
}

int main() {
    int arr[] = {12, 15, 8, 6, 7, 4, 10, 5, 11, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    return 0;
}
