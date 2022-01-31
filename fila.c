#include "fila.h"

void inicializa_fila(Fila ** fila){
    *fila = NULL;
    printf("Fila inicializada com sucesso!\n");
}

int verifica_vazia(Fila * fila){
    if(fila == NULL) return 1;
    else return 0; 
}

void enfileira_numero(Fila ** fila, int n){
    Fila *prox, *aux, *novo = NULL;
    novo = (Fila *) malloc(sizeof(Fila));
    if(novo){
        novo->valor = n;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            if(n>59){
                if((*fila)->valor<60){
                    novo->proximo = *fila;
                    *fila = novo;
                }
                else{
                    aux = *fila;
                    prox = aux->proximo;
                    while(aux->proximo && (prox->valor >= 60) ) {
                        aux = aux->proximo;
                        prox = aux->proximo;
                    }
                    aux->proximo = novo;
                    novo->proximo = prox; 
                }
            }
            else{
                aux = *fila;
                while(aux->proximo)
                    aux = aux->proximo;
                aux->proximo = novo;
            }
        }
        printf("Elemento %d inserido a fila com sucesso!\n", n);
    }
    else printf("Erro ao criar posicao na fila!\n");
}

void desenfileirar(Fila ** fila){
    Fila * aux = NULL;
    if(*fila){
        aux = *fila;
        *fila = (*fila)->proximo;
        printf("Elemento %d removido da fila com sucesso.\n", aux->valor);
        free(aux);
    }
    else printf("Fila esta Vazia!\n");
}

void libera_fila(Fila ** fila){
    Fila * aux;
    if (*fila == NULL) return;
    aux = *fila;
    while((*fila)->proximo){
        *fila = (*fila)->proximo;
        free(aux);
        aux = *fila;
    }
    free(aux);
}

void mostra_fila(Fila *fila){
    if (verifica_vazia(fila)){
        printf("Fila Vazia!\n");
        return;
    }
    printf("\t------------- Inicio da Fila -------------\t\n\n");
    while(fila->proximo){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("%d ", fila->valor);
    printf("\n\n\t------------- Final da Fila -------------\t\n");
}

int qtd_fila(Fila *fila){  
    int qtd = 1;
    Fila * aux = NULL;
    if (verifica_vazia(fila)) return 0;
    aux = fila;
    while(aux->proximo){
        qtd++;
        aux = aux->proximo;
    }
    return qtd;
}

void print_fila_contrario(Fila * fila){
    Fila * aux = NULL;
    int i;
    if(fila == NULL) return;
    aux = fila;
    i = aux->valor;
    print_fila_contrario(aux->proximo);
    printf("%d ", i);
}