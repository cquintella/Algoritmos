#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include <math.h>

#define SIZE_NAME 30
#define SIZE_EMAIL 30
#define SIZE_PHONE 17
#define SIZE_ORG 30
#define SIZE_HASH 123  

typedef struct dado {
    char primeiro_nome[SIZE_NAME];
    char ultimo_nome[SIZE_NAME];
    char email[SIZE_EMAIL];
    char telefone[SIZE_PHONE];
    char organizacao[SIZE_ORG];
    char cargo[SIZE_ORG];
} contato_t;

typedef struct nodo_lista{
    struct nodo_lista *proximo;
    struct dado *dado;
} nodo_t;

int hash_simples(char str[]) {
    int sum = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) { 
        sum += str[i];
    }
    return (sum % SIZE_HASH);
}


char *obter_nome_completo(char *primeiro_nome, char *ultimo_nome){
    char *nome_completo = malloc((strlen(primeiro_nome) + strlen(ultimo_nome) + 2) * sizeof(char));
    sprintf(nome_completo, "%s %s", primeiro_nome, ultimo_nome);
    return nome_completo;
}

contato_t *criar_contato(char *primeiro_nome, char *ultimo_nome, char *email, char *telefone, char *organizacao, char *cargo){
    contato_t *contato = malloc(sizeof(contato_t));
    if (contato == NULL){
        printf("Erro de falta de memória.\n");
        return NULL;
    }
    
    strcpy(contato->primeiro_nome, primeiro_nome);
    strcpy(contato->ultimo_nome, ultimo_nome);
    strcpy(contato->email, email);
    strcpy(contato->telefone, telefone);
    strcpy(contato->organizacao, organizacao);
    strcpy(contato->cargo, cargo);
    return contato;
}

contato_t *criar_contato_pelo_teclado() {
    char primeiro_nome[SIZE_NAME];
    char ultimo_nome[SIZE_NAME];
    char email[SIZE_EMAIL];
    char telefone[SIZE_PHONE];
    char organizacao[SIZE_ORG];
    char cargo[SIZE_ORG];
    
    printf("Insira o primeiro nome: ");
    scanf("%s", primeiro_nome);
    
    printf("Insira o último nome: ");
    scanf("%s", ultimo_nome);
    
    printf("Insira o e-mail: ");
    scanf("%s", email);
    
    printf("Insira o telefone: ");
    scanf("%s", telefone);
    
    printf("Insira a organização: ");
    scanf("%s", organizacao);
    
    printf("Insira o cargo: ");
    scanf("%s", cargo);
    
    contato_t *novo_contato = criar_contato(primeiro_nome, ultimo_nome, email, telefone, organizacao, cargo);
    
    return novo_contato;
}

int inserir_contato(contato_t **hash_table, nodo_t **head, contato_t *contato){
    // inserir na lista encadeada
    nodo_t *atual = malloc(sizeof(nodo_t));
    if (atual == NULL){
        printf("Erro de falta de memória.\n");
        return -1;
    }
    atual->dado = contato;
    atual->proximo = *head;
    *head = atual;
    
    // inserir na tabela hash
    char *nome_completo = obter_nome_completo(contato->primeiro_nome, contato->ultimo_nome);
    int index = hash_simples(nome_completo);
    while(hash_table[index] != NULL && index < SIZE_HASH){
        index++;
    }
    if(index < SIZE_HASH){
        hash_table[index] = contato;
        return 0;
    } else {
        printf("Acabou o espaço na tabela\n");
        return -1;
    }
}

int inserir_na_hash(contato_t **hash_table, contato_t *contato){
    char *nome_completo = obter_nome_completo(contato->primeiro_nome, contato->ultimo_nome);
    int index = hash_simples(nome_completo);
    
    while (hash_table[index] != NULL && index < SIZE_HASH){ //procurando vaga
        index++;
    }
    
    if (index < SIZE_HASH){
        hash_table[index] = contato;
        return 0;
    } else {
        printf("Acabou o espaço na tabela\n");
        return -1;
    }
}


// Função para excluir um contato da tabela hash
int excluir_da_tabela_hash(contato_t **hash_table, contato_t *dado) {
    int indice = hash_simples(obter_nome_completo(dado->primeiro_nome, dado->ultimo_nome));
    
    if (hash_table[indice] == NULL) {
        printf("Contato não encontrado.\n");
        return -1;
    }
    
    if (strcmp(hash_table[indice]->primeiro_nome, dado->primeiro_nome) == 0
        && strcmp(hash_table[indice]->ultimo_nome, dado->ultimo_nome) == 0) {
        hash_table[indice] = NULL;
        return 0;
    }
    
    printf("Contato não encontrado.\n");
    return -1;
}

