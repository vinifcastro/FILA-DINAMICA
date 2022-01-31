#include "fila.h"

int main(){
    Fila *fila;
    int opcao, init = 0, valor;
    do{
        system("CLS");
        printf("\t00 - Sair.\n\t01 - Inicializar fila.\n\t02 - Verificar se a fila esta vazia.\n\t03 - Enfileirar.\n\t04 - Desenfileirar.\n\t05 - Imprimir fila.\n\t06 - Quantas pessoas na fila.\n\t07 - Mostra fila ao contrario.\n");
        printf("\nDigite uma opcao:\n");
        scanf("%d%*c", &opcao);
        switch (opcao){
            case 1:
                system("CLS");
                if (init != 0) printf("Fila ja inicializada!\n");
                else{
                    inicializa_fila(&fila);
                    init++;
                }
                break;
            case 2:
                system("CLS");
                if (init == 0) {
                    printf("Fila nao inicializada!\n");
                    break;
                }
                if(verifica_vazia(fila)) printf("Fila Vazia\n");
                else printf("A fila nao esta vazia!\n");
                break;
            case 3:
                system("CLS");
                if (init == 0) {
                    printf("Fila nao inicializada!\n");
                    break;
                }
                printf("Digite a idade da pessoa a ser inserida na fila: (Caso a idade seja maior ou igual a 60 tera prioridade)\n");
                scanf("%d%*c", &valor);
                enfileira_numero(&fila, valor);
                break;
            case 4:
                system("CLS");
                if (init == 0) {
                    printf("Fila nao inicializada!\n");
                    break;
                }
                desenfileirar(&fila);
                break;
            case 5:
                system("CLS");
                if (init == 0) {
                    printf("Fila nao inicializada!\n");
                    break;
                }
                mostra_fila(fila);
                break;
            case 6:
                system("CLS");
                if (init == 0) {
                    printf("Fila nao inicializada!\n");
                    break;
                }
                valor = qtd_fila(fila);
                if(valor) printf("A fila possui %d pessoas!\n", valor);
                else printf("A fila esta vazia!\n");
                break;
            case 7:
                system("CLS");
                if (init == 0) {
                    printf("Fila nao inicializada!\n");
                    break;
                }
                if(verifica_vazia(fila)) {
                    printf("Fila Vazia\n");
                    break;
                }
                printf("\t------------- Inicio da Fila -------------\t\n\n");
                print_fila_contrario(fila);
                printf("\n\n\t------------- Final da Fila -------------\t\n");
                break;
            default:
                system("CLS");
                if(opcao == 0) printf("Finalizado programa...\n");
                else printf("Opcao invalida!!!\n");
                break;
        }
        system("PAUSE");
    }while(opcao);
    libera_fila(&fila);
    return 0;
}