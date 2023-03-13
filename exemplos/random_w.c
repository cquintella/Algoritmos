#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 50

int grid[GRID_SIZE][GRID_SIZE]; // vetor para representar o grid

void move(int *x, int *y) {
    // mover aleatoriamente uma posição na horizontal ou vertical
    int direction = rand() % 4; // gerar um número aleatório entre 0 e 3
    switch(direction) {
        case 0: // mover para cima
            if(*y > 0) (*y)--;
            else (*y)++;
            break;
        case 1: // mover para baixo
            if(*y < GRID_SIZE - 1) (*y)++;
            else (*y)--;
            break;
        case 2: // mover para esquerda
            if(*x > 0) (*x)--;
            else (*x)++;
            break;
        case 3: // mover para direita
            if(*x < GRID_SIZE - 1) (*x)++;
            else (*x)--;
            break;
    }
    
    grid[*y][*x] = 1; // marcar o ponto atual como visitado
}

int main() {
    int x = GRID_SIZE/2;
    int y = GRID_SIZE/2;
    srand(time(NULL)); // seed o gerador de números aleatórios com o tempo atual
    
    // inicializar o grid com zeros
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    
    grid[y][x] = 1; // marcar a posição inicial como visitada
    
    while(1) { // loop infinito
        printf("Posição atual: (%d, %d)\n", x, y);
        
        move(&x, &y); // chamar a função move para gerar uma nova movimentação
        
        // aguardar um segundo antes de continuar o loop
        sleep(1);
    }
    
    return 0;
