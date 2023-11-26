#include <stdio.h>
#include <stdlib.h>

#include "../inc/file_io.h"

FILE *open_file(const char *nomeArquivo, const char *modo) {
    FILE *arquivo = fopen(nomeArquivo, modo);
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        exit(-1);
    }
    return arquivo;
}