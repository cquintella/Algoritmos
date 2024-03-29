#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TOTAL_NOMES 50
#define TAM_NOME 20



typedef struct {
    char nome[TAM_NOME];
    char sobrenome[TAM_NOME];
} nome_pessoa_t;

typedef enum genero{
    masculino,
    feminino
    } genero_t;
        
nome_pessoa_t gerar_nome( genero_t genero){
        
        
    char *nomes_masc[TOTAL_NOMES] = {
        "João", "Pedro", "Lucas", "Mateus", "Gabriel", "Felipe", "Rafael",
        "Gustavo", "Leonardo", "Bruno", "Thiago", "Rodrigo", "Vinicius",
        "Luciano", "Daniel", "Lucas", "Fernando", "Marcelo", "Lucas",
        "André", "Alexandre", "Carlos", "Eduardo", "Guilherme", "Igor",
        "Juliano", "Leandro", "Marcelo", "Nelson", "Pablo", "Renato",
        "Ricardo", "Rogério", "Sérgio", "Thales", "Tiago", "Vagner",
        "Wagner", "Xavier", "Yuri", "Zé", "Antônio", "Benedito", "Cícero",
        "Davi", "Elias", "Fabrício", "Geraldo", "Heitor"
    };

    char *nomes_femi[TOTAL_NOMES] = {
        "Ana", "Beatriz", "Carla", "Diana", "Elena", "Fernanda", "Gabriela",
        "Helena", "Isabela", "Jéssica", "Karina", "Lara", "Mariana",
        "Natália", "Olivia", "Patrícia", "Raquel", "Sara", "Tatiana",
        "Ursula", "Vera", "Wendy", "Ximena", "Yara", "Zara",
       "Adriana", "Bianca", "Cristina", "Daniela", "Elaine", "Flávia",
       "Gisele", "Heloisa", "Ivana", "Juliana", "Kátia", "Lilian",
       "Marcela", "Natalie", "Odete", "Paula", "Renata", "Sabrina",
       "Talita", "Valéria", "Waleska", "Xandra", "Yasmin", "Zélia"
    };
    
    char* sobrenomes[TOTAL_NOMES] = {
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
   
   char primeiro_nome[TAM_NOME];
   char segundo_nome[TAM_NOME];
        
   strcpy(segundo_nome, sobrenomes[rand()%TOTAL_NOMES]);
     
   if (genero == masculino) {
            strcpy(primeiro_nome, nomes_masc[rand()%TOTAL_NOMES]);
   }else{
             strcpy(primeiro_nome, nomes_femi[rand()%TOTAL_NOMES]);
   }
        
   nome_pessoa_t nome_completo;
   strcpy(nome_completo.nome,primeiro_nome);
   strcpy(nome_completo.sobrenome,segundo_nome);
   return nome_completo;
}
        
typedef struct car_fisicas{
    char *cor_de_olho;
    char *cor_de_cabelo;
    char *tipo_de_cabelo;
    char *tipo_de_corte;
    char *tom_de_pele;
    char *formato_rosto;
    char *formato_nariz;
    char *formato_boca;
    char *formato_olhos;
    char *formato_queixo;
    char *formato_testa;
    char *car_faciais;
    
} car_fisicas_t;

car_fisicas_t gerar_características_físicas(){
    char *cor_de_olho[] = {"castanho", "verde", "azul", "cinza", "preto"};
    char *cor_de_cabelo[] = {"preto", "castanho", "loiro", "ruivo", "grisalho"};
    char *tipo_de_cabelo[] = {"liso", "ondulado", "cacheado"};
    char *tipo_de_corte[]={"careca","moecano","sarará","longo","escovinha","social","emo"};
    char *tom_de_pele[]={"branco", "negro", "pardo"};
    char *formato_rosto[]={"rosto fino", "rosto redondo"};
    char *formato_nariz[]={"nariz largo", "nariz pontudo", "nariz pequeno", "nariz grande"};
    char *formato_boca[]={"lábios finos", "labios grossos","boca grande","boca pequena"};
    char *formato_olhos[]={"grandes","puxados","separados","pequenos","juntos"};
    char *formato_queixo[]={"grande","fino","largo","pequeno"};
    char *formato_testa[]={"curta","alta","grande","saliente"};             
    char *car_faciais[]={"tatuagem", "sardas", "espinhas", "vitiligo", "rugas"} ;   
    
    car_fisicas_t car_fisicas;
    car_fisicas.cor_de_olho = cor_de_olho[rand() % 5];
    car_fisicas.cor_de_cabelo = cor_de_cabelo[rand() % 5];
    car_fisicas.tipo_de_cabelo = tipo_de_cabelo[rand() % 3];
    car_fisicas.tipo_de_corte = tipo_de_corte[rand() % 7];
    car_fisicas.tom_de_pele = tom_de_pele[rand() % 3];
    car_fisicas.formato_rosto = formato_rosto[rand() % 2];
    car_fisicas.formato_nariz = formato_nariz[rand() % 4];
    car_fisicas.formato_boca = formato_boca[rand() % 4];
    car_fisicas.formato_olhos = formato_olhos[rand() % 5];
    car_fisicas.formato_queixo = formato_queixo[rand() % 4];
    car_fisicas.formato_testa = formato_testa[rand() % 4];
    car_fisicas.car_faciais = car_faciais[rand() % 5];
                  
    return      car_fisicas;          
 }
 

int main(){
    car_fisicas_t car_fisicas = gerar_características_físicas();
    genero_t genero=masculino;
    nome_pessoa_t nome_completo = gerar_nome(genero);

    printf("Nome: %s %s\n", nome_completo.nome, nome_completo.sobrenome);
    printf("\n Criar uma foto de rosto de um jogador de futebol no formato 3x4 mostrando do peito para cimai, fundo da foto é verde, jogador com camisa amarela com as seguintes caracteristicas físicas: ");
    printf("Cor dos olhos: %s, ", car_fisicas.cor_de_olho);
    printf("cabelo de cor %s, ", car_fisicas.cor_de_cabelo);
    printf("no estilo: %s, ", car_fisicas.tipo_de_cabelo);
    printf("Tom de pele: %s, ", car_fisicas.tom_de_pele);
    printf("Formato de rosto: %s, ", car_fisicas.formato_rosto);
    printf("Formato de nariz: %s, ", car_fisicas.formato_nariz);
    printf("Formato de boca: %s, ", car_fisicas.formato_boca);
    printf("Formato de olhos: %s, ", car_fisicas.formato_olhos);
    printf("Formato de queixo: %si, ", car_fisicas.formato_queixo);
    printf("Formato de testa: %s.", car_fisicas.formato_testa);
    printf("Características faciais: %s\n", car_fisicas.car_faciais);

    return 0;
}
