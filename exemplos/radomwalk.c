// Uma brincadeira com randomwalk
/* Ainda tem que ajustar */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TAMANHO_GRID 50

// Função que inicializa o grid com espaços em branco
void inicializar_grid(char grid[TAMANHO_GRID][TAMANHO_GRID]) {
    for (int i = 0; i < TAMANHO_GRID; i++) {
        for (int j = 0; j < TAMANHO_GRID; j++) {
            grid[i][j] = ' ';
        }
    }
}

// Função que imprime o grid na tela
void imprimir_grid(char grid[TAMANHO_GRID][TAMANHO_GRID], int pos_x, int pos_y) {
    system("clear"); // Limpar a tela (Linux/Mac)
    //system("cls"); // Limpar a tela (Windows)
    for (int i = 0; i < TAMANHO_GRID; i++) {
        for (int j = 0; j < TAMANHO_GRID; j++) {
            if (i == pos_y && j == pos_x) {
                printf("O"); // Ponto atual
            } else {
                printf("%c", grid[i][j]); // Espaço em branco ou ponto
            }
        }
        printf("\n");
    }
}

// Função que faz um passo do random walk
void dar_passo(char grid[TAMANHO_GRID][TAMANHO_GRID], int *pos_x, int *pos_y) {
    int direcao = rand() % 4;
    int nova_pos_x = *pos_x;
    int nova_pos_y = *pos_y;
    switch (direcao) {
        case 0: // Norte
            if (*pos_y > 0) nova_pos_y = *pos_y - 1;
            break;
        case 1: // Leste
            if (*pos_x < TAMANHO_GRID - 1) nova_pos_x = *pos_x + 1;
            break;
        case 2: // Sul
            if (*pos_y < TAMANHO_GRID - 1) nova_pos_y = *pos_y + 1;
            break;
        case 3: // Oeste
            if (*pos_x > 0) nova_pos_x = *pos_x - 1;
            break;
    }
    
    // Verificar se a nova posição já foi visitada
    if (grid[nova_pos_y][nova_pos_x] == ' ') {
        grid[*pos_y][*pos_x] = '.'; // Deixar um rastro na posição anterior
        *pos_x = nova_pos_x;
        *pos_y = nova_pos_y;
    }
}

int main() {
    // Inicializar o gerador de números aleatórios
    srand(time(NULL));
    
    // Inicializar a posição do ponto de partida
    int pos_x = TAMANHO_GRID / 2;
    int pos_y = TAMANHO_GRID / 2;
    
    // Inicializar o grid com espaços em branco
    char grid[TAMANHO_GRID][TAMANHO_GRID];
    inicializar_grid(grid);
    
    // Fazer o random walk
    int passos=0;
    while (passos<1000) {
        imprimir_grid(grid, pos_x, pos_y);
        dar_passo(grid, &pos_x, &pos_y);
        usleep(100000); // Esperar 100 milissegundos
        passos++;
        printf("Passos dados: %d",passos);
    }
    
    return 0;
} 
