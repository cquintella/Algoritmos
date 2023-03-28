#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#define SIZE_DESCRICAO 20

struct dado_t {
    int chave;
    char descricao[SIZE_DESCRICAO];
};

struct nodo_t {
    struct dado_t *dado;
    struct nodo_t *proximo;
};

void insere_nodo(struct nodo_t **cabeca, struct dado_t *dado);

int deleta_nodo(struct nodo_t **cabeca, struct nodo_t *nodo_a_deletar);
void imprime_dado(struct dado_t *dado);
struct nodo_t *procura(struct nodo_t *cabeca,int item);
void insere_no_final(struct nodo_t **cabeca, struct nodo_t *dado);

#endif
