//
// Created by aluno on 23/11/2026.
//

#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

static int altura(NoAVL *no) {
    if (no == NULL) {
        return 0;
    }
    return no->altura;
}

static int maior(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}
static void atualizar_altura(NoAVL *no) {
    no->altura = 1 + maior(altura(no->esquerda), altura(no->direita));
}
static NoAVL *criar_no(int valor, void *dado) {
    NoAVL *novo = malloc(sizeof * novo);
    if (novo == NULL) {
        return NULL;
    }
    novo->valor = valor;
    novo->dado = dado;
    novo->altura = 1;
    novo->esquerda =  NULL;
    novo->direita =  NULL;
    return novo;
}

static int fator_balanceamento(NoAVL *no) {
    if (no == NULL) {
        return 0;
    }
    return altura(no->esquerda) - altura(no->direita);
}

static NoAVL *rotacao_direita(NoAVL *y) {
    NoAVL *x = y->esquerda;
    NoAVL *aux = x->direita;
    x->direita = y;
    y->esquerda = aux;
    atualizar_altura(y);
    atualizar_altura(x);
    return x;
}

static NoAVL *rotacao_esquerda(NoAVL *x) {
    NoAVL *y = x->direita;
    NoAVL *aux = y->esquerda;
    y->esquerda = x;
    x->direita = aux;
    atualizar_altura(x);
    atualizar_altura(y);
    return y;
}

NoAVL *inserir_avl(NoAVL *no, int valor, void *dado) {
    if (no == NULL) {
        return criar_no(valor, dado);
    }
    if (valor < no->valor) {
        no->esquerda = inserir_avl(no->esquerda, valor, dado);
    }
    else if (valor > no->valor) {
        no->direita = inserir_avl(no->direita, valor, dado);
    }

    else {
        return no;
    }
    atualizar_altura(no);
    int balanceamento = fator_balanceamento(no);
    if (balanceamento > 1 && valor < no->esquerda->valor) {
        return rotacao_direita(no);
    }
    if (balanceamento < -1 && valor > no->direita->valor) {
        return rotacao_esquerda(no);
    }
    if (balanceamento > 1 && valor > no->esquerda->valor) {
        no->esquerda = rotacao_esquerda(no->esquerda);
        return rotacao_direita(no);
    }
    if (balanceamento < -1 && valor < no->direita->valor) {
        no->direita = rotacao_direita(no->direita);
        return rotacao_esquerda(no);
    }
    return no;
}
static NoAVL *balancear(NoAVL *no) {

    atualizar_altura(no);
    int balanceamento = fator_balanceamento(no);
    if (balanceamento > 1 && fator_balanceamento(no->esquerda) >= 0) {
        return rotacao_direita(no);
    }
    if (balanceamento > 1 && fator_balanceamento(no->esquerda) < 0) {
        no->esquerda = rotacao_esquerda(no->esquerda);
        return rotacao_direita(no);
    }
    if (balanceamento < -1 && fator_balanceamento(no->direita) <= 0) {
        return rotacao_esquerda(no);
    }
    if (balanceamento < -1 && fator_balanceamento(no->direita) > 0) {
        no->direita = rotacao_direita(no->direita);
        return rotacao_esquerda(no);
    }
    return no;
}

NoAVL *remover_avl(NoAVL *no, int valor) {
    if (no == NULL) {
        return NULL;    // não achou
    }
    if (valor < no->valor) {
        no->esquerda = remover_avl(no->esquerda, valor);
    }
    else if (valor > no->valor) {
        no->direita = remover_avl(no->direita, valor);
    }
    else {
        if (no->esquerda == NULL || no->direita == NULL) {
            NoAVL *filho = no->esquerda != NULL ? no->esquerda : no->direita;
            free(no);
            return filho;
        }
        NoAVL *sucessor = no->direita;
        while (sucessor->esquerda != NULL) {
            sucessor = sucessor->esquerda;
        }
        no->valor = sucessor->valor;
        no->dado = sucessor->dado;
        no->direita = remover_avl(no->direita, sucessor->valor);
    }
    return balancear(no);
}

void *buscar_avl(NoAVL *no, int valor) {
    while (no != NULL) {
        if (valor == no->valor) {
            return no->dado;
        }
        if (valor < no->valor) {
            no = no->esquerda;
        } else {
            no = no->direita;
        }
    }
    return NULL;
}

void percorrer_avl(NoAVL *no, void (*visitar)(void *dado)) {
    if (no != NULL) {
        percorrer_avl(no->esquerda, visitar);
        visitar(no->dado);
        percorrer_avl(no->direita, visitar);
    }
}

void imprimir_ordem(NoAVL *no) {
    if (no != NULL) {
        imprimir_ordem(no->esquerda);
        printf("%d ", no->valor);
        imprimir_ordem(no->direita);
    }
}

void imprimir_avl(NoAVL *no, int nivel) {
    if (no != NULL) {
        imprimir_avl(no->direita, nivel + 1);
        for (int i = 0; i < nivel; i++) {
            printf("        ");
        }
        printf("%d (h=%d, fb=%d)\n", no->valor, no->altura, fator_balanceamento(no));
        imprimir_avl(no->esquerda, nivel + 1);
    }
}

int altura_avl(NoAVL *no) {
    return altura(no);
}

int tamanho_avl(NoAVL *no) {
    if (no == NULL) {
        return 0;
    }
    return 1 + tamanho_avl(no->esquerda) + tamanho_avl(no->direita);
}

void destruir_avl(NoAVL *no) {
    if (no != NULL) {
        destruir_avl(no->esquerda);
        destruir_avl(no->direita);
        free(no);
    }
}