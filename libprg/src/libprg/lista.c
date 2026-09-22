//
// Created by aluno on 22/09/2026.
//

#include <libprg/libprg.h>
#include <stdio.h>

void criar_lista(Lista *lista) {
    lista->tamanho = 0;
}

int inserir_lista(Lista *lista, int dado) {
    if (lista->tamanho >= TAM_MAX) return 0;
    lista->dados[lista->tamanho] = dado;
    lista->tamanho++;
    return 1;
}

int remover_lista(Lista *lista, int dado) {
    int posicao = busca_lista(lista, dado);
    if (posicao == -1) return 0;
    for (int i = posicao; i < lista->tamanho; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }
    lista->tamanho--;
    return 1;
}

int busca_lista(Lista *lista, int dado) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == dado) return i;
    }
    return -1;
}

void imprime_lista(Lista *lista) {
    printf("[ ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
        printf("]\n");
    }
}