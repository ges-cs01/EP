/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   <   >                   <  >                                  **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"

#define LCHILD(x) 2*x+1
#define RCHILD(x) 2*x+2
#define PARENT(x) (x-1)/2

PFILA criarFila(int max){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->maxElementos = max;
  res->arranjo = (PONT*) malloc(sizeof(PONT)*max);
  res->heap = (PONT*) malloc(sizeof(PONT)*max);
  int i;
  for (i=0;i<max;i++) {
    res->arranjo[i] = NULL;
    res->heap[i] = NULL;
  }
  res->elementosNoHeap = 0;
  return res;
}

void exibirLog(PFILA f){
  printf("Log [elementos: %i]\n", f->elementosNoHeap);
  PONT atual;
  int i;
  for (i=0;i<f->elementosNoHeap;i++){
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}

int tamanho(PFILA f){
  int tam = 0;
  for(int i = 0; i < f->elementosNoHeap; i++)
    if(f->heap[i] != NULL) tam++;
  return tam;
}


void swap(PONT *n1, PONT *n2) {
    PONT temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}

/* heapify garante que as propriedades do heap max sejam mantidas apos remocao de um elemento. */
void heapify(PFILA f, int i) {
    int largest = (LCHILD(i) < f->elementosNoHeap && f->heap[LCHILD(i)]->prioridade > f->heap[i]->prioridade) ? LCHILD(i) : i;
    if(RCHILD(i) < f->elementosNoHeap && f->heap[RCHILD(i)]->prioridade > f->heap[largest]->prioridade) {
        largest = RCHILD(i);
    }
    if(largest != i) {
        swap(&(f->heap[i]), &(f->heap[largest])) ;
        heapify(f, largest) ;
    }
}

/* inserirElemento recebe como argumentos, um endereço para uma fila f,
 * um identificador id do tipo inteiro e uma prioridade do tipo float.
 *      retorno: 
 *          false caso o identificador do elemento seja invalido.
 *          true caso o elemento seja inserido corretamente. */
bool inserirElemento(PFILA f, int id, float prioridade){
    if(id < 0 || id >= f->maxElementos) return false;
    if(f->arranjo[id] != NULL) return false;
    
    PONT novo = malloc(sizeof(ELEMENTO));
    novo->id = id;
    novo->prioridade = prioridade;
    novo->posicao = f->elementosNoHeap;  
    f->arranjo[id] = novo;
    f->heap[f->elementosNoHeap] = novo;
    int i = (f->elementosNoHeap)++;
    while (i && novo->prioridade > f->heap[PARENT(i)]->prioridade) {
        f->heap[i] = f->heap[PARENT(i)];
        i = PARENT(i);
    }
    f->heap[i] = novo;

    for (int j = 0; j < f->elementosNoHeap; j++) {
        f->heap[j]->posicao = j;
    }
    return true;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
    if(id < 0 || id >= f->maxElementos) return false;
    if(f->arranjo[id] == NULL) return false;
    if(f->arranjo[id]->prioridade >= novaPrioridade) return false; 


    f->arranjo[id]->prioridade = novaPrioridade;
    int i = f->arranjo[id]->posicao; 

    
    while(i && f->heap[PARENT(i)]->prioridade < f->heap[i]->prioridade) {
        PONT temp = f->heap[i];
        f->heap[i] = f->heap[PARENT(i)];
        f->heap[PARENT(i)] = temp;
        i = PARENT(i);
    }

    for (int j = 0; j < f->elementosNoHeap; j++) {
        f->heap[j]->posicao = j;
    }
    return true;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
    if(id < 0 || id >= f->maxElementos) return false;
    if(f->arranjo[id] == NULL) return false;
    if(f->arranjo[id]->prioridade <= novaPrioridade) return false; 

    f->arranjo[id]->prioridade = novaPrioridade;
    int i = f->arranjo[id]->posicao; 

    while(i && f->heap[PARENT(i)]->prioridade > f->heap[i]->prioridade) {
        PONT temp = f->heap[i];
        f->heap[i] = f->heap[PARENT(i)];
        f->heap[PARENT(i)] = temp;
        i = PARENT(i);
    }
    heapify(f,0);

    for (int j = 0; j < f->elementosNoHeap; j++) {
        f->heap[j]->posicao = j;
    }
    return true;
}

PONT removerElemento(PFILA f){
    if(f->elementosNoHeap == 0) return NULL;
    PONT ret = f->heap[0];
    f->arranjo[f->heap[0]->id] = NULL;

    f->heap[0] = f->heap[f->elementosNoHeap-1];
    int i = (f->elementosNoHeap)--;

    heapify(f, 0);

    for (int j = 0; j < f->elementosNoHeap; j++) {
        f->heap[j]->posicao = j;
    }
    return ret;
}

/* consultarPrioridade recebe como argumentos um endereço para uma fila f,
 * um identificador id do tipo int, e uma resposta do tipo ponteiro para float.
 * */
bool consultarPrioridade(PFILA f, int id, float* resposta){
  if(id < 0) return false;
  if(id >= f->maxElementos) return false;
  if(f->arranjo[id] == NULL) return false;
  *resposta = f->arranjo[id]->prioridade;    
  return true;
}

