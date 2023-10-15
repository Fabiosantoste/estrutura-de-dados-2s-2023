#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1; 
        }
        atual = atual->proximo;
    }
    return 0; 
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            ocorrencias++;
        }
        atual = atual->proximo;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo != NULL) {
        lista_imprimir_inversa(L->proximo);
        printf("%c ", L->valor);
    }
}

void lista_inserir_no_i(No* L, int i, char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    No* anterior = L;
    for (int j = 0; j < i; j++) {
        anterior = anterior->proximo;
        if (anterior == NULL) {
     
            free(novoNo);
            return;
        }
    }
    novoNo->proximo = anterior->proximo;
    anterior->proximo = novoNo;
}

void lista_remover_no_i(No* L, int i) {
    No* anterior = L;
    for (int j = 0; j < i; j++) {
        anterior = anterior->proximo;
        if (anterior == NULL || anterior->proximo == NULL) {
          
            return;
        }
    }
    No* noRemover = anterior->proximo;
    anterior->proximo = noRemover->proximo;
    free(noRemover);
}

void lista_remover_no(No* L, char valor_busca) {
    No* anterior = L;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            anterior->proximo = atual->proximo;
            free(atual);
            atual = anterior->proximo;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}
