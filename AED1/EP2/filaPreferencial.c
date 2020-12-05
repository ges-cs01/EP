/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Seugndo Semestre de 2020                           **/
/**   <04   > - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP2 - Fila Preferencial                                       **/
/**                                                                 **/
/**   <Guilherme Elui de Souza>                   <11796152>        **/
/**                                                                 **/
/*********************************************************************/

#include "filapreferencial.h"

PFILA criarFila(){
  PFILA res = (PFILA) malloc(sizeof(FILAPREFERENCIAL));
  res->inicioPref = NULL;
  res->fimPref = NULL;
  res->inicioGeral = NULL;
  res->fimGeral = NULL;
  return res;
}

int tamanho(PFILA f){
  PONT atual = f->inicioGeral;
  int tam = 0;
  while (atual) {
    atual = atual->prox;
    tam++;
  }
  return tam;
}

int tamanhoFilaPreferencial(PFILA f){
  PONT atual = f->inicioPref;
  int tam = 0;
  while (atual) {
    atual = atual->prox;
    tam++;
  }
  return tam;
}

PONT buscarID(PFILA f, int id){
  PONT atual = f->inicioGeral;
   while (atual) {
    if (atual->id == id) return atual;
    atual = atual->prox;
  }
  return NULL;
}

void exibirLog(PFILA f){
  int numElementos = tamanho(f);
  printf("\nLog fila geral [elementos: %i] - Inicio:", numElementos);
  PONT atual = f->inicioGeral;
  while (atual){
    printf(" [%i;%i]", atual->id, atual->ehPreferencial);
    atual = atual->prox;
  }
  printf("\n");
  numElementos = tamanhoFilaPreferencial(f);
  printf("\nLog fila preferencial [elementos: %i] - Inicio:", numElementos);
  atual = f->inicioPref;
  while (atual){
    printf(" [%i;%i]", atual->id, atual->ehPreferencial);
    atual = atual->prox;
  }
  printf("\n\n");
}

PONT buscaSeqExcGeral(PFILA f, int id, PONT* ant){
  *ant = NULL;
  PONT atual = f->inicioGeral;
  while (atual != NULL && atual->id != id){
    *ant = atual;
    atual = atual->prox;
  }
  if ((atual != NULL) && (atual->id == id)) return atual;
  return NULL;
}

PONT buscaSeqExcPref(PFILA f, int id, PONT* ant){
  *ant = NULL;
  PONT atual = f->inicioPref;
  while (atual != NULL && atual->id != id){
    *ant = atual;
    atual = atual->prox;
  }
  if ((atual != NULL) && (atual->id == id)) return atual;
  return NULL;
}

/* inserirPessoaNaFila
 *
 * return:
 *      - false: caso não seja possivel inserir pessoa na fila
 *               id invalido ou ja existente
 *      - true:  caso seja possivel inserir pessoa na fila */
bool inserirPessoaNaFila(PFILA f, int id, int ehPreferencial){
    //testa id valido e se eh existe
    if(id < 0 || buscarID(f, id) != NULL) {
        return false;
    }

    //atribuicoes.
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->id = id;
    novo->ehPreferencial = ehPreferencial;

    //filaGeral nao vazia.
    if(f->inicioGeral != NULL) {
        f->fimGeral->prox = novo;
        f->fimGeral = novo;
        novo->prox = NULL;
    }

    //filaGeral vazia.
    if(f->inicioGeral == NULL) {
        f->inicioGeral = novo;
        f->fimGeral = novo;
        novo->prox = NULL;
    }

  //pessoa com direito a atendimento pref.
  if(ehPreferencial == true) {
      PONT novoPref = (PONT) malloc(sizeof(ELEMENTO));
      novoPref->id = id;
      novoPref->ehPreferencial = ehPreferencial;
      
      //filaPref nao vazia.
      if(f->inicioPref != NULL) {
          f->fimPref->prox = novoPref;
          f->fimPref = novoPref;
          novoPref->prox = NULL;
      }

      //filaPref vazia.
      if(f->inicioPref == NULL) {
          f->inicioPref = novoPref;
          f->fimPref = novoPref;
          novoPref->prox = NULL;
      }
  }
  return true;
}

/* atenderPrimeiraDaFilaPreferencial 
 *
 *  return:
 *      - false: caso id invalido, fila vazia, id nao existe.
 *      - true:  caso a pessoa seja atendida. */
