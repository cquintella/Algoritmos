    #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NOMES 50
#define MAX_SOBRENOMES 50


// Struct que armazena nome e sobrenome gerados aleatoriamente
typedef struct {
    char nome[MAX_TAM_NOME];
    char sobrenome[MAX_TAM_SOBRENOME];
} Pessoa;

Pessoa gerar_pessoa(char nomes[][MAX_TAM_NOME], char sobrenomes[][MAX_TAM_SOBRENOME], int qtd_nomes, int qtd_sobrenomes) {
    Pessoa pessoa;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera um nome aleatório
    int indice_nome = rand() % qtd_nomes;
    strncpy(pessoa.nome, nomes[indice_nome], MAX_TAM_NOME);
    pessoa.nome[MAX_TAM_NOME - 1] = '\0';

    // Gera um sobrenome aleatório
    int indice_sobrenome = rand() % qtd_sobrenomes;
    strncpy(pessoa.sobrenome, sobrenomes[indice_sobrenome], MAX_TAM_SOBRENOME);
    pessoa.sobrenome[MAX_TAM_SOBRENOME - 1] = '\0';

    return pessoa;
}

int main(){
      
      char* nomes_masc[] = {
        "João", "Pedro", "Lucas", "Mateus", "Gabriel", "Felipe", "Rafael",
        "Gustavo", "Leonardo", "Bruno", "Thiago", "Rodrigo", "Vinicius",
        "Luciano", "Daniel", "Lucas", "Fernando", "Marcelo", "Lucas",
        "André", "Alexandre", "Carlos", "Eduardo", "Guilherme", "Igor",
        "Juliano", "Leandro", "Marcelo", "Nelson", "Pablo", "Renato",
        "Ricardo", "Rogério", "Sérgio", "Thales", "Tiago", "Vagner",
        "Wagner", "Xavier", "Yuri", "Zé", "Antônio", "Benedito", "Cícero",
        "Davi", "Elias", "Fabrício", "Geraldo", "Heitor"
    };


    char* sobrenomes_brasil[] = {
        "Silva", "Santos", "Oliveira", "Souza", "Pereira", "Costa",
        "Ferreira", "Rodrigues", "Alves", "Nascimento", "Mendes",
        "Ribeiro", "Lima", "Gonçalves", "Carvalho", "Martins",
        "Araújo", "Vieira", "Cavalcanti", "Barbosa", "Barros",
        "Pinto", "Correia", "Duarte", "Freitas", "Farias",
        "Moreira", "Sales", "Rocha", "Fonseca", "Moura",
        "Macedo", "Xavier", "Cardoso", "Gomes", "Lopes",
        "Viana", "Mota", "Cunha", "Campos", "Borges",
        "Teixeira", "Nogueira", "Prado", "Andrade", "Monteiro",
        "Lacerda", "Miranda", "Assis", "Ramos"
    };

    char *cor_de_olho[] = {"castanho", "verde", "azul", "cinza", "preto"};
    
    char *cor_de_cabelo[] = {"preto", "castanho", "loiro", "ruivo", "grisalho"};
    char *tipo_de_cabelo[] = {"liso", "ondulado", "cacheado"};
    char *tipo_de_corte[]={"careca","moecano","sarará","longo","escovinha","social","emo"};
    char *pele[]={{"branco", "negro", "pardo"};
    char *formato_rosto[]={"rosto fino", "rosto redondo"};
    char *formato_nariz[]={"nariz largo", "nariz pontudo", "nariz pequeno", "nariz grande"};
    char *formato_boca[]={"lábios finos", "labios grossos","boca grande","boca pequena"};
    char *formato_olhos[]={"grandes","puxados","separados","pequenos","juntos"};
    char *formato_queixo[]={"grande","fino","largo","pequeno"};
    char *formato_testa[]={"curta","alta","grande","saliente"};             
    char *caracteristicas_faciais[]={"tatuagem", "sardas", "espinhas", "vitiligo", "rugas"} ;              
    

      
      return 0;
    }

