//Aqui devemos definir as funçoes da arvore
typedef struct NO* ArvBin;// Passa estrutura do no para uma variavel arvore

//----------Operações básicas------------
ArvBin* cria_ArvBin();
void libera_NO(struct NO* no);
ArvBin libera_ArvBin(ArvBin *raiz);
//----------Informações da arvore--------
int estaVazia(ArvBin *raiz);
int altura(ArvBin *raiz);
int totalNO(ArvBin *raiz);
//----------Ordem de busca----------------
void preOrdem_ArvBin(ArvBin *raiz);
void EmOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
//----------Operações AVL----------------(IMPLEMENTAR POR ULTIMO)
int Consulta_No();
void Insere_No();
void Remove_No();
void Rotaciona_No();
