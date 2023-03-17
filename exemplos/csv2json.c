#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 50
#define MAX_FIELD_NAME_LENGTH 50
#define MAX_RECORDS 1000
#define MAX_RECORD_LENGTH 1000

// Função que lê o cabeçalho do arquivo CSV e extrai o nome dos campos
void read_header(FILE* fp, char field_names[MAX_FIELDS][MAX_FIELD_NAME_LENGTH], int* num_fields) {
    char line[MAX_RECORD_LENGTH];
    fgets(line, MAX_RECORD_LENGTH, fp);
    char* token = strtok(line, ",");
    int i = 0;
    while (token != NULL) {
        // Remove caracteres de quebra de linha e espaços em branco do nome do campo
        char* end = token + strlen(token) - 1;
        while (end > token && (*end == '\r' || *end == '\n' || *end == ' ')) {
            *end = '\0';
            end--;
        }
        strncpy(field_names[i], token, MAX_FIELD_NAME_LENGTH);
        i++;
        token = strtok(NULL, ",");
    }
    *num_fields = i;
}

// Função que lê os registros do arquivo CSV e grava um arquivo JSON com esses registros
void read_records(FILE* fp_in, FILE* fp_out, char field_names[MAX_FIELDS][MAX_FIELD_NAME_LENGTH], int num_fields) {
    char line[MAX_RECORD_LENGTH];
    char record[MAX_RECORD_LENGTH];
    fprintf(fp_out, "[");
    while (fgets(line, MAX_RECORD_LENGTH, fp_in) != NULL) {
        char* token = strtok(line, ",");
        int i = 0;
        sprintf(record, "{");
        while (token != NULL) {
            // Remove caracteres de quebra de linha e espaços em branco do valor do campo
            char* end = token + strlen(token) - 1;
            while (end > token && (*end == '\r' || *end == '\n' || *end == ' ')) {
                *end = '\0';
                end--;
            }
            sprintf(record + strlen(record), "\"%s\":\"%s\"", field_names[i], token);
            if (i < num_fields - 1) {
                sprintf(record + strlen(record), ",");
            }
            i++;
            token = strtok(NULL, ",");
        }
        sprintf(record + strlen(record), "}");
        fprintf(fp_out, "%s", record);
        if (fgets(line, MAX_RECORD_LENGTH, fp_in) != NULL) {
            fprintf(fp_out, ",");
        }
    }
    fprintf(fp_out, "]");
}

int main() {
    FILE* fp_in = fopen("input.csv", "r");
    if (fp_in == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de entrada.\n");
        exit(EXIT_FAILURE);
    }

    FILE* fp_out = fopen("output.json", "w");
    if (fp_out == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de saída.\n");
        exit(EXIT_FAILURE);
    }

    char field_names[MAX_FIELDS][MAX_FIELD_NAME_LENGTH];
    int num_fields;
    read_header(fp_in, field_names, &num_fields);

    read_records(fp_in, fp_out, field_names, num_fields);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}

