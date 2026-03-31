#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H


typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
bool vazia(pilha_t* pilha);
int tamanho(pilha_t* pilha);
int destruir_pilha(pilha_t* pilha);


typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
int enfileirar(fila_t* fila, int valor);
void destruir_fila(fila_t* fila);
int desenfileirar (fila_t* fila);
int fila_vazia(fila_t* fila);
int inicio_fila(fila_t* fila);
int fim_fila(fila_t* fila);
int cheia(fila_t* fila);
#endif
