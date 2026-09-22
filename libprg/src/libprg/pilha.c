//
// Created by aluno on 22/09/2026.
//

#include <libprg/libprg.h>

void pilha_iniciar(Pilha *pilha) {
    pilha->topo = -1;
}

int pilha_vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int pilha_cheia(Pilha *pilha) {
    return pilha->topo == TAM_MAX;
}

int pilha_empilhar(Pilha *pilha, int valor) {
    if (pilha_cheia(pilha)) return 0;
    pilha->topo++;
    pilha->dados[pilha->topo] = valor;
    return 1;
}

int pilha_desempilhar(Pilha *pilha, int *valor) {
    if (pilha_vazia(pilha)) return 0;
    *valor = pilha->dados[pilha->topo];
    pilha->topo--;
    return 1;
}

int pilha_tamanho(Pilha *pilha) {
    return pilha->topo;
}
