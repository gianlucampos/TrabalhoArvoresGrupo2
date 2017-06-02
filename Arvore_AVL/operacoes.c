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

int consulta_ArvBin(ArvAVL *raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    struct NO *atual = *raiz;
    while (atual != NULL) {//enquanto possuir algo na raiz faça...
        if (valor == atual->informacao) {//comparar se o valor passado por parametro esta presente em algum nó
            return 1;
            printf("\nO valor já existe na árvore\n");
        }
        if (valor > atual->informacao) {
            atual = atual->dir; //procura na direita
        } else {
            atual = atual->esq; //procura na esquerda
        }
        return 0; //esse valor não existe na árvore binária
    }
}
//-----------------------------------------------------------------------------

int insere_ArvAVL(ArvAVL *raiz, int valor) {
    int res;
    if (*raiz == NULL) {//arvore esta vazia(sem elemento nenhum) ou no folha(no nao possui filhos)
        struct NO *novo; //passa toda as variaveis de um no para o ponteiro novo
        novo = (struct NO*) malloc(sizeof (struct NO)); // alocar memoria para um novo no
        if (novo == NULL) {//verifica se a alocaçao foi bem sucedida
            return 0;
        }
        novo->informacao = valor; //inserindo o valor no nó
        novo->alt = 0;
        novo->dir = NULL; //passando nulo pois o nó será uma folha inicialmente
        novo->esq = NULL;
        *raiz = novo; // recebendo parametros do no novo
        return 1;
    }
    struct NO *atual = *raiz;
    if (valor < atual->informacao) {//inserir a esquerda caso verdade pois valores menores sao colocados a direita
        if ((res = insere_ArvAVL(&(atual->esq), valor)) == 1) {//se a funcao retornar 1 deu certo
            if (fatorBalanceamento_NO(atual) >= 2) {//se estiver desbalanceada
                if (valor < (*raiz)->esq->informacao) {
                    rotacaoLL(raiz);
                } else {
                    rotacaoLR(raiz);
                }
            }
        }
    } else {
        if (valor > atual->informacao) {//inserir a direita
            if ((res = insere_ArvAVL(&(atual->dir), valor)) == 1) {//se a funcao retornar 1 deu certo
                if (fatorBalanceamento_NO(atual) >= 2) {//se estiver desbalanceada
                    if (valor < (*raiz)->dir->informacao) {
                        rotacaoRR(raiz);
                    } else {
                        rotacaoRL(raiz);
                    }
                }
            }
        } else {
            printf("Valor duplicado!!"); //nao permite valores iguais na arvore
            return 0;
        }
    }
    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;
    return res;
}
//-----------------------------------------------------------------------------
void Remove_ArvBin(); //FALTA FAZER AQUI FAZ BINARIA 1º E DEPOIS MUDA PRA AVL
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
