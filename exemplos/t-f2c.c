// Conversor de Fahrenheight para Celsius.

/* Modifique o programa para aceitar um valor começado por (f ou c) e converta para 
a unidade oposta.*/


#include <stdio.h>

int main(void) {
    float fahrenheit, celsius;
    
    // leitura da temperatura em Fahrenheit
    printf("Conversor de Fahrenheit para Celsius.\n");
    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &fahrenheit);
    
    // conversão para Celsius
    celsius = (fahrenheit - 32) * 5 / 9;
    
    // exibição do resultado
    printf("%.2f graus Fahrenheit equivalem a %.2f graus Celsius\n", fahrenheit, celsius);
    
    return 0;
}
