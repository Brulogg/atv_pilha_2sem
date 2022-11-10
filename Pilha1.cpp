//pilha com vetor
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Empilha (push)\n");
     printf("2. Retira (pop)\n");
     printf("3. Mostra a pilha\n");
     printf("4. Conta elementos\n"); //int contaElementos(Pilha *p)
     printf("5. Soma elementos\n");//float somaElementos(Pilha *q)
     printf("6. Topo da pilha\n");//float topo(Pilha *p)
     printf("7. Base da pilha\n");//void base(Pilha *p)
	 printf("9. Fim\n");
}
//conta elementos
int contaElementos (Pilha *p){
	int conta=0;
	Pilha *aux=pilha_cria();
	float v;
	//esvaziar a pilha original passando os dados para a pilha auxiliar para contar
	while(pilha_vazia(p)==0){//significa que a pilha não está vazia
	   v=pilha_pop(p);
	   conta++;//conta os elementos
	   pilha_push(aux,v);
	}
	//restaurar a pilha original passando os dados da auxilar para ela
	while(pilha_vazia(aux)==0){
		v=pilha_pop(aux);
		pilha_push(p,v);
	}
	pilha_libera(aux);
	return conta;
}
//soma elementos
float somaElementos (Pilha *q){
	float v,soma=0;
	Pilha *aux=pilha_cria();
	//esvaziar a pilha original passando os dados para a pilha auxiliar para somar
	while(pilha_vazia(q)==0){//significa que a pilha não está vazia
	   v=pilha_pop(q);
	   soma=soma+v;//soma os elementos
	   pilha_push(aux,v);
	}
	//restaurar a pilha original passando os dados da auxilar para ela
	while(pilha_vazia(aux)==0){
		v=pilha_pop(aux);
		pilha_push(q,v);
	}
	pilha_libera(aux);
	return soma;
}

float topo(Pilha *p){
	float tp;
	tp=pilha_pop(p);//tira para guardar o valor em tp
	pilha_push(p,tp);//recoloca na posiçao original
	return tp;
}
void base(Pilha *p){
    Pilha *p_aux;
    p_aux = pilha_cria();
    float basePilha=0, v;
    //esvaziando a pilha para verificar
    while (pilha_vazia(p)==0){ //enquanto a função da pilha_vazia retornar 0 significa que nao esta vazia, faça
        v = pilha_pop(p); //retirando o elemento da pilha principal
        pilha_push(p_aux,v); //colocando os elementos na pilha auxiliar
    }
    basePilha=v;
    // apos verificar os elementos temos que colocar os elementos da pilha auxiliar na pilha principal
    while(pilha_vazia(p_aux)==0){
        v = pilha_pop(p_aux);
        pilha_push(p,v);
        //pilha_push(p,pilha_pop(aux))
    }
    pilha_libera(p_aux); //liberando espaço na memória da pilha auxiliar
    printf("Base: %.0f\n",basePilha);
}



//--------------------------------------------------------
main(){
      Pilha *pi=pilha_cria();
      int opmenu;
      float item;
      do{
         menu();
         scanf("%d", &opmenu);
         switch (opmenu){
         case 1 : //insere
                printf("Digite o valor a ser empilhado: ");
                scanf("%f", &item);
                pilha_push(pi,item);
                break;
        case 2 : //retira
               if(pilha_vazia(pi))//verifica antes se está vazia
                   printf("Pilha vazia.\n");
               else
                   printf("Elemento retirado = %.0f\n",pilha_pop(pi));
               break;
        case 3 : //mostra
                pilha_mostra(pi);
                break;
        case 4: //conta elementos
                printf("Numero de elementos: %d\n",contaElementos(pi));
                break;
        case 5: //soma elementos
                printf("Soma dos elementos: %.0f\n",somaElementos(pi));
                break;
        case 6://mostra o topo
                printf("Topo: %.0f\n",topo(pi));
                break;
        case 7://mostra a base
                base(pi);
                break;
       }//switch
       printf("\n");
       system("pause");
       
     } while(opmenu!=9);
     pilha_libera(pi);
   }
