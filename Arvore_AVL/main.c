#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {

    ArvAVL *raiz;
    raiz = cria_ArvBin();
    int opcaoMenu, opcaoInformacao, opcaoPercorre, opcaoOperacao;
    do {
        printf("\nArvore AVL: Escolha uma opção:\n");
        printf("0-Sair: \n");
        printf("1-Informações da Árvore: \n");
        printf("2-Percorrer a Árvore: \n");
        printf("3-Operações com a Árvore: \n");
        printf("------------------------");
        printf("\nOpção escolhida: ");
        scanf("%d", &opcaoMenu);

        if (opcaoMenu == 1) {
            printf("------------------------\n");
            printf("\nEscolha uma opção:\n");
            printf("0-Sair: \n");
            printf("1-Voltar para o menu principal: \n");
            printf("2-Mostrar a altura da Árvore\n");
            printf("3-Mostrar o Nº de elementos que possui a Árvore\n");
            printf("------------------------");
            printf("\nOpção escolhida: ");
            scanf("%d", &opcaoInformacao);
            if (opcaoInformacao == 0) {
                return (EXIT_SUCCESS);
            } else if (opcaoInformacao == 1) {
                printf("------------------------");
            } else if (opcaoInformacao == 2) {
                printf("------------------------");
                int altura = altura_Arv(raiz);
                printf("\nA altura da árvore é: %d\n", altura);
                printf("------------------------");
            } else if (opcaoInformacao == 3) {
                printf("------------------------");
                int total = totalNO(raiz);
                printf("\nA árvore possui %d elementos\n", total);
                printf("------------------------");
            }
        } else if (opcaoMenu == 2) {
            printf("------------------------\n");
            printf("\nEscolha uma opção:\n");
            printf("0-Sair: \n");
            printf("1-Voltar para o menu principal: \n");
            printf("2-Percorrer a Árvore em Pré Ordem\n");
            printf("3-Percorrer a Árvore em Ordem \n");
            printf("4-Percorrer a Árvore em Pós Ordem \n");
            printf("------------------------");
            printf("\nOpção escolhida: ");
            scanf("%d", &opcaoPercorre);
            if (opcaoPercorre == 0) {
                return (EXIT_SUCCESS);
            } else if (opcaoPercorre == 1) {
                printf("------------------------");
            } else if (opcaoPercorre == 2) {
                printf("------------------------");
                preOrdem_ArvBin(raiz);
                printf("------------------------");
            } else if (opcaoPercorre == 3) {
                printf("------------------------");
                EmOrdem_ArvBin(raiz);
                printf("------------------------");
            } else if (opcaoPercorre == 4) {
                printf("------------------------");
                posOrdem_ArvBin(raiz);
                printf("------------------------");
            }

        } else if (opcaoMenu == 3) {
            printf("------------------------\n");
            printf("\nEscolha uma opção:\n");
            printf("0-Sair: \n");
            printf("1-Voltar para o menu principal: \n");
            printf("2-Consultar se existe o valor X na Árvore\n");
            printf("3-Inserir algum no na Árvore\n");
            printf("4-Remover algum no na Árvore \n");
            printf("------------------------");
            printf("\nOpção escolhida: ");
            scanf("%d", &opcaoOperacao);
            if (opcaoOperacao == 0) {
                return (EXIT_SUCCESS);
            } else if (opcaoOperacao == 1) {
                printf("------------------------");
            } else if (opcaoOperacao == 2) {
                printf("------------------------");
                int valor;
                printf("\nDigite o valor do no que você deseja buscar na Árvore: ");
                scanf("%d", &valor);
                printf("------------------------");
                int consulta = consulta_ArvBin(raiz, valor);
                if (consulta == 1) {
                    printf("\nO valor já existe na árvore\n");
                } else {
                    printf("\nO valor não existe e pode ser inserido na árvore\n");
                }
                printf("------------------------");
            } else if (opcaoOperacao == 3) {
                printf("------------------------");
                int valor;
                printf("\nDigite o valor do no que você deseja inserir da Árvore: ");
                scanf("%d", &valor);
                printf("------------------------");
                int insere_valor; //se deu certo retorna 1 
                insere_valor = insere_ArvAVL(raiz, valor);
                if (insere_valor == 1) {
                    printf("\nO valor foi inserido com êxito!!\n");
                    printf("------------------------");
                } else {
                    printf("\nNão foi possível inserir o elemento na Árvore!!\n");
                    printf("------------------------");
                }
                printf("------------------------");
            } else if (opcaoOperacao == 4) {
                printf("------------------------");
                int valor;
                printf("\nDigite o valor do no que você deseja remover da Árvore: ");
                scanf("%d", &valor);
                printf("------------------------");
                int remove; //se deu certo retorna 1 
                remove = remove_ArvAVL(raiz, valor);
                if (remove == 1) {
                    printf("------------------------");
                    printf("\nO valor foi removido com êxito!!");
                    printf("------------------------");
                } else {
                    printf("------------------------");
                    printf("\nErro ao inserir elemento na Árvore!!");
                    printf("------------------------");
                }
                printf("------------------------");
            }
        }
    } while (opcaoMenu != 0);

    libera_ArvBin(raiz);
    return (EXIT_SUCCESS);
}