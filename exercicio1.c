#include <stdio.h>

int soma_array(int array[], int tamanho) {
    int soma = 0; 
    int i;

    for (i = 0; i < tamanho; i++) {
        soma += array[i]; /
    }

    return soma;
}

int main() {
    int array[] = {5, 7, 9, 6};
    int tamanho = sizeof(array) / sizeof(array[0]);

    int resultado = soma_array(array, tamanho);

    printf("A soma dos elementos do array é: %d\n", resultado);

    return 0;
}
