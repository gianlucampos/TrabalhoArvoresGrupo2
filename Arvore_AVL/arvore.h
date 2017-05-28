//Aqui devemos definir as funçoes da arvore
typedef struct NO* ArvBin;// Passa estrutura do no para uma variavel arvore

//Operações AVL
ArvBin* cria_ArvBin();
ArvBin libera_ArvBin(ArvBin *raiz); //Removerá
void libera_NO(struct NO* no);

//Informações dobre a Árvore
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);

int Busca_No();

void Insere_No();

void Remove_No();

void Rotaciona_No();