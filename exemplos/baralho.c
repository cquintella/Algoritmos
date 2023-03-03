#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define TAMANHO_BARALHO 52

// Enumeracao dos naipes
typedef enum {
    ESPADAS,
    COPAS,
    PAUS,
    OUROS
} Naipe;

// Enumeracao dos valores das cartas
typedef enum {
    AS,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE,
    DEZ,
    VALETE,
    DAMA,
    REI,
    CORINGA
} Valor;

// Estrutura da carta
typedef struct {
    Naipe naipe;
    Valor valor;
} Carta;

// Funcao para imprimir o nome da carta
void imprime_carta(Carta c) {
    switch (c.valor) {
        case AS:
            printf("A de ");
            break;
        case DOIS:
            printf("2 de ");
            break;
        case TRES:
            printf("3 de ");
            break;
        case QUATRO:
            printf("4 de ");
            break;
        case CINCO:
            printf("5 de ");
            break;
        case SEIS:
            printf("6 de ");
            break;
        case SETE:
            printf("7 de ");
            break;
        case OITO:
            printf("8 de ");
            break;
        case NOVE:
            printf("9 de ");
            break;
        case DEZ:
            printf("10 de ");
            break;
        case VALETE:
            printf("Valete de ");
            break;
        case DAMA:
            printf("Dama de ");
            break;
        case REI:
            printf("Rei de ");
            break;
        case CORINGA:
            printf("Coringa");
            return;
    }

    switch (c.naipe) {
        case ESPADAS:
            printf("Espadas");
            break;
        case COPAS:
            printf("Copas");
            break;
        case PAUS:
            printf("Paus");
            break;
        case OUROS:
            printf("Ouros");
            break;
    }
}

// Funcao para ler a carta do usuario
Carta ler_carta() {
    Carta c;

    // Ler o valor da carta
    printf("Digite o valor da carta (0-Coringa, 1-A, 2-2, ..., 10-10, 11-Valete, 12-Dama, 13-Rei): ");
    scanf("%d", &c.valor);

    // Ler o naipe da carta
    printf("Digite o naipe da carta (0-Espadas, 1-Copas, 2-Paus, 3-Ouros): ");
    scanf("%d", &c.naipe);

    return c;
}

// Funcao para embaralhar o baralho
void embaralhar(Carta baralho[], int tamanho) {
    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        int j = rand() % tamanho;

        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

Carta sortear_carta(Carta baralho[], int *tamanho) {
    srand(time(NULL));
    int indice = rand() % (*tamanho); // Gerar índice aleatório
    Carta carta_sorteada = baralho[indice];

    // Remover a carta do baralho
    for (int i = indice; i < (*tamanho) - 1; i++) {
        baralho[i] = baralho[i + 1];
    }
    (*tamanho)--;

    return carta_sorteada;
}

void imprime_baralho(Carta baralho[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d - ", i+1);
        imprime_carta(baralho[i]);
        printf("\n");
    }
}

// Funcao para perguntar ao usuario qual carta foi sorteada e verificar se ele acertou
void adivinhar_carta(Carta sorteada) {
    
    // Ler a carta do usuario
    printf("Tente adivinhar a carta sorteada:\n");
    Carta palpite = ler_carta();

    // Verificar se o palpite do usuario esta correto
    if (palpite.naipe == sorteada.naipe && palpite.valor == sorteada.valor) {
        printf("Parabens, voce acertou!\n");
    } else {
        printf("Que pena, voce errou. A carta sorteada era: ");
        imprime_carta(sorteada);
        printf("\n");
    }
}


int main() {
    // Criar o baralho
    int tamanho = TAMANHO_BARALHO;
    Carta baralho[tamanho];
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            baralho[k].naipe = i;
            baralho[k].valor = j;
            k++;
        }
    }

    // Embaralhar o baralho
    embaralhar(baralho, tamanho);

    // Imprimir o baralho
    imprime_baralho(baralho, tamanho);

    Carta carta_sorteada = sortear_carta(baralho, &tamanho);
    adivinhar_carta(carta_sorteada);

    return 0;
}
