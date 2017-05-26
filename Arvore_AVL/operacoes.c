//Aqui serao executadas as funções da árvore
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct No {//criando a estrutura do no da arvore que vai ter o valor, e os ponteiros da esq ou dir
    int valor;
    struct NO *esq;
    struct NO *dir;
};
