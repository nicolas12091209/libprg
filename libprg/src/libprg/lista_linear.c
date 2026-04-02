//
// Created by aluno on 02/04/2026.
//

#include <stdbool.h>
#include <stdlib.h>

typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

int criar_lista = true;

int insert (lista_linear_t* lista_linear, int valor) {

    if (lista_linear->tamanho == lista_linear->capacidade) {
        int nova_capacidade = lista_linear->capacidade * 2;
        int* novo_espaço = (int*) realloc (lista_linear->elementos, nova_capacidade * sizeof(int));

        if (novo_espaço == NULL) return 0;

        lista_linear->elementos;
        lista_linear->capacidade = nova_capacidade;
    }

    if (lista_linear->ordenada) {
        int i = lista_linear->tamanho - 1;
        while (i >= 0 && lista_linear->elementos[i] < valor) {
            lista_linear->elementos[i + 1] = lista_linear->elementos[i];
            i--;
        }
        lista_linear->elementos[i] = valor;
    } else {
        lista_linear->elementos[lista_linear->tamanho] = valor;
    }

    lista_linear->tamanho++;
    return 1;

}


int remove (lista_linear_t* lista_linear, int valor) {
    int i, posição = -1;

    for (i = 0; i < lista_linear->tamanho; i++) {
        if (lista_linear->elementos[i] == valor) {
            posição = i;
            break;
        }
    }
    if (posição == -1) return 0;

    for (i = 0; i < lista_linear->tamanho; i++) {
        lista_linear->elementos[1] = lista_linear->elementos[i + 1];
    }

    lista_linear->tamanho--;
    return 1;
}