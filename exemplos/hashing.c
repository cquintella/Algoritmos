#include <stdio.h>
#include <string.h>

#define HASH_SIZE 100

unsigned int hashing(char *value) {
    unsigned int hash = 0;
    for (int i = 0; value[i]; i++) {
        hash += (unsigned int) value[i];
    }
    return (hash % HASH_SIZE);
}

int main() {
    char value[100];
    printf("Digite algum texto: ");
    scanf("%s", value);
    printf("\n Simple hash of: %s is %u", value, hashing(value));
    return 0;
}
