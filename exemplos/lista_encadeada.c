#include <stdlib.h>
#include <stdio.h>

// Define a estrutura do nodo
typedef struct nodo{
    int dado;
    struct nodo *proximo;
} nodo_t;


void imprimir_nodo(nodo_t *nodo){
      printf("nodo em: %p\t dado: %d\t proximo: %p.\n", nodo, nodo->dado, nodo->proximo);  
}

nodo_t *criar_nodo(int dado){
    nodo_t *novo_nodo = malloc(sizeof(nodo_t));
    novo_nodo->dado = dado;
    novo_nodo->proximo = NULL;
    return novo_nodo;
}

void inserir_nodo(nodo_t **nodo_inicial, int dado) {
    printf("Inserindo um novo nodo, valor: %d.\n", dado);
  
    nodo_t *novo_nodo = criar_nodo(dado);
    
    if (*nodo_inicial == NULL) {   // criando a lista
        *nodo_inicial = novo_nodo;
        imprimir_nodo(novo_nodo);
    } else {
        nodo_t *nodo_atual=*nodo_inicial;
        while (nodo_atual->proximo != NULL) { // procura o fim da lista
            nodo_atual=nodo_atual->proximo;
        }
        nodo_atual->proximo=novo_nodo;
        imprimir_nodo(novo_nodo);
        
    }
}

nodo_t *procurar_dado(int dado, nodo_t *nodo_inicial){
// A função retorna um ponteiro para o nó que contém o dado procurado ou NULL se o dado não for encontrado na lista.
  
    nodo_t *nodo_atual = nodo_inicial;
    
    while (nodo_atual != NULL) {
        if (nodo_atual->dado == dado) {
            printf ("Achado em nodo: %p.\n", nodo_atual);
            return nodo_atual;
        }
        nodo_atual = nodo_atual->proximo;
    }
    
    // Se chegou aqui, não encontrou o dado
    return NULL;
    printf("nodo não achado.\n");
}








void deletar_nodo(nodo_t *nodo, nodo_t **nodo_inicial){
  nodo_t *nodo_atual = nodo_inicial;
  nodo_t *nodo_anterior = NULL;

  while(nodo_atual != NULL && nodo_atual != nodo) {
    nodo_anterior = nodo_atual;
    nodo_atual = nodo_atual->proximo;
  }

  if (nodo_atual == NULL) {
    printf("Nodo não encontrado na lista.\n");
    return;
  }

  if (nodo_anterior == NULL) {
    // Se o nó a ser removido é o primeiro da lista
    nodo_inicial = nodo_atual->proximo;
  } else {
    // Ajusta o ponteiro do nó anterior para apontar para o próximo nó após o nó a ser removido
    nodo_anterior->proximo = nodo_atual->proximo;
  }

  free(nodo_atual);
}

int main(){
    nodo_t *nodo_inicial = NULL;  // Ou chame de nó_cabeça
    nodo_t *nodo_final = nodo_inicial;
    printf("INICIANDO A LISTA\n");
    printf("O tamanho de um nodo é: %lu bytes\n\n", sizeof(nodo_t));

    
    int dado = 10;
    inserir_nodo(&nodo_inicial, dado);

    dado = 20;
    inserir_nodo(&nodo_inicial, dado);

    dado = 5;
    inserir_nodo(&nodo_inicial, dado);

    dado = 5;
    inserir_nodo(&nodo_inicial, dado);

    nodo_t *nodo_a_deletar;
    nodo_a_deletar=procurar_dado(5, nodo_inicial);
    
    
    if (nodo_a_deletar !=NULL){
      deletar_nodo(nodo_a_deletar, &nodo_inicial);
    } else { 
      printf("Valor não encontrado.\n");
    }
  
    return 0;
}
