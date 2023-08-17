#include <stdio.h>

void encontrarMinMax(int array[], int tamanho, int *min, int *max) {
   
    *min = array[0];
    *max = array[0];

   
    for (int i = 1; i < tamanho; i++) {
        
        if (array[i] < *min) {
            *min = array[i];
        }

     
        if (array[i] > *max) {
            *max = array[i];
        }
    }
}

int main() {
    int array[] = {5, 10, 3, 8, 1};
    int tamanho = sizeof(array) / sizeof(array[0]);

    int minimo, maximo;
    encontrarMinMax(array, tamanho, &minimo, &maximo);

    printf("O menor elemento é: %d\n", minimo);
    printf("O maior elemento é: %d\n", maximo);

    return 0;
}
