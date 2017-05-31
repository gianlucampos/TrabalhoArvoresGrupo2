//Aqui devemos definir as funçoes da arvore
typedef struct NO* ArvAVL;// Passa estrutura do no para uma variavel arvore

//----------Operações básicas------------
ArvAVL* cria_ArvBin();
void libera_NO(struct NO* no);
ArvAVL libera_ArvBin(ArvAVL *raiz);
//----------Informações da arvore--------
int estaVazia(ArvAVL *raiz);
int altura(ArvAVL *raiz);
int totalNO(ArvAVL *raiz);
//----------Ordem de busca----------------
void preOrdem_ArvBin(ArvAVL *raiz);
void EmOrdem_ArvBin(ArvAVL *raiz);
void posOrdem_ArvBin(ArvAVL *raiz);

//---------Operações Binárias-------------
int insere_ArvBin(ArvAVL* raiz, int valor);
//----------Operações AVL----------------(IMPLEMENTAR POR ULTIMO)
int Consulta_No();
void Insere_No();
int alt_NO(struct NO* no);
int fatorBalanceamento_NO(struct NO* no);
int maior(int x, int y);
void rotacaoLL(ArvAVL *raiz);
void rotacaoRR(ArvAVL *raiz);
void rotacaoLR(ArvAVL *raiz);
void rotacaoRL(ArvAVL *raiz);
void Remove_No();