bool atenderPrimeiraDaFilaPreferencial(PFILA f, int* id){
  //teste fila geral vazia e id valido
  if(f->inicioGeral == NULL || id < 0 || buscarID(f, *id) != NULL) {
      return false;
  }

  else {
      if(f->inicioPref != NULL) {
          *id = f->inicioPref->id;
          
          //remove da filaPref.
          PONT removerPref = f->inicioPref;
          f->inicioPref = f->inicioPref->prox;
          free(removerPref);
          //caso filaPref fique vazia.
          if(f->inicioPref == NULL) {
              f->fimPref = NULL;
          }

          //remove da filaGeral.
          PONT anterior = NULL;
          PONT atual = f->inicioGeral;

          //caso seja a 1a pessoa.
          if (atual != NULL && atual->id == *id) {
              f->inicioGeral = f->inicioGeral->prox;
              free(atual);
              if(f->inicioGeral == NULL) {
                  f->fimGeral = NULL;
              }
              return true;
          }

          //do contrario busca pela id. mantem info sobre o no anterior.
          while(atual != NULL && atual->id != *id){
              anterior = atual;
              atual = atual->prox;
          }
          
          anterior->prox = atual->prox;
          free(atual);
          return true;
      }

      //filaPref vazia => deve-se deletar a primeira da filaGeral.
      if(f->inicioPref == NULL && f->inicioGeral != NULL) {
          *id = f->inicioGeral->id;
          PONT removeGeral = f->inicioGeral;
          f->inicioGeral = f->inicioGeral->prox;
          free(removeGeral);
          if(f->inicioGeral == NULL) {
              f->fimGeral = NULL;
          }
          return true;
      }
  }
}

/* atenderPrimeiraDaFilaGeral 
 *
 *  return:
 *      - false: caso id invalido, fila vazia, id nao existe.
 *      - true:  caso a pessoa seja atendida. */
bool atenderPrimeiraDaFilaGeral(PFILA f, int* id){
  //teste fila geral vazia e id valido
  if(f->inicioGeral == NULL || id < 0 || buscarID(f, *id) != NULL) {
      return false;
  }

  else {
      //obs.: caso seja preferencial a pessoa eh a primeira da filaPref.
      if(f->inicioGeral->ehPreferencial == true) {
          *id = f->inicioGeral->id;

          //remove da filaGeral.
          PONT removeGeral = f->inicioGeral;
          f->inicioGeral = f->inicioGeral->prox;
          free(removeGeral);
          if(f->inicioGeral == NULL) {
              f->fimGeral = NULL;
          }

          //remove da filaPref.
          PONT removePref = f->inicioGeral;
          f->inicioPref = f->inicioGeral->prox;
          free(removePref);
          if(f->inicioPref == NULL) {
              f->fimPref = NULL;
          }
          
          return true;
      }

      //pessoa nao preferencial.
      if(f->inicioGeral->ehPreferencial == false) {
          *id = f->inicioGeral->id;
          //remove da filaGeral
          PONT removeGeral = f->inicioGeral;
          f->inicioGeral = f->inicioGeral->prox;
          free(removeGeral);
          //caso fique vazia;
          if (f->inicioGeral == NULL) {
              f->fimGeral = NULL;
          }

          return true;
      }
  }
}

/* desistirDaFila
 * 
 * return:
 *      - false: caso nao seja encontrado o ID
 *      - true: caso o elemento seja excluido*/
bool desistirDaFila(PFILA f, int id){

    //exclui primeira pessoa da filaGeral se ela nao for pref.
    if(f->inicioGeral->id == id && f->inicioGeral->ehPreferencial == false) {
        PONT temp = f->inicioGeral;
        f->inicioGeral = f->inicioGeral->prox;
        free(temp);
        if(f->inicioGeral == NULL) {
            f->fimGeral = NULL;
        }
        return true;
    }


    //removeGeral
    PONT antGeral, iGeral;
    iGeral = buscaSeqExcGeral(f, id, &antGeral);
    if(iGeral == NULL) {
        return false;
    }
    //eh o primeiro elemento da lista
    if(antGeral == NULL) {
        f->inicioGeral = iGeral->prox;
    }
    else {
        antGeral->prox = iGeral->prox;
    }
    free(iGeral);

    //removePref
    PONT antPref, iPref;
    iPref = buscaSeqExcPref(f,id,&antPref);
    if(iPref == NULL) {
        return false;
    }
    //eh o primeiro elemento da lista
    if(antPref == NULL) {
        f->inicioPref = iPref->prox;
    }
    else {
        antPref->prox = iPref->prox;
    }
    free(iPref);
    

    if(f->inicioGeral == NULL) {
        f->fimGeral = NULL;
    }
    
    if(f->inicioPref == NULL) {
        f->fimPref = NULL;
    }
        
    return true;
}
