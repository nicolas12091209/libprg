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

#endif //LABORATORIO_LIBPRG_H
