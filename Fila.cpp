#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define capacidade 3 //tamanho da fila

struct Queue
{
       int frente, atras, item[capacidade-1];
};

typedef struct Queue queue;
 /*============== Inicia fila ======================*/
void inic_fila(queue *p)
{
    p->frente = -1;
    p->atras = -1;
}
 
/*=============== Verifica fila Cheia ==============*/
int fila_cheia(queue *p)
{
    if (p->atras == (capacidade-1))
    {
        printf ("\n\tA Fila esta Cheia!!!");
        return 1;
    }else
        return 0;
}
 
/*=============== Verifica fila Vazia ==============*/
int fila_vazia(queue *p)
{
    if (p->frente == p->atras)
    {
        printf ("\n\tA Fila esta Vazia!!!");
        return 1;
    }
    else
    	return 0;
}
 
/*================== Insere na fila  ========================*/
void enqueue (queue *p, int valor)
{
	if (!fila_cheia(p)){
		p->atras++;
		p->item[p->atras] = valor;
	}
}
 
/*================== desenfila  =====================*/
int dequeue (queue *p)
{
	if (!fila_vazia(p))
	{
	    int aux;
	    aux = p->item[p->frente+1];
	    p->frente++;
	    printf("removido %i\n",aux);
	    return aux;
	}
}
 
/*================== Mostra lista  ===================*/
void mostra(queue* p)
{
	if (!fila_vazia(p))
	{
		//	printf("%i ",p->frente);
		//	printf("%i ",p->atras);
		printf("\nFila:\n");
		int i;
		for (i=p->frente+1; i<=p->atras; i++)
			printf("%i ",p->item[i]);
	}

}
 
int menu(){
	int opcao;
	printf("\n1 - Criar a fila\n");
	printf("2 - Inserir na fila ENQUEUE\n");
	printf("3 - Remover da fila DEQUEUE\n");
	printf("4 - Buscar valor na Lista\n");
	//printf("5 - Remover a fila\n");
	printf("6 - Mostrar a fila\n");
	printf("0 - Sair\n");
	scanf("%i",&opcao);
	return(opcao);
}

int main()
{
	int opcao, x;	
	queue fila;
	
	do{ 
		opcao = menu();
		switch(opcao){
			case 1: inic_fila(&fila);
					break;
			case 2: printf("Elemento a ser inserido: ");
					scanf("%d",&x);
					enqueue(&fila, x);
					break;
			case 3: x = dequeue(&fila);
					printf("Elemento removido: %d\n",x);
					break;
			case 4: printf("Elemento a ser buscado: ");
					scanf("%d",&x);
					break;
			case 5: //libera(&fila);
					break; 
			case 6: mostra(&fila);
					break;
			} 
	}while(opcao !=0);
}


