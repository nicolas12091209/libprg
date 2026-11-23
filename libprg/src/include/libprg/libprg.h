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

typedef struct NoListaDupla {
    int dado;
    struct NoListaDupla *anterior;
    struct NoListaDupla *proximo;

} NoListaDupla;

typedef struct {
    NoListaDupla *inicio;
    NoListaDupla *fim;
    int tamanho;

} ListaDupla;

void criar_lista_dupla(ListaDupla *lista);
int inserir_inicio_dupla(ListaDupla *lista, int dado);
int inserir_fim_dupla(ListaDupla *lista, int dado);
int remover_inicio_dupla(ListaDupla *lista);
int remover_fim_dupla(ListaDupla *lista);
int remover_dupla(ListaDupla *lista, int dado);
int buscar_dupla(ListaDupla *lista, int dado);
void imprimir_dupla(ListaDupla *lista);
void imprimir_dupla_reversa(ListaDupla *lista);
void destruir_lista_dupla(ListaDupla *lista);


#define TAM_CHAVE_ABP 100

typedef struct NoABP {
    char chave[TAM_CHAVE_ABP];
    void *dado;
    struct NoABP *esquerda;
    struct NoABP *direita;
} NoABP;

typedef struct {
    NoABP *raiz;
    int tamanho;
} ABP;

void criar_abp(ABP *arvore);
int inserir_abp(ABP *arvore, const char *chave, void *dado);
void *buscar_abp(ABP *arvore, const char *chave);
int remover_abp(ABP *arvore, const char *chave, void *dado);
void em_ordem_abp(ABP *arvore, void (*visitar)(void *dado));
int altura_abp(ABP *arvore);
void destruir_abp(ABP *arvore);

typedef struct NoAVL {
    int valor;
    void *dado;
    int altura;
    struct NoAVL *esquerda;
    struct NoAVL *direita;
} NoAVL;

NoAVL *inserir_avl(NoAVL *no, int valor, void *dado);
NoAVL *remover_avl(NoAVL *no, int valor);
void *buscar_avl(NoAVL *no, int valor);
void percorrer_avl(NoAVL *no, void (*visitar)(void *dado));
void imprimir_ordem(NoAVL *no);
void imprimir_avl(NoAVL *no, int nivel);
int altura_avl(NoAVL *no);
int tamanho_avl(NoAVL *no);
void destruir_avl(NoAVL *no);


#endif //LABORATORIO_LIBPRG_H
