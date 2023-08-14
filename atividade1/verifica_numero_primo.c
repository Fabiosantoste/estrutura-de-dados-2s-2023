#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int ehPrimo(int num)
    if (num <= 1) {
        return 0;  
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    
    return 1; 
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }
    
    char *endptr;
    long num = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' && *endptr != '\n') {
        printf("Erro: Valor inserido não é um número válido.\n");
        return 1;
    }

    if (errno == ERANGE) {
        printf("Erro: Valor inserido está fora da faixa de representação de um número.\n");
        return 1;
    }
    
    if (ehPrimo(num)) {
        printf("1 - O numero %ld eh primo.\n", num);
    } else {
        printf("0 - O numero %ld nao eh primo.\n", num);
    }
    
    return 0;
}