//Aqui serao executadas as funções da árvore
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct NO { //criando a estrutura do no da arvore que vai ter o valor, e os ponteiros da esq ou dir
    int informacao;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

//---------------------------------------------------------------------------

ArvAVL* cria_ArvBin() {
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof (ArvAVL)); // alocando um espaco de memoria para o ponteiro da raiz
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

ArvAVL libera_ArvBin(ArvAVL *raiz) {
    if (raiz == NULL) {
        return;
    }
    libera_NO(*raiz); //libera os nos
    free(raiz); //libera raiz
}

//----------------------------------------------------------------------------

int estaVazia(ArvAVL *raiz) {//verifica se a arvore possui algum elemento
    if (raiz == NULL) {
        return 1;
    }
    if (*raiz == NULL) {
        return 1;
    }
    return 0;

}

int altura_Arv(ArvAVL *raiz) {// retorna a altura da arvore
    if (raiz == NULL) {
        return 0;
    }
    if (*raiz == NULL) {// caso a raiz nao possua nada dentro a altura e = 0
        return 0;
    }
    int alt_esq = alt_NO(&((*raiz)->esq)); // checar se o filho esq é diferente de null
    int alt_dir = alt_NO(&((*raiz)->dir));
    if (alt_esq > alt_dir) {
        return alt_esq + 1; //caso seja ele é + 1
    } else {
        return alt_dir + 1;
    }

}

int alt_NO(struct NO* no) {// Calcula altura do nó
    if (no == NULL) {
        return -1;
    } else {
        return no->alt;
    }
}

int totalNO(ArvAVL *raiz) {//retorna o numero de nos que a arvore possui
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

void preOrdem_ArvBin(ArvAVL *raiz) {//Ordem: raiz esq dir
    if (raiz == NULL) {// nao tem nenhum elemento na arvore, logo ela esta vazia
        return;
    }
    if (*raiz != NULL) {//se a raiz tiver filho(s)....
        printf("%d\n", (*raiz)->informacao); //imprima valor do no filho da raiz
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void EmOrdem_ArvBin(ArvAVL *raiz) {//Ordem: esq raiz dir
    if (raiz == NULL) {// nao tem nenhum elemento na arvore, logo ela esta vazia
        return;
    }
    if (*raiz != NULL) {//se a raiz tiver filho(s)....
        preOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", ((*raiz)->informacao)); //imprima valor do no filho da raiz
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvAVL *raiz) {//Ordem: esq dir raiz
    if (raiz == NULL) {// nao tem nenhum elemento na arvore, logo ela esta vazia
        return;
    }
    if (*raiz != NULL) {//se a raiz tiver filho(s)....
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->informacao); //imprima valor do no filho da raiz
    }
}

//-----------------------------------------------------------------------------

int insere_ArvBin(ArvAVL *raiz, int valor) {
    if (raiz == NULL) {// verifica se existe alguma raiz na arvore
        return 0;
    }
    struct NO *novo; //passa toda as variaveis de um no para o ponteiro novo
    novo = (struct NO*) malloc(sizeof (struct NO)); // alocar memoria para um novo no
    if (novo == NULL) {//verifica se a alocaçao foi bem sucessedida
        return 0;
    }
    novo->informacao = valor; //inserindo o valor no nó
    novo->dir = NULL; //passando nulo pois o nó será uma folha inicialmente
    novo->esq = NULL;

    //ONDE INSERIR ?

    if (*raiz == NULL) {//se for uma arvore vazia
        *raiz = novo; //cria-se um no
    } else {
        struct NO* atual = *raiz; // vai receber o ponteiro da raiz
        struct NO* ant = NULL; //como o atual vai ser a raiz nao temos outro elemento na arvore
        while (atual != NULL) {//continua percorrendo a arvore ate nao possuir mais filhos
            ant = atual;
            if (valor == atual->informacao) {//se o valor que quisermos inserir ja possui na arvore
                free(novo); //desalocamos o no novo 
                printf("O elemento atual já existe na arvore");
                return 0;
            }//caso não exista inserimos um filho no nó
            if (valor == atual->informacao) {//Comparar para inserir o maior elemento a direita sempre
                atual = atual->dir;
            } else {
                atual = atual->esq;
            }
        }
    }
    return 1;
}
//-----------------------------------------------------------------------------

int fatorBalanceamento_NO(struct NO* no) {
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}//Calcula o fator de balanceamento do nó

int maior(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}
//-----------------------------------------------------------------------------

void rotacaoLL(ArvAVL *raiz) {

    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq),
            alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->esq),
            (*raiz)->alt) + 1;
    *raiz = no;
}// Rotações simples RR e LL atualizam nova altura das sub arvores

void rotacaoRR(ArvAVL *raiz) {
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_NO((*raiz)->esq),
            alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->dir), (*raiz)->alt) + 1;
    (*raiz) = no;
}

void rotacaoLR(ArvAVL *raiz) {
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}// Rotaçoes duplas LR e RL sao implementadas com 2 rot. simples

void rotacaoRL(ArvAVL *raiz) {
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}
