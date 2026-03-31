//
// Created by aluno on 26/03/2026.
//

#include <stdlib.h>

typedef struct fila {
    int* elementos;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
}fila_t;

fila_t* criar_fila(int capacidade) {

    fila_t* fila = (fila_t*) malloc(sizeof(fila_t));
    fila->elementos = malloc(sizeof(int) * capacidade);
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;
}

int fila_vazia(fila_t* fila) {
    return (fila->tamanho == 0);
}

int destruir_fila(fila_t* fila) {

    free(fila->elementos);
    free(fila);
    return 0;

}
void enfileirar(fila_t* fila, int valor) {

    if (fila->tamanho >= fila->capacidade) exit(EXIT_FAILURE);

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

int desenfileirar (fila_t* fila) {

    if (fila_vazia(fila)) {
        exit(EXIT_FAILURE);
    }
    int valor = fila->elementos[0];

    for (int i = 1; i < fila->fim; i++) {
        fila->elementos[i] = fila->elementos[i + 1];
    }
    fila->fim--;

    return valor;
}

int inicio_fila(fila_t* fila) {
    if (fila_vazia(fila)) {
        exit(EXIT_FAILURE);
    }
    return fila->elementos[fila->inicio];
}

int fim_fila(fila_t* fila) {
    if (fila_vazia(fila)) {
        exit(EXIT_FAILURE);
    }
    int ultimo = (fila->fim - 1 + fila->capacidade) % fila->capacidade;

    return fila->elementos[ultimo];
}
int cheia(fila_t* fila) {
    return fila->tamanho == fila->capacidade ;
}

