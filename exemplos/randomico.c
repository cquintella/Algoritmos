// Gerador de número randomico entre min e max

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_int(int min, int max) {
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    return rand() % (max - min + 1) + min;
}

int main() {
    int min = 0;
    int max = 100;
    int random_number = random_int(min, max);
    printf("Número aleatório entre %d e %d: %d\n", min, max, random_number);
    return 0;
}
