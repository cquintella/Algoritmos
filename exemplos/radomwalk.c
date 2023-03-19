#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TAMANHO_GRID 50

void initialize_grid(char grid[TAMANHO_GRID][TAMANHO_GRID]) {
    for (int i = 0; i < TAMANHO_GRID; i++) {
        for (int j = 0; j < TAMANHO_GRID; j++) {
            grid[i][j] = ' ';
        }
    }
}

void print_grid(char grid[TAMANHO_GRID][TAMANHO_GRID], int pos_x, int pos_y) {
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

void take_step(char grid[TAMANHO_GRID][TAMANHO_GRID], int *pos_x, int *pos_y) {
    int direction = rand() % 4;
    int new_pos_x = *pos_x;
    int new_pos_y = *pos_y;
    switch (direction) {
        case 0: // Norte
            if (*pos_y > 0) new_pos_y = *pos_y - 1;
            break;
        case 1: // Leste
            if (*pos_x < TAMANHO_GRID - 1) new_pos_x = *pos_x + 1;
            break;
        case 2: // Sul
            if (*pos_y < TAMANHO_GRID - 1) new_pos_y = *pos_y + 1;
            break;
        case 3: // Oeste
            if (*pos_x > 0) new_pos_x = *pos_x - 1;
            break;
    }

    grid[*pos_y][*pos_x] = '.'; // Marcar a célula atual como visitada
    *pos_x = new_pos_x;
    *pos_y = new_pos_y;
}

int main() {
    srand(time(NULL));
    
    int pos_x = TAMANHO_GRID / 2;
    int pos_y = TAMANHO_GRID / 2;
    
    char grid[TAMANHO_GRID][TAMANHO_GRID];
    initialize_grid(grid);
    
    int steps = 0;
    while (steps < 1000) {
        print_grid(grid, pos_x, pos_y);
        take_step(grid, &pos_x, &pos_y);
        usleep(1000);// Esperar 100 milissegundos
        steps++;
        printf("Passos dados: %d", steps);
    }
    
    return 0;
}