// Função para excluir um contato da lista encadeada
int excluir_da_lista(nodo_t **head, contato_t *contato) {
    nodo_t *atual = *head;
    nodo_t *anterior = NULL;
    
    while (atual != NULL) {
        if (atual->dado == contato) {
            if (anterior == NULL) {
                // Remover primeiro elemento
                *head = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            
            free(atual->dado);
            free(atual);
            return 0;
        }
        
        anterior = atual;
        atual = atual->proximo;
    }
    
    printf("Contato não encontrado.\n");
    return -1;
}

// Função para excluir um contato da lista e da tabela hash
int excluir_contato( contato_t *dado, contato_t **hash_table,nodo_t **head) {
    if (excluir_da_tabela_hash(hash_table, dado) == 0
        && excluir_da_lista(head, dado) == 0) {
        printf("Contato excluído com sucesso.\n");
        return 0;
    }
    
    printf("Erro ao excluir contato.\n");
    return -1;
}

contato_t *buscar_contato(char *primeiro_nome, char *ultimo_nome, contato_t **hash_table){
    int indice = hash_simples(obter_nome_completo(primeiro_nome, ultimo_nome));
    while(hash_table[indice] != NULL) {
        if(strcmp(hash_table[indice]->primeiro_nome, primeiro_nome) == 0 && strcmp(hash_table[indice]->ultimo_nome, ultimo_nome) == 0) {
            return hash_table[indice];
        }
        indice++;
    }
    return NULL;
}

void imprimir_tabela_hash(contato_t **hash_table, int size) {
    printf("---------------- TABELA HASH ----------------\n");
    for (int i = 0; i < size; i++) {
        if (hash_table[i] != NULL) {
            printf("%d: %p -> %s %s\n", i, hash_table[i],hash_table[i]->primeiro_nome, hash_table[i]->ultimo_nome);
        } else {
            printf("%d: %p -> vazio\n", i,hash_table[i]);
        }
    }
}

void imprimir_lista(nodo_t *head) {
    printf("---------------- LISTA ENCADEADA ----------------\n");
    while (head != NULL) {
        printf("%s %s\n", head->dado->primeiro_nome, head->dado->ultimo_nome);
        printf("Email: %s\n", head->dado->email);
        printf("Telefone: %s\n", head->dado->telefone);
        printf("Organização: %s\n", head->dado->organizacao);
        printf("Cargo: %s\n\n", head->dado->cargo);
        head = head->proximo;
    }
}


int main(){
    
    nodo_t *head=NULL;
    contato_t *hash_table[SIZE_HASH];
    memset(hash_table, 0, SIZE_HASH * sizeof(contato_t *));


    inserir_contato(hash_table,&head,criar_contato("Marcelo", "Santos", "marcelo@gmail.com", "11 22222-8228", "Empresa b", "Cargo b"));
    inserir_contato(hash_table,&head,criar_contato("João", "Silva", "joao@gmail.com", "11 99999-8888", "Empresa A", "Cargo A"));
    inserir_contato(hash_table,&head,criar_contato("Maria", "Santos", "maria@gmail.com", "11 99999-7777", "Empresa B", "Cargo B"));
    inserir_contato(hash_table,&head,criar_contato("Pedro", "Oliveira", "pedro@gmail.com", "11 99999-6666", "Empresa C", "Cargo C"));
    inserir_contato(hash_table,&head,criar_contato("Mariana", "Fernandes", "mariana@gmail.com", "11 99999-5555", "Empresa D", "Cargo D"));
    inserir_contato(hash_table,&head,criar_contato("Lucas", "Costa", "lucas@gmail.com", "11 99999-4444", "Empresa E", "Cargo E"));
    
    imprimir_lista(head);
    imprimir_tabela_hash(hash_table, SIZE_HASH);
    printf("Buscando: Marcelo Santos: %p\n",buscar_contato("Marcelo","Santos", hash_table));
    excluir_contato(buscar_contato("Marcelo","Santos", hash_table),hash_table,&head);
    imprimir_lista(head);
    imprimir_tabela_hash(hash_table, SIZE_HASH);
    return 0;
}
