//Aqui devemos definir as funçoes da arvore
typedef struct NO* ArvAVL; // Passa estrutura do no para uma variavel arvore

//----------Operações básicas------------
ArvAVL* cria_ArvBin();
void libera_NO(struct NO* no);
ArvAVL libera_ArvBin(ArvAVL *raiz);
//----------Informações da arvore--------
int estaVazia(ArvAVL *raiz);
int altura_Arv(ArvAVL *raiz);
int alt_NO(struct NO* no);
int totalNO(ArvAVL *raiz);
//----------Ordem de busca----------------
void preOrdem_ArvBin(ArvAVL *raiz);
void EmOrdem_ArvBin(ArvAVL *raiz);
void posOrdem_ArvBin(ArvAVL *raiz);
//----------Remocao-----------------------
void Remove_ArvBin();//Falta fazer em binario 
//---------Consulta----------------------
int consulta_ArvBin(ArvAVL *raiz, int valor);
//----------Operações AVL----------------
//No avl só vai mudar a inserção e remoção
//----------Insercao---------------------
int insere_ArvAVL(ArvAVL *raiz, int valor);
//----------Remoção----------------------
//Depois de fazer em binario mudar para AVL
//---------Balanceamento-----------------
int fatorBalanceamento_NO(struct NO* no);
int maior(int x, int y);
//-----------Rotação---------------------
void rotacaoLL(ArvAVL *raiz);
void rotacaoRR(ArvAVL *raiz);
void rotacaoLR(ArvAVL *raiz);
void rotacaoRL(ArvAVL *raiz);