#include "pilha.h"
#include <stdlib.h>

Pilha* criar_pilha(int tamanho_maximo) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->tamanho_maximo = tamanho_maximo;
    pilha->topo = -1;
    pilha->dados = (int*)malloc(sizeof(int) * tamanho_maximo);
    return pilha;
}

int esta_vazia(Pilha* pilha) {
    return (pilha->topo == -1);
}

int esta_cheia(Pilha* pilha) {
    return (pilha->topo == pilha->tamanho_maximo - 1);
}

void empilhar(Pilha* pilha, int elemento) {
    if (esta_cheia(pilha)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    pilha->dados[++pilha->topo] = elemento;
}

int desempilhar(Pilha* pilha) {
    if (esta_vazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return -1; 
    }
    return pilha->dados[pilha->topo--];
}

void liberar_pilha(Pilha* pilha) {
    free(pilha->dados);
    free(pilha);
}