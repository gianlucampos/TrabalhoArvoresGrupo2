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
// Calcula altura do nó

int alt_NO(struct NO* no) {
    if (no == NULL) {
        return -1;
    } else {
        return no->alt;
    }
}

//Calcula o fator de balanceamento do nó

int fatorBalanceamento_NO(struct NO* no) {
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

int maior(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

// Rotações simples RR e LL atualizam nova altura das sub arvores

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
}

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

// Rotaçoes duplas LR e RL sao implementadas com 2 rot. simples

void rotacaoLR(ArvAVL *raiz) {
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(ArvAVL *raiz){
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

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

int altura(ArvAVL *raiz) {// retorna a raiz da arvore
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

int altura NO(struct NO* no) {
    if (no == NULL) {
        return -1;
    } else {
        return no->alt;
    }
}

int insere_ArvBin(ArvAVL* raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof (struct NO));
    if (novo == NULL) {
        return 0;
    }
    novo->informacao = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if (*raiz == NULL) {
        *raiz = novo;
    } else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while (atual != NULL) {
            ant = atual;
            if (valor == atual->informacao) {
                free(novo);
                return 0;
            }
            if (valor > atual->informacao) {
                atual = atual->dir;
            } else {
                atual = atual->esq;
            }
            if (valor > ant->informacao) {
                ant->dir = novo;
            } else {
                ant->esq = novo;
            }
            return 1;
        }
    }
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
