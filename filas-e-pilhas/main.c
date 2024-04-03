#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
  int num;
  struct Nodo *proximo;
} nodo;

/*  REINO DA PILHA  */

typedef struct Pilha {
  struct Nodo *topo;
} pilha;

pilha *pilha_Criar() {
  pilha *aux = (pilha *)malloc(sizeof(pilha));
  if (aux) {
    aux->topo = NULL;
    return aux;
  }
  return NULL;
}

int pilha_Esta_Vazia(pilha *minha_pilha) {
  if (minha_pilha->topo) {
    return 0;
  }
  return 1;
}

void pilha_Push(pilha *minha_pilha, int num) {
  if (!pilha_Esta_Vazia(minha_pilha)) {
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    if (aux) {
      aux->proximo = minha_pilha->topo;
      aux->num = num;
      minha_pilha->topo = aux;
    }
  } else {
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    if (aux) {
      aux->proximo = NULL;
      aux->num = num;
      minha_pilha->topo = aux;
    }
  }
}

void pilha_Pop(pilha *minha_pilha) {
  if (!pilha_Esta_Vazia(minha_pilha)) {
    nodo *aux = minha_pilha->topo;
    minha_pilha->topo = aux->proximo;
    free(aux);
  } else {
    printf("Pilha vazia.\n");
  }
}

void pilha_Print(pilha *minha_pilha) {
  nodo *aux = minha_pilha->topo;
  while (aux) {
    printf("%d ", aux->num);
    aux = aux->proximo;
  }
  printf("\n");
}

void pilha_Alterar_Topo(pilha *minha_pilha, int novo_num) {
  if (!pilha_Esta_Vazia(minha_pilha)) {
    minha_pilha->topo->num = novo_num;
  } else {
    printf("Pilha vazia.\n");
  }
}

int pilha_Esta_Cheia(pilha *minha_pilha, int maximo) {
  if (minha_pilha->topo) {
    nodo *aux = minha_pilha->topo;
    int k = 1;
    for (; aux->proximo != NULL && k < maximo; k++, aux = aux->proximo) {
    }
    if (k == maximo) {
      return 1;
    }
  }
  return 0;
}

/*  REINO DA FILA  */

typedef struct Fila {
  struct Nodo *comeco;
  struct Nodo *fim;
} fila;

fila *fila_Criar() {
  fila *aux = (fila *)malloc(sizeof(fila));
  if (aux) {
    aux->comeco = NULL;
    aux->fim = NULL;
    return aux;
  }
  return NULL;
}

int fila_Esta_Vazia(fila *minha_fila) {
  if (minha_fila->comeco) {
    return 0;
  }
  return 1;
}

void fila_Enfileirar(fila *minha_fila, int num) {
  if (!fila_Esta_Vazia(minha_fila)) {
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    if (aux) {
      aux->proximo = NULL;
      aux->num = num;
      minha_fila->fim->proximo = aux;
      minha_fila->fim = aux;
    }
  } else {
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    if (aux) {
      aux->proximo = NULL;
      aux->num = num;
      minha_fila->fim = aux;
      minha_fila->comeco = aux;
    }
  }
}

void fila_Desenfileirar(fila *minha_fila) {
  if (!fila_Esta_Vazia(minha_fila)) {
    nodo *aux = minha_fila->comeco;
    minha_fila->comeco = aux->proximo;
    free(aux);
  } else {
    printf("Fila vazia.\n");
  }
}

void fila_Print(fila *minha_fila) {
  nodo *aux = minha_fila->comeco;
  while (aux) {
    printf("%d ", aux->num);
    aux = aux->proximo;
  }
  printf("\n");
}

int fila_Esta_Cheia(fila *minha_fila, int maximo) {
  if (minha_fila->comeco) {
    nodo *aux = minha_fila->comeco;
    int k = 1;
    for (; aux->proximo != NULL && k < maximo; k++, aux = aux->proximo) {
    }
    if (k == maximo) {
      return 1;
    }
  }
  return 0;
}

void entre_Iguais(char string[200]) {
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("%s", string);
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}
      
int main() {
  int vontade = 0;

  printf("Olá Mundo!\n");
  entre_Iguais("Escolha sua vontade...\n");
  printf("[1] Pilha\n");
  printf("[2] Fila\n");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  scanf("%d", &vontade);

  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("\n\n\n\n\n\n\n");

  if (vontade == 1) {
    pilha *minha_pilha = pilha_Criar();
    int maximo;

    printf("Insira o valor maximo da sua pilha: ");
    scanf("%d", &maximo);

    for (; vontade != 4;) {
      int numero = 0;

      entre_Iguais("Escolha sua vontade...\n");
      printf("[1] Adicionar\n");
      printf("[2] Retirar\n");
      printf("[3] Imprimir\n");
      printf("[4] Sair\n");
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      scanf("%d", &vontade);

      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("\n\n\n\n\n\n\n");

      switch(vontade) {
        case 1: 
          printf("Insira o num para sua pilha: ");
          scanf("%d", &numero);
          if (!pilha_Esta_Cheia(minha_pilha, maximo)) {
            pilha_Push(minha_pilha, numero);
            entre_Iguais("Numero adicionado com sucesso!\n");
          }
          else {
            entre_Iguais("Espere a pilha diminuir primeiro :(((\n");
          }
          break;
        case 2:
          if (!pilha_Esta_Vazia(minha_pilha)) {
            pilha_Pop(minha_pilha);
            entre_Iguais("Numero removido com sucesso!\n");
          }
          else {
            entre_Iguais("Espere a pilha comecar primeiro :(((\n");
          }
          break;
        case 3:
          if (pilha_Esta_Vazia(minha_pilha)) {
            entre_Iguais("Espere a pilha comecar primeiro :(((\n");
          }
          else {
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            pilha_Print(minha_pilha);
            printf("O topo eh: %d\n", minha_pilha->topo->num);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          }
          break;
      }
    }
  }

  if (vontade == 2) {
    fila *minha_fila = fila_Criar();
    int maximo;

    printf("Insira o valor maximo da sua fila: ");
    scanf("%d", &maximo);

    for (; vontade != 4;) {
      int numero = 0;

      entre_Iguais("Escolha sua vontade:\n");;
      printf("[1] Adicionar\n");
      printf("[2] Retirar\n");
      printf("[3] Imprimir\n");
      printf("[4] Sair\n");
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      scanf("%d", &vontade);

      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("\n\n\n\n\n\n\n");

      switch(vontade) {
        case 1: 
          printf("Insira o num para sua fila: ");
          scanf("%d", &numero);
          if (!fila_Esta_Cheia(minha_fila, maximo)) {
            fila_Enfileirar(minha_fila, numero);
            entre_Iguais("Numero adicionado com sucesso!\n");
          }
          else {
            entre_Iguais("Espere a fila andar primeiro :(((\n");
          }
          break;
        case 2:
          if (!fila_Esta_Vazia(minha_fila)) {
            fila_Desenfileirar(minha_fila);
            entre_Iguais("Numero removido com sucesso!\n");
          }
          else {
            entre_Iguais("Espere a fila comecar primeiro :(((\n");
          }
          break;
        case 3:
          if (fila_Esta_Vazia(minha_fila)) {
            entre_Iguais("Espere a fila comecar primeiro :(((\n");
          }
          else {
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            fila_Print(minha_fila);
            printf("Inicia-se em: %d\n", minha_fila->comeco->num);
            printf("Finaliza-se em: %d\n", minha_fila->fim->num);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          }
          break;
      }
    }
  }

  return 0;
}
