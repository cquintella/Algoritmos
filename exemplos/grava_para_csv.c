#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define FILE_HEADER "ci_id,ci_name,ci_owner"
#define FILE_FORMAT "%d,%s,%s\n"
#define MAX_CI_DB 100

// estrutura que define um configuration item simplificado.
typedef struct ci a
   int ci_id;
   char ci_name[20];
   char ci_owner[20];
} ci_t;

// faz a carga do array passado por referencia
void load_ci_db(ci_t ci_db[]) {
  
  for (int i=0; i<MAX_CI_DB; i++) {
    ci_db[i].ci_id=i;
    strcpy(ci_db[i].ci_name, "nome_qq");
    strcpy(ci_db[i].ci_owner, "qq dono");
  }
}

// imprime o array passado por valor
imprime_ci_db(ci_t ci_db[]){
  for (int i=0; i<MAX_CI_DB; i++) {
    printf("%d:\t%s\t%s\n", ci_db[i].ci_id, ci_db[i].ci_name, ci_db[i].ci_owner);
    }
}

int main() {
  ci_t ci_db[100];
  load_ci_db(ci_db);
  imprime_ci_db(ci_db);

  // salvar para .csv
  FILE *file_p=NULL;
  file_p = fopen("arquivo.csv", "w");
  if (file_p == NULL) {
    printf("Erro ao abrir arquivo.\n");
    return 1;
  }
  //imprimir o header
  fprintf(file_p, FILE_HEADER);
  for (int i = 0; i < MAX_CI_DB; i++) {
     fprintf(file_p, FILE_FORMAT, ci_db[i].ci_id, ci_db[i].ci_name, ci_db[i].ci_owner);
  }
 
  }
