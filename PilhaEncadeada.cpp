#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct no {
	int info;
	struct no* prox;
};
typedef struct no No;

struct pilha {
	No* prim;
};
typedef struct pilha Pilha;

 /*============== Inicia Pilha ======================*/
Pilha* cria (Pilha* p)
{	
	p->prim = NULL;
	return p;
}
  
/*=============== Verifica pilha Vazia ==============*/
int vazia(Pilha* p)
{
	return (p->prim==NULL);
}
 
/* função auxiliar: insere no início */
No* ins_ini(No* l, int v)
{
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = l;
	return p;
}

/* função auxiliar: retira do início */
No* ret_ini(No* l)
{
	No* p = l->prox;
	free(l);
	return p;
} 
 
/*================== Empilha  ========================*/
void push(Pilha* p, int v)
{
	p->prim = ins_ini(p->prim,v);
}
/*================== Desempilha  =====================*/
int pop(Pilha* p)
{
	int v;
	if (vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1); /* aborta programa */
	}
	v = p->prim->info;
	p->prim = ret_ini(p->prim);
	return v;
} 

/*================== Mostra Pilha  ===================*/
void imprime(Pilha* p)
{
	No* q;
	for (q=p->prim; q!=NULL; q=q->prox)
		printf("%d\n",q->info);
}

/*================== Libera ===================*/
void libera (Pilha* p)
{
	No* q = p->prim;
	while (q!=NULL) {
		No* t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}
 
int menu(){
	int opcao;
	printf("1 - Criar a pilha\n");
	printf("2 - Inserir na pilha PUSH\n");
	printf("3 - Remover da pilha POP\n");
	printf("5 - Desalocar\n");
	printf("6 - Mostrar a pilha\n");
	printf("0 - Sair\n");
	scanf("%i",&opcao);
	return(opcao);
}

int main()
{
	int opcao, x;	
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	do{ 
		opcao = menu();
		switch(opcao){
			case 1: cria(p);
					break;
			case 2: printf("Elemento a ser inserido: ");
					scanf("%d",&x);
					push(p, x);
					break;
			case 3: x = pop(p);
					printf("Elemento removido: %d\n",x);
					break;
			case 4: printf("Elemento a ser buscado: ");
					scanf("%d",&x);
					//busca(&pilha,x);
					break;
			case 5: libera(p);
					break; 
			case 6: imprime(p);
					break;
			} 
	}while(opcao !=0);
}


