#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define capacidade 5 //tamanho da pilha

struct Stack
{
       int topo, item[capacidade];
};

typedef struct Stack stack;
 /*============== Inicia Pilha ======================*/
void inic_pilha(stack *p)
{
     p->topo = -1;
}
 
/*=============== Verifica pilha Cheia ==============*/
int pilha_cheia(stack *p)
{
    if (p->topo == (capacidade-1))
    {
          printf ("\n\n\t\tA Pilha esta Cheia!!!");
          return 1;
    }else
        return 0;
}
 
/*=============== Verifica pilha Vazia ==============*/
int pilha_vazia(stack *p)
{
    if (p->topo == -1)
    {
         printf ("\n\n\t\tA Pilha esta Vazia!!!");
         return 1;
    }
    else
     return 0;
}
 
/*=============== Verifica pilha Vazia 2 ============*/
int pilha_vazia2(stack *p)
{
    if (p->topo == -1)
       return 1;
    else
       return 0;
}
 
/*================== Empilha  ========================*/
int push (stack *p, int valor)
{
     return (p->item[++(p->topo)] = valor);
}
 
/*================== Desempilha  =====================*/
int pop (stack *p)
{
    int aux;
    aux = p->item[(p->topo)--];
    return aux;
}
 
/*================== Mostra Pilha  ===================*/
void mostra(stack* p)
{
	printf("\nPilha:\n");
	int i;
	for (i=p->topo; i>=0; i--)
		printf("%i\n",p->item[i]);
}
 
int menu(){
	int opcao;
	printf("\n1 - Criar a pilha\n");
	printf("2 - Inserir na pilha PUSH\n");
	printf("3 - Remover da pilha POP\n");
	printf("4 - Buscar valor na pilha\n");
	//printf("5 - Remover a pilha\n");
	printf("6 - Mostrar a pilha\n");
	printf("0 - Sair\n");
	scanf("%i",&opcao);
	return(opcao);
}

int main()
{
	int opcao, x;	
	stack pilha;
	
	do{ 
		opcao = menu();
		switch(opcao){
			case 1: inic_pilha(&pilha);
					break;
			case 2: printf("Elemento a ser inserido: ");
					scanf("%d",&x);
					push(&pilha, x);
					break;
			case 3: x = pop(&pilha);
					printf("Elemento removido: %d\n",x);
					break;
			case 4: printf("Elemento a ser buscado: ");
					scanf("%d",&x);
					//busca(&pilha,x);
					break;
			case 5: //libera(&pilha);
					break; 
			case 6: mostra(&pilha);
					break;
			} 
	}while(opcao !=0);
}


