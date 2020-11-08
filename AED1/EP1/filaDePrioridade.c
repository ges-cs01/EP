/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   <2020204> - Prof. Luciano Antonio Digiampietri                **/
/**                                                                 **/
/**   EP1 - Fila de Prioridade                                      **/
/**                                                                 **/
/**   <Guilherme Elui de Souza>                   <        >        **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"

PFILA criarFila(int max){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->maxElementos = max;
  res->arranjo = (PONT*) malloc(sizeof(PONT)*max);
  int i;
  for (i=0;i<max;i++) res->arranjo[i] = NULL;
  PONT cabeca = (PONT) malloc(sizeof(ELEMENTO));
  res->fila = cabeca;
  cabeca->ant = cabeca;
  cabeca->prox = cabeca;
  cabeca->id = -1;
  cabeca->prioridade = 1000000;
  return res;
}

void exibirLog(PFILA f){
  printf("Log [elementos: %i (alem do no cabeca)]\n", tamanho(f));
  PONT atual = f->fila;
  printf("%p[%i;%f;%p]%p ", atual->ant, atual->id, atual->prioridade, atual, atual->prox);
  atual = atual->prox;
  while (atual != f->fila){
    printf("%p[%i;%f;%p]%p ", atual->ant, atual->id, atual->prioridade, atual, atual->prox);
    atual = atual->prox;
  }
  printf("\nElementos validos: ");
  atual = atual->prox;
  while (atual != f->fila){
    printf("[%i;%f;%p] ", atual->id, atual->prioridade, atual);
    atual = atual->prox;
  }

  printf("\nValores do arrajo:\n \[ ");
  int x;
  for (x=0;x<f->maxElementos;x++) printf("%p ",f->arranjo[x]);
  printf("]\n\n");
}

/* recebe como argumento uma fila f do tipo PFILA.
 *      
 *      return:
 *          int que corresponde ao numero de elementos validos da fila. */
int tamanho(PFILA f){
  int tam = 0;
  PONT end = f->fila->prox;
  while (end != f->fila) {
      tam++;
      end = end->prox;
  }
  
  return tam;
}

/* inserirElemento recebe como argumentos uma fila f do tipo PFILA, uma id
 * do tipo inteiro e uma prioridade do tipo float.
 *      return: 
 *          - false caso o elemento nao seja inserido
 *          - true caso a insercao ocorra. */
bool inserirElemento(PFILA f, int id, float prioridade){
  bool resposta = false;
  PONT novo;

  //teste id valido
  if (id < 0 || id >= f->maxElementos) {
      return false;
  }

  //teste posicao vazia
  if(f->arranjo[id] != NULL) {
      return false;
  }

  //alocacao de memoria para o novo elemento
  novo = (PONT) malloc(sizeof(ELEMENTO));
  
  //atribuicao dos valores passados por parametro
  novo->id = id;
  novo->prioridade = prioridade;
  f->arranjo[id] = novo;
  
  //insercao logo antes do no cabeca (menor prioridade do que todos os outros elementos restantes).
  if (novo->prioridade < f->fila->ant->prioridade) {
      novo->prox = f->fila;
      novo->ant = f->fila->ant;
      f->fila->ant = novo;
      novo->ant->prox = novo;
      return true;
  }

  //insercao logo apos o no cabeca(maior prioridade do que todos os outros elementos restantes).
  else if (novo->prioridade > f->fila->prox->prioridade) {
      novo->ant = f->fila;
      novo->prox = f->fila->prox;
      f->fila->prox = novo;
      novo->prox->ant = novo;
      return true;
  }

  //insercao em outra posicao qualquer.
  else {
    PONT atual = f->fila;
    atual = atual->prox;
        while (atual != f->fila){
            if (atual->prioridade < novo->prioridade) {
                novo->prox = atual; 
                novo->ant = atual->ant;
                atual->ant->prox = novo;
                atual->ant = novo;
            }
            atual = atual->prox;
        }
    return true;
  }
  
  return resposta;
}

/* aumentarPrioridade recebe como argumentos uma fila do tipo PFILA,
 * um id do tipo int, uma novaPrioridade do tipo float e aumenta a
 * prioridade do elemento desejado, de modo a reposiciona-lo na fila.
 *      return: 
 *          - false caso nao seja possivel reduzir a prioridade
 *          do elemento.
 *          - true caso a operacao ocorra. */
bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  bool resposta = false;
  
  //testes 
  if (id < 0 || id >= f->maxElementos) {return false;}

  else if(f->arranjo[id] == NULL) {return false;}

  //teste novaPrioridade deve ser maior do que a atual.
  else if(f->arranjo[id]->prioridade >= novaPrioridade) {return false;}

  else {
      //atribuicao novaPrioridade
      f->arranjo[id]->prioridade = novaPrioridade;
      PONT atual = f->arranjo[id];
      
      while (atual != f->fila) {
          if (f->arranjo[id]->prioridade > f->arranjo[id]->ant->prioridade) {
              //correcao dos ponteiros.
              f->arranjo[id]->ant->ant->prox = f->arranjo[id];
              f->arranjo[id]->prox->ant = f->arranjo[id]->ant;

              f->arranjo[id]->ant->prox = f->arranjo[id]->prox;
              f->arranjo[id]->ant = f->arranjo[id]->ant->ant;
              
              f->arranjo[id]->prox = f->arranjo[id]->prox->ant;
              f->arranjo[id]->prox->ant = f->arranjo[id];
            }

          atual = atual->ant;
      }
      return true;
  }

  return resposta;
}


/* reduzirPrioridade recebe como argumentos uma fila do tipo PFILA,
 * um id do tipo int, uma novaPrioridade do tipo float e diminui a
 * prioridade do elemento desejado, de modo a reposiciona-lo na fila.
 *      return:
 *          - false caso nao seja possivel reduzir a prioridade
 *            do elemento.
 *          - true caso a operacao ocorra. */
bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  bool resposta = false;

  //testes.
  if (id < 0 || id >= f->maxElementos) {return false;}
  
  else if(f->arranjo[id] == NULL) {return false;}
  
  //novaPrioridade deve ser menor do que a atual.
  else if(f->arranjo[id]->prioridade <= novaPrioridade) {return false;}

  else {

      f->arranjo[id]->prioridade = novaPrioridade;
      PONT atual = f->arranjo[id];

      while (atual != f->fila) {
          if (f->arranjo[id]->prioridade < f->arranjo[id]->prox->prioridade) {
              //correcao do ponteiros.
              f->arranjo[id]->prox->prox->ant = f->arranjo[id];
              f->arranjo[id]->ant->prox = f->arranjo[id]->prox;
              f->arranjo[id]->prox->ant = f->arranjo[id]->ant;
              f->arranjo[id]->prox = f->arranjo[id]->prox->prox;
              f->arranjo[id]->ant = f->arranjo[id]->ant->prox;
              f->arranjo[id]->ant->prox = f->arranjo[id];
            }
          atual = atual->prox;
      }
      return true;
  }
  return resposta;
}

/* removerElemento recebe uma fila f do tipo PFILA
 * e exclui o primeiro elemento valido dela.
 *      return:
 *          endereco do elemento retirado da fila.*/
PONT removerElemento(PFILA f){
  PONT resposta = NULL;
  
  //teste fila vazia.
  if(f->fila == f->fila->prox) {return NULL;}
  
  resposta = f->fila->prox;
  f->fila->prox = resposta->prox;
  resposta->prox->ant = f->fila;
  f->arranjo[resposta->id] = NULL;

  return resposta;
}

/* consultarPrioridade recebe como argumentos uma fila f do tipo PFILA,
 * uma id do tipo int, uma resposta do tipo ponteiro para float armazena
 * na memoria apontada pela variavel resposta o valor da prioridade consultada.
 *      return:
 *          - false caso id invalido ou elemento inexistente.
 *          - caso contrario armazena na memoria apontada pela variavel resposta 
 *            o valor da prioridade consultada e retorna true */
bool consultarPrioridade(PFILA f, int id, float* resposta){
  bool resp = false;
  
  //teste id valido
  if (id < 0 || id >= f->maxElementos) {
      return false;}
  
  //teste posicao vazia
  else if (f->arranjo[id] == NULL) {return false;}

  else {
      *resposta = f->arranjo[id]->prioridade;
      return true;
  }
  
  return resp;
}
