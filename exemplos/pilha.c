#include <stdio.h>
#define TAMANHO 5
int pilha[TAMANHO];
int topo;
int fundo;

int push (int valor) {
    if ((topo < TAMANHO-1) ){
       topo++;
       pilha[topo]=valor;
       return 0;
     } 
       printf( "Erro: Pilha cheia ou vazia.\n");
       return -1;
}

int pop () {
  int valor=0;
  if (topo>=fundo) {
     valor = pilha[topo];
     topo--;
     return valor;
  }
  printf("ERRO: Tentou tirar com pilha vazia\n");
  return 0;
}

int top(){
  return pilha[topo];
}

int main () {
     topo=-1;
     fundo=0;

  
     push(10);
     push(1);
     push (100);
     push (6);
     push (33);
     push (42);

     imprime_pilha();
  
     printf ("faz pop ->%d\n", pop());
     printf ("faz pop ->%d\n", pop());
     printf ("faz pop ->%d\n", pop());
     printf ("faz pop ->%d\n", pop());
     printf ("faz pop ->%d\n", pop());
     printf ("faz pop ->%d\n", pop());
    
  
}
