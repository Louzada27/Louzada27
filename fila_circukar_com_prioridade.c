- 👋 Hi, I’m @Louzada27
- 👀 I’m interested in ...
- 🌱 I’m currently learning ...
- 💞️ I’m looking to collaborate on ...
- 📫 How to reach me ...

<!---
Louzada27/Louzada27 is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->
#include <stdio.h>
#include <stdlib.h>

#define Tam 5
#define prioridade 60

typedef struct {
  int dados[Tam];
  int inicio;
  int fim;

} Fila;

void CreateEmptyQueue(Fila *f);
int isFull(Fila *f);
int isEmpty(Fila *f);
int enQueue(Fila *f, int valor);
int deQueue(Fila *f);
int printQueue(Fila *f);

int main(void) {
  Fila *F = (Fila *)malloc(sizeof(Fila));
  int valor, opc;
  CreateEmptyQueue(F);

  while (opc != 4) {
    printf("\n  Menu \n");
    printf("1-> inserir \n");
    printf("2-> desenfielrar\n");
    printf("3-> imprimir\n");
    printf("4-> sair\n");
    printf("-> ");
    scanf("%d", &opc);
    switch (opc) {
    case (1):
      printf("\nElemento-> ");
      scanf("%d", &valor);
      enQueue(F, valor);
      break;
    case (2):
      deQueue(F);
      break;
    case (3):
      printQueue(F);
      break;
    }
  }

  return 0;
}

void CreateEmptyQueue(Fila *f) {
  f->inicio = 0;
  f->fim = 0;

} // cria fila
int isFull(Fila *f) {
  return (f->fim+1)%Tam == f->inicio;
} // verifica se esta cheia
int isEmpty(Fila *f) {
  if ((f->inicio) == (f->fim)) {
    return 1;
  } else {
    return 0; //  vazia
  }

} // verifica se a fila esta vazia
int enQueue(Fila *f, int valor) { 
  if (!isFull(f)) {
   if(valor >= prioridade){
    f->fim = (f->fim%Tam)+1;
    int vetor[f->fim];   
    int ini = f->inicio;
    int cont = 0;
     
    for(int i = ini; i<Tam;i++){
      if(f->dados[i] >= prioridade){
        vetor[cont] = f->dados[i];
        cont++;
      }
    }
    if(ini!=0){
      for(int i = 0; i< ini; i++){
         if(f->dados[i] >= prioridade){
           vetor[cont] = f->dados[i];
           cont++;
      }
      }
    }  //pega os que tem prioridade na frente
  
    vetor[cont] = valor;
    cont++; //insere o novo
    
    for(int i = ini; i<Tam;i++){
      if(f->dados[i] < prioridade){
        vetor[cont] = f->dados[i];
        cont++;
      }
    }
    if(ini!=0){
      for(int i = 0; i< ini; i++){
         if(f->dados[i] < prioridade){
           vetor[cont] = f->dados[i];
           cont++;
      }
      }
    } //pega os que nao tem prioridade
    
    cont = 0;
    ini = f->inicio;
    
    for(int i = ini; i<Tam;i++){
        f->dados[i] = vetor[cont];
        vetor[cont] = 0;
        cont++;
    }
    if(ini!=0){
      for(int i = 0; i< ini; i++){
         f->dados[i] = vetor[cont];
         vetor[cont] = 0;
         cont++;
      }
     
    
    
    } //volta para o a fila e zera o vetor
    }
   else {
       f->dados[f->fim] = valor;
       f->fim = (f->fim+1)%Tam;
      
    }
  
  
   }
  else{
    printf("Pilah cheia");
  }
 
  
  return 0;
} // inserir item na fila
int deQueue(Fila *f) {
  if (isEmpty(f) == 0) {
    printf("\n elemento excluido");
    f->dados[f->inicio] = 0;
    f->inicio = (f->inicio+1)%Tam;
    
    return 0;
  }
  return 0;
} // retira item da fila
int printQueue(Fila *f) {
  int ini = f->inicio;
  for(int i = ini; i<Tam;i++){
    if(f->dados[i]<=0 || f->dados[i]>=120){
      break;
    }
    printf(" %d ",f->dados[i]);
  }
  if(ini!=0){
    for(int i = 0; i< ini; i++){
      if(f->dados[i]<=0 || f->dados[i]>=120){
          break;
    }
      printf(" %d ",f->dados[i]);
    }
  }
  return 0;
} // imprimir a fila




