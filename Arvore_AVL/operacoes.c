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

//Teste para ver o funcionamento
