#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct Musica {
    char artista[MAX_LENGTH];
    char titulo[MAX_LENGTH];
    char album[MAX_LENGTH];
    char local[MAX_LENGTH];
    int ano;
    int lancamento;
    struct Musica *proximo;
} Musica;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Musica *criar_musica(char *artista, char *titulo, char *album, char *local, int ano, int lancamento) {
    Musica *nova_musica = (Musica *) malloc(sizeof(Musica));
    strcpy(nova_musica->artista, artista);
    strcpy(nova_musica->titulo, titulo);
    strcpy(nova_musica->album, album);
    strcpy(nova_musica->local, local);
    nova_musica->ano = ano;
    nova_musica->lancamento = lancamento;
    nova_musica->proximo = NULL;
    return nova_musica;
}

void inserir_musica(Musica **lista, Musica *nova_musica) {
    if (*lista == NULL) {
        *lista = nova_musica;
        (*lista)->proximo = *lista;
    } else {
        Musica *ultima_musica = (*lista)->proximo;
        while (ultima_musica->proximo != *lista) {
            ultima_musica = ultima_musica->proximo;
        }
        ultima_musica->proximo = nova_musica;
        nova_musica->proximo = *lista;
    }
}

void salvarMusicas(ListaCircular *lista, char* nomeArquivo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    Musica *atual = lista->inicio;
    do {
        fprintf(arquivo, "Artista: %s\n", atual->artista);
        fprintf(arquivo, "Música: %s\n", atual->nomeMusica);
        fprintf(arquivo, "Álbum: %s\n", atual->album);
        fprintf(arquivo, "Ano de Lançamento: %d\n", atual->anoLancamento);
        fprintf(arquivo, "Local do arquivo: %s\n", atual->localArquivo);
        fprintf(arquivo, "\n");
        atual = atual->prox;
    } while(atual != lista->inicio);

    fclose(arquivo);
}


void imprimir_lista(Musica *lista) {
    Musica *atual = lista;
    do {
        printf("Artista: %s\n", atual->artista);
        printf("Titulo: %s\n", atual->titulo);
        printf("Album: %s\n", atual->album);
        printf("Local: %s\n", atual->local);
        printf("Ano: %d\n", atual->ano);
        printf("Lancamento: %d\n", atual->lancamento);
        printf("\n");
        atual = atual->proximo;
    } while (atual != lista);
}

void tocarMusica(Musica *musica) {
    char comando[100];
    sprintf(comando, "vlc \"%s\"", musica->localArquivo); // formata o comando para o VLC

    printf("Tocando música: %s\n", musica->nomeMusica);

    system(comando); // executa o comando no terminal
}

void buscar_musicas(char* diretorio, ListaCircular* lista) {
    DIR* dir;
    struct dirent* ent;

    // abre o diretório
    if ((dir = opendir(diretorio)) != NULL) {
        // percorre todos os arquivos e diretórios do diretório atual
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_DIR) {
                // se for um diretório, chama a função recursivamente para o diretório filho
                if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                    continue;
                }
                char subdiretorio[PATH_MAX];
                snprintf(subdiretorio, sizeof(subdiretorio), "%s/%s", diretorio, ent->d_name);
                buscar_musicas(subdiretorio, lista);
            } else {
                // se for um arquivo, verifica se é uma música em mp3
                char* extensao = strrchr(ent->d_name, '.');
                if (extensao && strcmp(extensao, ".mp3") == 0) {
                    // se for uma música, cria uma nova música e adiciona à lista
                    Musica musica = criar_musica(ent->d_name, diretorio);
                    adicionar_musica(lista, musica);
                }
            }
        }
        closedir(dir);
    }
}

void ordenar_musicas(Musica **lista, int criterio) {
    Musica *atual = *lista, *proximo = NULL, *anterior = NULL;
    int trocou = 1;
    
    while (trocou) {
        trocou = 0;
        atual = *lista;
        while (atual->prox != *lista) {
            proximo = atual->prox;
            if (criterio == 0 && strcmp(atual->artista, proximo->artista) > 0) {
                trocar_musicas(atual, proximo);
                trocou = 1;
            }
            else if (criterio == 1 && strcmp(atual->album, proximo->album) > 0) {
                trocar_musicas(atual, proximo);
                trocou = 1;
            }
            else if (criterio == 2 && strcmp(atual->musica, proximo->musica) > 0) {
                trocar_musicas(atual, proximo);
                trocou = 1;
            }
            anterior = atual;
            atual = proximo;
        }
        if (criterio == 0 && strcmp(atual->artista, (*lista)->artista) < 0) {
            trocar_musicas(atual, *lista);
            trocou = 1;
            *lista = atual;
        }
        else if (criterio == 1 && strcmp(atual->album, (*lista)->album) < 0) {
            trocar_musicas(atual, *lista);
            trocou = 1;
            *lista = atual;
        }
        else if (criterio == 2 && strcmp(atual->musica, (*lista)->musica) < 0) {
            trocar_musicas(atual, *lista);
            trocou = 1;
            *lista = atual;
        }
    }
}


void menu(Musica **lista) {
    int opcao;

    do {
        printf("\n---- JUKEBOX MENU ----\n");
        printf("1. Inserir nova música\n");
        printf("2. Imprimir dados de uma música\n");
        printf("3. Listar todas as músicas\n");
        printf("4. Tocar uma música\n");
        printf("5. Sair do programa\n");
        printf("6. Ordenar músicas.\n˜);

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirMusica(lista);
                break;
            case 2:
                imprimirMusica(lista);
                break;
            case 3:
                listarMusicas(*lista);
                break;
            case 4:
                tocarMusica(*lista);
                break;
            case 5:
                printf("\nEncerrando o programa...\n");
                break;
            case 6:
                printf("Escolha o critério de ordenação:\n");
                printf("0 - Artista\n1 - Álbum\n2 - Música\n");
                scanf("%d", &criterio);
                ordenar_musicas(&lista, criterio);
                printf("Lista ordenada com sucesso!\n");
            break;
          case 7:
                printf("Digite o diretório onde deseja buscar as músicas: ");
                scanf("%s", diretorio);
                buscarMP3(diretorio, inicio);
}

            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);
}



int main() {
    FILE *arquivo;
    char linha[MAX_LENGTH], artista[MAX_LENGTH], titulo[MAX_LENGTH], album[MAX_LENGTH], local[MAX_LENGTH];
    int ano, lancamento;
    Musica *lista_musicas = NULL;

    arquivo = fopen("lista_musicas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    while (fgets(linha, MAX_LENGTH, arquivo)) {
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%d;%d", artista, titulo, album, local, &ano, &lancamento);
        Musica *nova_musica = criar_musica(artista, titulo, album, local, ano, lancamento);
        inserir_musica(&lista_musicas, nova_musica);
    }

    fclose(arquivo);

    imprimir_lista(lista_musicas);

    return 0;
}
  

