//
// Created by aluno on 17/11/2026.
//
#include <libprg/libprg.h>
#include <stdio.h>
#include <stdlib.h>
void criar_lista_dupla(ListaDupla *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}
int inserir_inicio_dupla(ListaDupla *lista, int dado) {
    NoListaDupla *novo = malloc(sizeof(NoListaDupla));
    if (novo == NULL) return 0;
    novo->dado = dado;
    novo->anterior = NULL;
    novo->proximo = lista->inicio;
    if (lista->inicio == NULL) {
        lista->fim = novo;
    } else {
        lista->inicio->anterior = novo;
    }
    lista->inicio = novo;
    lista->tamanho++;
    return 1;
}
int inserir_fim_dupla(ListaDupla *lista, int dado) {
    NoListaDupla *novo = malloc(sizeof(NoListaDupla));
    if (novo == NULL) return 0;
    novo->dado = dado;
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    if (lista->fim == NULL) {
        lista->inicio = novo;
    } else {
        lista->fim->proximo = novo;
    }
    lista->fim = novo;
    lista->tamanho++;
    return 1;
}
int remover_inicio_dupla(ListaDupla *lista) {
    if (lista->inicio == NULL) return -1;
    NoListaDupla *aux = lista->inicio;
    int valor = aux->dado;
    lista->inicio = aux->proximo;
    if (lista->inicio == NULL) {
        lista->fim = NULL;
    } else {
        lista->inicio->anterior = NULL;
    }
    free(aux);
    lista->tamanho--;
    return valor;
}
int remover_fim_dupla(ListaDupla *lista) {
    if (lista->fim == NULL) return -1;
    NoListaDupla *aux = lista->fim;
    int valor = aux->dado;
    lista->fim = aux->anterior;
    if (lista->fim == NULL) {
        lista->inicio = NULL;
    } else {
        lista->fim->proximo = NULL;
    }
    free(aux);
    lista->tamanho--;
    return valor;
}

int remover_dupla(ListaDupla *lista, int dado) {
    NoListaDupla *aux = lista->inicio;
    while (aux != NULL && aux->dado != dado) {
        aux = aux->proximo;
    }
    if (aux == NULL) return 0;
    if (aux->anterior != NULL) {
        aux->anterior->proximo = aux->proximo;
    } else {
        lista->inicio = aux->proximo;   // era o primeiro
    }
    if (aux->proximo != NULL) {
        aux->proximo->anterior = aux->anterior;
    } else {
        lista->fim = aux->anterior;     // era o último
    }
    free(aux);
    lista->tamanho--;
    return 1;
}

int buscar_dupla(ListaDupla *lista, int dado) {
    int posicao = 0;
    for (NoListaDupla *aux = lista->inicio; aux != NULL; aux = aux->proximo) {
        if (aux->dado == dado) return posicao;
        posicao++;
    }
    return -1;
}
void imprimir_dupla(ListaDupla *lista) {
    printf("[ ");
    for (NoListaDupla *aux = lista->inicio; aux != NULL; aux = aux->proximo) {
        printf("%d ", aux->dado);
    }
    printf("]\n");
}
void imprimir_dupla_reversa(ListaDupla *lista) {
    printf("[ ");
    for (NoListaDupla *aux = lista->fim; aux != NULL; aux = aux->anterior) {
        printf("%d ", aux->dado);
    }
    printf("]\n");
}
void destruir_lista_dupla(ListaDupla *lista) {
    NoListaDupla *aux;
    while (lista->inicio != NULL) {
        aux = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(aux);
    }
    lista->fim = NULL;
    lista->tamanho = 0;
}


