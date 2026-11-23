//
// Created by aluno on 23/11/2026.
//

#include <libprg/libprg.h>
#include <stdlib.h>
#include <string.h>

void criar_abp(ABP *arvore) {
    arvore->raiz = NULL;
    arvore->tamanho = 0;
}

int inserir_abp(ABP *arvore, const char *chave, void *dado) {
    NoABP *novo = malloc(sizeof(NoABP));
    if (novo == NULL) return 0;
    strncpy(novo->chave, chave, TAM_CHAVE_ABP - 1);
    novo->chave[TAM_CHAVE_ABP - 1] = '\0';
    novo->dado = dado;
    novo->esquerda = NULL;
    novo->direita = NULL;

    NoABP **lugar = &arvore->raiz;
    while (*lugar != NULL) {
        if (strcmp(chave, (*lugar)->chave) < 0) {
            lugar = &(*lugar)->esquerda;
        } else {
            lugar = &(*lugar)->direita;
        }
    }
    *lugar = novo;
    arvore->tamanho++;
    return 1;
}

void *buscar_abp(ABP *arvore, const char *chave) {
    NoABP *aux = arvore->raiz;
    while (aux != NULL) {
        int c = strcmp(chave, aux->chave);
        if (c == 0) return aux->dado;
        aux = (c < 0) ? aux->esquerda : aux->direita;
    }
    return NULL;
}

int remover_abp(ABP *arvore, const char *chave, void *dado) {
    NoABP **lugar = &arvore->raiz;
    while (*lugar != NULL) {
        int c = strcmp(chave, (*lugar)->chave);
        if (c == 0 && (*lugar)->dado == dado) break;
        lugar = (c < 0) ? &(*lugar)->esquerda : &(*lugar)->direita;
    }
    NoABP *no = *lugar;
    if (no == NULL) return 0;

    if (no->esquerda == NULL) {
        *lugar = no->direita;
    } else if (no->direita == NULL) {
        *lugar = no->esquerda;
    } else {
        NoABP **lugar_sucessor = &no->direita;
        while ((*lugar_sucessor)->esquerda != NULL) {
            lugar_sucessor = &(*lugar_sucessor)->esquerda;
        }
        NoABP *sucessor = *lugar_sucessor;
        *lugar_sucessor = sucessor->direita;
        sucessor->esquerda = no->esquerda;
        sucessor->direita = no->direita;
        *lugar = sucessor;
    }
    free(no);
    arvore->tamanho--;
    return 1;
}

static void em_ordem(NoABP *no, void (*visitar)(void *dado)) {
    if (no == NULL) return;
    em_ordem(no->esquerda, visitar);
    visitar(no->dado);
    em_ordem(no->direita, visitar);
}

void em_ordem_abp(ABP *arvore, void (*visitar)(void *dado)) {
    em_ordem(arvore->raiz, visitar);
}

static int altura(NoABP *no) {
    if (no == NULL) return 0;
    int esq = altura(no->esquerda);
    int dir = altura(no->direita);
    return 1 + (esq > dir ? esq : dir);
}

int altura_abp(ABP *arvore) {
    return altura(arvore->raiz);
}

static void destruir(NoABP *no) {
    if (no == NULL) return;
    destruir(no->esquerda);
    destruir(no->direita);
    free(no);
}

void destruir_abp(ABP *arvore) {
    destruir(arvore->raiz);
    criar_abp(arvore);
}