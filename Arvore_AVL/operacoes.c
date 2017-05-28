//Aqui serao executadas as funções da árvore
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct NO {             //criando a estrutura do no da arvore que vai ter o valor, e os ponteiros da esq ou dir
    int valor;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin () {
    ArvBin* raiz = (ArvBin*) malloc(sizeof (ArvBin)); // alocando um espaco de memoria para o ponteiro da raiz
    if(raiz != NULL) {   //caso o malloc funcione o ponteiro da raiz recebe nulo
        *raiz = NULL;
    }
}

void libera_NO(struct NO* no){
    if(no == NULL){   //so poderá apagar a raiz se não possuir filho
        return;
    }
    libera_NO(no -> dir); //no da dir vai receber NULL
    libera_NO(no -> esq);
    no = NULL;
}

ArvBin libera_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz); //libera os nos
    free(raiz);  //libera raiz
}

int estaVazia_ArvBin(ArvBin *raiz) {
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int altura_ArvBin(ArvBin *raiz) {
    if(raiz == NULL){
        return 0;
    }
    if (*raiz == NULL){ //caso a raiz não possua nada dentro a atura é = 0
        return 0;
    } 
    int alt_esq = altura_ArvBin (& ((*raiz)->esq)); //Checar se o filho esq é diferente de nulo
    int alt_dir = altura_ArvBin (&((*raiz)->dir)); //Checar se o filho dir é diferente de nulo
    if(alt_esq > alt_dir) {
        return alt_esq + 1; //caso seja ele é + 
    } else {
        return alt_dir + 1;
    }
}

void int totalNO_ArvBin (ArvBin *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (*raiz == NULL) {
        return 0;
    }
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

