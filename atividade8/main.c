#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char valor;
    struct No* proximo;
} No;

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) return 1;/
        atual = atual->proximo;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) ocorrencias++;
        atual = atual->proximo;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo != NULL) {
        lista_imprimir_inversa(L->proximo);
        printf("%c ", L->proximo->valor);
    }
}

void lista_inserir_no_i(No* L, int i, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    No* atual = L;
    for (int j = 0; j < i && atual->proximo != NULL; j++) atual = atual->proximo;
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;
    for (int j = 0; j < i && atual->proximo != NULL; j++) atual = atual->proximo;
    if (atual->proximo != NULL) {
        No* no_remover = atual->proximo;
        atual->proximo = no_remover->proximo;
        free(no_remover);
    }
}

void lista_remover_no(No* L, char valor_busca) {
    No* atual = L;
    while (atual->proximo != NULL) {
        if (atual->proximo->valor == valor_busca) {
            No* no_remover = atual->proximo;
            atual->proximo = no_remover->proximo;
            free(no_remover);
        } else {
            atual = atual->proximo;
        }
    }
}

int main() {
    No* lista = (No*)malloc(sizeof(No));
    lista->proximo = NULL;
    
    lista_inserir_no_i(lista, 0, 'A');
    lista_inserir_no_i(lista, 1, 'B');
    lista_inserir_no_i(lista, 2, 'A');
    lista_inserir_no_i(lista, 3, 'C');

    if (lista_verificar_existencia(lista, 'B')) printf("Valor 'B' existe na lista.\n");
    else printf("Valor 'B' não existe na lista.\n");

    int ocorrencias = lista_verificar_ocorrencias(lista, 'A');
    printf("Valor 'A' ocorre %d vezes na lista.\n", ocorrencias);

    printf("Lista na ordem inversa: ");
    lista_imprimir_inversa(lista);
    printf("\n");

    lista_remover_no_i(lista, 2);
    lista_remover_no(lista, 'A');
    
    while (lista->proximo != NULL) {
        No* temp = lista->proximo;
        lista->proximo = temp->proximo;
        free(temp);
    }
    free(lista);

    return 0;
}
