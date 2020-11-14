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

void mostra(node *LISTA)
{
	if(!LISTA)
		printf("Lista não iniciada \n");	
		 
	if(LISTA->prox == NULL)
		printf("Lista Vazia \n");	
	else{
		node *aux;
		aux = LISTA->prox;
		while(aux != NULL)
		{
			printf("%i ",aux->num);
	    	aux = aux->prox;
		}
		printf("\n");
	}
}

void cria(node *LISTA)
{
	LISTA->prox = NULL;
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
  		return 1;
 	else
  		return 0;
}

void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,	*atual;
		
		while(LISTA->prox != NULL){
			proxNode = LISTA->prox;
	   		free(LISTA);
	   		LISTA = proxNode;
	   		printf("valor removido \n");
	  	}
 	}
 	else
 		printf("Lista vazia already");
}

int busca(node *LISTA,int x)
{
	node *p;
	p = LISTA;
	while(p != NULL && p->num != x){
		p = p->prox;
	}

	if(p == NULL) {
        printf("Nao achou\n");
    }
	else{
        printf("Achou\n");
	}
}

int remove(node *LISTA) {
	
	node *p = LISTA->prox; 
	
	if(vazia(LISTA))
		printf("Fila vazia \n");
	else{
		/* retira elemento */
		int x = p->num;
   		LISTA->prox = p->prox;
   		free (p);
   		return x;
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
	node *FILA = (node *) malloc(sizeof(node));
	do{ 
		opcao = menu();
		switch(opcao){
			case 1: cria(FILA);
					break;
			case 2: printf("Elemento a ser inserido: ");
					scanf("%d",&x);
					insereFim(FILA, x);
					break;
			case 3: x = remove(FILA);
					printf("Elemento removido %i\n: ",x);
					break;
			case 4: printf("Elemento a ser buscado: ");
					scanf("%d",&x);
					busca(FILA,x);
					break;
			case 5: libera(FILA);
					break; 
			case 6: mostra(FILA);
					break;
			} 
	}while(opcao !=0);
}


