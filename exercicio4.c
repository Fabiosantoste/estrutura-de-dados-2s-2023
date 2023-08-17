#include <stdio.h>

int conta_int_array(int array[], int tamanho, int busca) {
    int contador = 0;

   
    for (int i = 0; i < tamanho; i++) {
        
        if (array[i] == busca) {
            contador++;
        }
    }

    return contador;
}

int main() {
    int array[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);
    int busca = 7;

    int ocorrencias = conta_int_array(array, tamanho, busca);

    printf("O número %d aparece %d vezes no array.\n", busca, ocorrencias);

    return 0;
}
