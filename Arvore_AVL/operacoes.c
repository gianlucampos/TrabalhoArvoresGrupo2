//Aqui serao executadas as funções da árvore
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct NO { //criando a estrutura do no da arvore que vai ter o valor, e os ponteiros da esq ou dir
    int valor;
    struct NO *esq;
    struct NO *dir;
};

//---------------------------------------------------------------------------

ArvBin* cria_ArvBin() {
    ArvBin* raiz = (ArvBin*) malloc(sizeof (ArvBin)); // alocando um espaco de memoria para o ponteiro da raiz
    if (raiz != NULL) { //caso o malloc funcione o ponteiro da raiz recebe nulo
        *raiz = NULL;
    }
}

void libera_NO(struct NO* no) {
    if (no == NULL) { //so poderá apagar a raiz se não possuir filho
        return;
    }
    libera_NO(no -> dir); //no da dir vai receber NULL
    libera_NO(no -> esq);
    no = NULL;
}

ArvBin libera_ArvBin(ArvBin *raiz) {
    if (raiz == NULL) {
        return;
    }
    libera_NO(*raiz); //libera os nos
    free(raiz); //libera raiz
}

//----------------------------------------------------------------------------

int estaVazia(ArvBin *raiz) {//verifica se a arvore possui algum elemento
    if (raiz == NULL) {
        return 1;
    }
    if (*raiz == NULL) {
        return 1;
    }
    return 0;

}

int altura(ArvBin *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (*raiz == NULL) {// caso a raiz nao possua nada dentro a altura e = 0
        return 0;
    }
    int alt_esq = altura(&((*raiz)->esq)); // checar se o filho esq é diferente de null
    int alt_dir = altura(&((*raiz)->dir));
    if (alt_esq > alt_dir) {
        return alt_esq + 1; //caso seja ele é + 1
    } else {
        return alt_dir + 1;
    }

}

int totalNO(ArvBin *raiz) {//retorna o numero de nos que a arvore possui
    if (raiz == NULL) {
        return 0;
    }
    if (*raiz == NULL) {
        return 0;
    }
    int alt_esq = totalNO(&((*raiz)->esq));
    int alt_dir = totalNO(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);

}

//-----------------------------------------------------------------------------

void preOrdem_ArvBin(ArvBin *raiz) {//Ordem: raiz esq dir
    if (raiz == NULL) {// nao tem nenhum elemento na arvore, logo ela esta vazia
        return;
    }
    if (*raiz != NULL) {//se a raiz tiver filho(s)....
        printf("%d\n", (*raiz)->valor); //imprima valor do no filho da raiz
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void EmOrdem_ArvBin(ArvBin *raiz) {//Ordem: esq raiz dir
    if (raiz == NULL) {// nao tem nenhum elemento na arvore, logo ela esta vazia
        return;
    }
    if (*raiz != NULL) {//se a raiz tiver filho(s)....
        preOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", ((*raiz)->valor)); //imprima valor do no filho da raiz
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz) {//Ordem: esq dir raiz
    if (raiz == NULL) {// nao tem nenhum elemento na arvore, logo ela esta vazia
        return;
    }
    if (*raiz != NULL) {//se a raiz tiver filho(s)....
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->valor); //imprima valor do no filho da raiz
    }
}
