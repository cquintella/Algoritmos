#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(float *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

float mean(float *arr, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

float stdev(float *arr, int n) {
    float sum = 0, mean_val = mean(arr, n);
    for (int i = 0; i < n; i++) {
        sum += pow(arr[i] - mean_val, 2);
    }
    return sqrt(sum / n);
}

float quartile(float *arr, int n, int quart) {
    sort(arr, n);
    float index = (quart / 4.0) * (n - 1);
    int int_index = (int)index;
    float frac_index = index - int_index;
    if (int_index + 1 < n) {
        return arr[int_index] * (1 - frac_index) + arr[int_index + 1] * frac_index;
    } else {
        return arr[int_index];
    }
}

int main() {
    int n;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);

    float *arr = malloc(n * sizeof(float));

    printf("Entre com os elementos do vetor: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Média: %.2f\n", mean(arr, n));
    printf("Desvio padrão: %.2f\n", stdev(arr, n));
    printf("Quartil 1: %.2f\n", quartile(arr, n, 1));
    printf("Quartil 2: %.2f\n", quartile(arr, n, 2));
    printf("Quartil 3: %.2f\n", quartile(arr, n, 3));

    free(arr);

    return 0;
}
