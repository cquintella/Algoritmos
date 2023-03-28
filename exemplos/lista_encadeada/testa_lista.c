#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lista_encadeada.h"

#define SIZE_DESCRICAO 20


int main(){
    //TESTANDO A LISTA ENCADEADA

    struct dado_t *novo_dado;
    
    struct nodo_t *cabeca;
   
    cabeca=NULL;    

    // CRIA REGISTROS E INSERE
    
    printf("Alocar registro para um novo dado");
    novo_dado=malloc(sizeof(struct dado_t));
   
    if (novo_dado==NULL) {
        printf("Erro ao alocar memória.\n");
        exit(-1);
    }
    printf("... novo_dado no endereco=> %p.\n", novo_dado);

    novo_dado->chave=1;
    strcpy(novo_dado->descricao,"Jose da Silva");
    imprime_dado(novo_dado);
    insere_nodo(&cabeca, novo_dado);


    novo_dado=malloc(sizeof(struct dado_t));
    novo_dado->chave=2;
    strcpy(novo_dado->descricao,"Rafaela Costa");
    imprime_dado(novo_dado);
    insere_nodo(&cabeca, novo_dado);

    novo_dado=malloc(sizeof(struct dado_t));
    novo_dado->chave=3;
    strcpy(novo_dado->descricao,"Roberval Jr.");
    imprime_dado(novo_dado);
    insere_nodo(&cabeca, novo_dado);
 
     novo_dado=malloc(sizeof(struct dado_t));
    novo_dado->chave=5;
    strcpy(novo_dado->descricao,"Marco");
    imprime_dado(novo_dado);
    insere_nodo(&cabeca, novo_dado);

    novo_dado=malloc(sizeof(struct dado_t));
    novo_dado->chave=9;
    strcpy(novo_dado->descricao,"Franca.");
    imprime_dado(novo_dado);
    insere_nodo(&cabeca, novo_dado);

    // PROCURA E APAGA
    struct nodo_t *nodo_procurado;

    nodo_procurado=procura(cabeca, 2);
    if (nodo_procurado==NULL){
        printf("Valor não encontrado.\n");
    } else {
        deleta_nodo(&cabeca, nodo_procurado);
    }

    nodo_procurado=procura(cabeca, 1);
    if (nodo_procurado==NULL){
        printf("Valor não encontrado.\n");
    } else {
        deleta_nodo(&cabeca, nodo_procurado);
    }

    
    nodo_procurado=procura(cabeca, 3);
    if (nodo_procurado==NULL){
        printf("Valor não encontrado.\n");
    } else {
        deleta_nodo(&cabeca, nodo_procurado);
    }

    return 0;

}
