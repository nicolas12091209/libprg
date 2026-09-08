//
// Created by aluno on 08/09/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

struct Fila {
    No *inicio;
    No *ultimo;
    int tamanho;
};

Fila *fila;

Fila *cria_fila(int tamanho) {
    Fila *fila = malloc(sizeof(Fila));

    fila->inicio = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;

    return fila;
}

void inserir_fila(Fila *fila, int valor) {
    No *novo = malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    if (fila->ultimo == NULL) {
        fila->inicio = novo;
        fila->ultimo = novo;
    } else {
        fila->ultimo->prox = novo;
        fila->ultimo = novo;
    }

    fila->tamanho++;
}


int remover_fila(Fila *fila) {
    if (fila->inicio == NULL) {
        return -1;
    }

    No *aux = fila->inicio;
    int valor = aux->valor;

    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL) {
        fila->ultimo = NULL;
    }

    free(aux);
    fila->tamanho--;
    return valor;
}

int inicio_fila(Fila *fila) {
    if (fila->inicio == NULL) {
        return -1;
    }

    return fila->inicio->valor;
}

int fim_fila(Fila *fila) {
    if (fila->ultimo == NULL) {
        return -1;
    }

    return fila->ultimo->valor;
}

int tam_fila(Fila *fila) {
    return fila->tamanho;
}

void imprimir_fila(Fila *fila) {
    No *aux = fila->inicio;

    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}

void destruir_fila(Fila *fila) {
    No *aux;

    while (fila->inicio != NULL) {
        aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(aux);
    }

    free(fila);
}

void ex_1_fila() {
    printf("Exercício 1 - Fila implementada.\n");
}

void ex_2_fila() {
    fila = criar_fila();

    printf("fila criada\n");
}

void ex_3_fila() {
    inserir_fila(fila, 10);
    inserir_fila(fila, 20);
    inserir_fila(fila, 30);
    inserir_fila(fila, 40);
    inserir_fila(fila, 50);
    inserir_fila(fila, 60);
    inserir_fila(fila, 70);
    inserir_fila(fila, 80);
    inserir_fila(fila, 90);
    inserir_fila(fila, 100);

    printf("10 numeros inseridos\n");
}

void ex_4_fila() {
    printf("Fim da fila: %d\n", fim_fila(fila));
    printf("Tamanho da fila: %d\n", tam_fila(fila));
}

void ex_5_fila() {
    remover_fila(fila);
    remover_fila(fila);
    remover_fila(fila);

    printf("Tres numeros removidos.\n");
}

void ex_6_fila() {
    printf("Numeros da fila: ");
    imprimir_fila(fila);
}

void ex_7_fila() {
    destruir_fila(fila);
    fila = NULL;

    printf("Fila destruida.\n");
}


