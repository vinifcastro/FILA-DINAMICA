#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Fila{
    int valor;
    struct Fila *proximo;
}Fila;

void inicializa_fila(Fila ** fila);

int verifica_vazia(Fila * fila);

void enfileira_numero(Fila ** fila, int n);

void desenfileirar(Fila ** fila);

void libera_fila(Fila ** fila);

void mostra_fila(Fila *fila);

int qtd_fila(Fila *fila);

void print_fila_contrario(Fila * fila);