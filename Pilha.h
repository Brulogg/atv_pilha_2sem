#define N 50 
typedef struct pilha{
        int topo;//controla o ultimo da pilha
        float v[N];
        }Pilha;

Pilha *pilha_cria(){//retorna o endereço da pilha
      Pilha *p=(Pilha*)malloc(sizeof(Pilha));
      p->topo=-1;
      return p;
} 
int pilha_vazia(Pilha *p){
    if (p->topo==-1) return 1;//verdadeiro
    else  return 0;
}
void pilha_push(Pilha *p, float v) {
    if(p->topo==N-1){
      printf("Capacidade da pilha esgotada.\n");
      return; //volta para o programa
      }   //insere novo elemento
      p->topo++;//incrementa o valor de topo (dentro da pilha)
	  p->v[p->topo]=v;
      
} 
float pilha_pop(Pilha *p){
     float v;
//retira o elemento da pilha
     v=p->v[p->topo];  
     p->topo--;
     return v;
}
void pilha_libera(Pilha *p){
     free(p);
}      
void pilha_mostra(Pilha *p) {
     printf("Conteudo da pilha\n");
     for(int i=p->topo;i>=0;i--)
         printf("%.0f\n",p->v[i]);
     printf("\n");
} 

