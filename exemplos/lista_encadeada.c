#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE_DESCRICAO 20

struct dado_t {
    int chave;
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
    struct nodo_t **corrente = cabeca;
    while (*corrente != NULL && *corrente != nodo_a_deletar){
        corrente = &(*corrente)->proximo;
    }
    if (*corrente == NULL){
        printf("nodo no endereço %p não foi encontrado.\n", nodo_a_deletar);
        return -1;
    }
    *corrente = nodo_a_deletar->proximo;
    free(nodo_a_deletar->dado);
    free(nodo_a_deletar);
    return 0;
}

void imprime_dado(struct dado_t *dado){
    printf("chave:    \t%d\n", dado->chave);
    printf("descrição:\t%s\n", dado->descricao);
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

int main(){

    //TESTANDO A LISTA ENCADEADA

    char valor[SIZE_DESCRICAO];
    struct dado_t *novo_dado;
    
    struct nodo_t *cabeca;
   
    cabeca=NULL;    

    // CRIA REGISTROS E INSERE
    novo_dado=malloc(sizeof(struct dado_t));
    if (novo_dado==NULL) {
        printf("Erro ao alocar memória.\n");
        exit(-1);
    }
    printf("novo_dado => %p.\n", novo_dado);
    novo_dado->chave=1;
    strcpy(novo_dado->descricao,"descricao do item 1");
    imprime_dado(novo_dado);
    insere_nodo(&cabeca, novo_dado);

    novo_dado=malloc(sizeof(struct dado_t));
    novo_dado->chave=2;
    strcpy(novo_dado->descricao,"descricao do item 2");
    imprime_dado(novo_dado);
    insere_nodo(&cabeca, novo_dado);

    novo_dado=malloc(sizeof(struct dado_t));
    novo_dado->chave=3;
    strcpy(novo_dado->descricao,"descricao do item 3");
    imprime_dado(novo_dado);
    insere_nodo(&cabeca, novo_dado);
 
    // PROCURA E APAGA
    struct nodo_t *nodo_procurado;

    nodo_procurado=procura(cabeca, 1);
    if (nodo_procurado==NULL){
        printf("Valor não encontrado.\n");
    } else {
        deleta_nodo(&cabeca, nodo_procurado);
    }

    nodo_procurado=procura(cabeca, 2);
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


