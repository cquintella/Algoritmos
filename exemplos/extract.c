#include <stdio.h>
#include <poppler.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pdf file>\n", argv[0]);
        return 1;
    }

    char *pdf_file = argv[1];
    char *base_name = strtok(pdf_file, ".");
    char *txt_file = malloc(strlen(base_name) + 5);
    sprintf(txt_file, "%s.txt", base_name);

    PopplerDocument *document;
    GError *error = NULL;
    document = poppler_document_new_from_file(pdf_file, NULL, &error);

    if (error) {
        printf("Error opening PDF file: %s\n", error->message);
        g_error_free(error);
        return 1;
    }

    int num_pages = poppler_document_get_n_pages(document);
    FILE *output_file = fopen(txt_file, "w");

    for (int i = 0; i < num_pages; i++) {
        PopplerPage *page = poppler_document_get_page(document, i);
        gchar *text = poppler_page_get_text(page);

        if (text) {
            fputs(text, output_file);
            g_free(text);
        }

        g_object_unref(page);
    }

    fclose(output_file);
    g_object_unref(document);
    free(txt_file);

    return 0;
}
