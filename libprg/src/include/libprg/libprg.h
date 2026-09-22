#ifndef LABORATORIO_LIBPRG_H
#define LABORATORIO_LIBPRG_H
#include <stdbool.h>

typedef struct Fila Fila;

Fila *criar_fila();

void inserir_fila(Fila *fila, int valor);

int remover_fila(Fila *fila);

int inicio_fila(Fila *fila);

int fim_fila(Fila *fila);

int tamanho_fila(Fila *fila);

void imprimir_fila(Fila *fila);

void destruir_fila(Fila *fila);


void ex_1_fila();
void ex_2_fila();
void ex_3_fila();
void ex_4_fila();
void ex_5_fila();
void ex_6_fila();
void ex_7_fila();

#define TAM_MAX 100

typedef struct {
    int dados[TAM_MAX];
    int topo;
} Pilha;

void pilha_iniciar(Pilha *pilha);
int pilha_vazia(Pilha *pilha);
int pilha_tamanho(Pilha *pilha);
int pilha_cheia(Pilha *pilha);
int pilha_empilhar(Pilha *pilha, int valor);
int pilha_desempilhar(Pilha *pilha, int *valor);

#define TAM_MAX_LISTA 100

typedef struct {
    int dados[TAM_MAX_LISTA];
    int tamanho;
} Lista;

void criar_lista(Lista *lista);
int inserir_lista(Lista *lista, int dado);
int remover_lista(Lista *lista, int dado);
int busca_lista(Lista *lista, int dado);
void imprime_lista(Lista *lista);



#endif //LABORATORIO_LIBPRG_H
