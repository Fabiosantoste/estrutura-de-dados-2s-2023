#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Ponto;

void regressaoLinear(Ponto pontos[], int n) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX += pontos[i].x;
        sumY += pontos[i].y;
        sumXY += pontos[i].x * pontos[i].y;
        sumX2 += pontos[i].x * pontos[i].x;
    }

    double slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double intercept = (sumY - slope * sumX) / n;

    printf("Equação da regressão linear: y = %.2fx + %.2f\n", slope, intercept);


    double mediaX = sumX / n;
    double mediaY = sumY / n;
    double intercepcao = mediaY - slope * mediaX;

    printf("Coeficiente angular (inclinação): %.2f\n", slope);
    printf("Coeficiente linear (intercepção): %.2f\n", intercepcao);

    printf("Equação completa da regressão linear: y = %.2fx + %.2f\n", slope, intercepcao);
}

int main() {
    int n;

    FILE *arquivo = fopen("pontos.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fscanf(arquivo, "%d", &n);

    Ponto *pontos = (Ponto *)malloc(n * sizeof(Ponto));

    for (int i = 0; i < n; i++) {
        fscanf(arquivo, "%lf %lf", &pontos[i].x, &pontos[i].y);
    }

    regressaoLinear(pontos, n);

    free(pontos);

    fclose(arquivo);

    return 0;
}
