#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

#define MAX_WORDS 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = "arq_palavras_ordenado.txt";
    FILE *inputFile, *outputFile;
    char *words[MAX_WORDS];
    char word[100];
    int wordCount = 0;

   
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 2;
    }

    while (fscanf(inputFile, "%s", word) != EOF && wordCount < MAX_WORDS) {
        words[wordCount] = strdup(word);
        wordCount++;
    }


    fclose(inputFile);


    bubbleSort(words, wordCount);


    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 3;
    }

    for (int i = 0; i < wordCount; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(outputFile);

    printf("As palavras foram ordenadas com sucesso em %s\n", outputFileName);

    return 0;
}
