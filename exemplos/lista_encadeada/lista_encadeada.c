#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE_DESCRICAO 20

struct dado_t {
    int chave;
    int usu;
    int saldo; 
    char descricao[SIZE_DESCRICAO];
};

struct nodo_t {
    struct dado_t *dado;
    struct nodo_t *proximo;
};


void insere_nodo(struct nodo_t **cabeca, struct dado_t *dado){
    struct nodo_t *novo_nodo = malloc(sizeof(struct nodo_t));
    if (novo_nodo == NULL){ // verificação de erro na alocação de memória
        printf("Erro ao alocar memória.\n");
        exit(-1);
    }
    novo_nodo->dado = dado;
    novo_nodo->proximo = *cabeca;
    *cabeca = novo_nodo;
}

int deleta_nodo(struct nodo_t **cabeca, struct nodo_t *nodo_a_deletar){
    struct nodo_t *corrente , *anterior;
    corrente= anterior = *cabeca;
    
    while (corrente != NULL && corrente != nodo_a_deletar){
        printf("... cabeca= %p, anterior= %p, corrente= %p.\n", *cabeca, anterior, corrente);
        anterior=corrente;
        corrente = corrente->proximo;
    }
    if (corrente == NULL){
        printf("nodo no endereço %p não foi encontrado.\n", nodo_a_deletar);
        return -1;
    }
    anterior->proximo=corrente->proximo;
    free(nodo_a_deletar->dado);
    free(corrente);
    return 0;
}

void imprime_dado(struct dado_t *dado){
    printf("-----------------------------------\n");
    printf("chave:    \t %d \n", dado->chave);
    printf("descrição:\t %s \n", dado->descricao);
    printf("-----------------------------------\n");
}

struct nodo_t *procura(struct nodo_t *cabeca,int item){
    printf("procurando item: %d, a partir de: %p.\n", item, cabeca);
    struct nodo_t *corrente;
    corrente=cabeca;
    while (corrente->dado->chave!=item && corrente->proximo!=NULL){
      corrente=corrente->proximo;
    }
    if (corrente->dado->chave==item){
      printf("Valor procurado está no nodo em: %p.\n",corrente);
      return corrente;
    }
    return NULL; 
}

void insere_no_final(struct nodo_t **cabeca, struct nodo_t *dado){
    dado->proximo = NULL;
    if (*cabeca == NULL){ // lista vazia
        *cabeca = dado;
    } else {
        struct nodo_t *ultimo = *cabeca;
        while (ultimo->proximo != NULL){
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = dado;
    }
}


