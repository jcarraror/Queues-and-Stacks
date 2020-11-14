#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Node
{
	int num;
	Node* prox;
};
typedef struct Node node;
 
// função para inserir um número (nó) na lista
void insereFim(node *LISTA, int numero)
{
	node *novo = (node *) malloc(sizeof(node));
	novo->num = numero;
	novo->prox = NULL;
	
	// inserção no fim da lista
	if(LISTA->prox == NULL)
		LISTA->prox = novo;
	else
	{
		node *aux = (node *) malloc(sizeof(node));
		aux = LISTA->prox;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
	}
}

void insereInicio(node *LISTA, int x)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	node *oldHead = LISTA->prox;
	novo->num = x;
	LISTA->prox = novo;
	novo->prox = oldHead;
}


int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
  		return 1;
 	else
  		return 0;
}

void mostraRecursiva(node *LISTA)
{
	if ( !vazia(LISTA)) {
		/* imprime primeiro elemento */
		printf("Info: %d\n",LISTA->prox->num);
		/* imprime sub-lista */
		mostraRecursiva(LISTA->prox);
	}
//	else
//		printf("Lista Vazia!\n");
}

void cria(node *LISTA)
{
	LISTA->prox = NULL;
}

node* removeRecursivo(node *LISTA, int val) 
//Elemento* lst_retira_rec (Elemento* lst, int val)
{
	if (!vazia(LISTA)) {
		/* verifica se elemento a ser retirado é o primeiro */
		if (LISTA->prox->num == val) {
			
			node* t = LISTA->prox;/* temporário para poder liberar */
			LISTA->prox = LISTA->prox->prox;
			free(t);
			}
		else {
			/* retira de sub-lista */
			LISTA->prox = removeRecursivo(LISTA->prox,val);
		}
	}
	else
		printf("Lista Vazia \n");
	return LISTA;
}
	
void liberaRecursivo(node* LISTA)
{
	if (!vazia(LISTA))
	{
		liberaRecursivo(LISTA->prox);
		free(LISTA);
	}
}

int menu(){
	int opcao;
	printf("1 - Criar a lista\n");
	printf("2 - Inserir na lista\n");
	printf("3 - Remover da lista\n");
	printf("4 - Buscar valor\n");
	printf("5 - Remover a lista\n");
	printf("6 - Mostrar a lista\n");
	printf("0 - Sair\n");
	scanf("%i",&opcao);
	return(opcao);
}

int main()
{
	int opcao, x;	
	node *LISTA = (node *) malloc(sizeof(node));
	do{ 
		opcao = menu();
		switch(opcao){
			case 1: cria(LISTA);
					break;
			case 2: printf("Elemento a ser inserido: ");
					scanf("%d",&x);
					//insereInicio(LISTA, x);
					insereFim(LISTA, x);
					break;
			case 3: printf("Elemento a ser removido: ");
					scanf("%d",&x);
					removeRecursivo(LISTA, x);
					break;
			case 4: printf("Elemento a ser buscado: ");
					scanf("%d",&x);
					//busca(LISTA,x);
					break;
			case 5: liberaRecursivo(LISTA);
					break; 
			case 6: mostraRecursiva(LISTA);
					break;
			} 
	}while(opcao !=0);
}


