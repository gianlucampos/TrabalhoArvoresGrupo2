//Aqui devemos definir as funçoes da arvore
typedef struct No* ArvBin;// aqui vamos passar a estrutura do no para uma variavel arvore

//Operações AVL
ArvBin* cria_ArvBin();
ArvBin libera_ArvBin(ArvBin *raiz); //Removerá
void libera_NO(struct NO* no);

int Busca_No();

void Insere_No();

void Remove_No();

void Rotaciona_No();