#include <stdio.h>
#include "matriz.h"
#define tamanho 9
#define coluna 3
#define linha 3

void ZerarMatriz(int vetor[tamanho]) {
  int k;
  for (k = 0; k < tamanho; k++) {
    vetor[k] = 0;
  }
  printf("\n");
}

int BuscarElemento(int vet[], int lin, int colun){
  lin--; colun--;
  return vet[colun + lin * coluna];
}

void ImprimeMatriz(int vet[tamanho], int lin, int colun) {
  int l, k;
  for (l = 1; l <= lin; l++) {
    for (k = 1; k <= colun; k++) {
      printf("%d ", BuscarElemento(vet, l, k));
    }
    printf("\n");
  }
  printf("\n");
}

void AdicionaElemento(int vetor[], int valor, int lin, int col) {
  vetor[(lin-1)*coluna+(col-1)] = valor;
}

void SomarMatriz(int vet[], int vet2[], int vet3[]) {
  int k = 0;
  while (k < tamanho) {
    vet3[k] = vet[k] + vet2[k];
    k++;
  }
}
