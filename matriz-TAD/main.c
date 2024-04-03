#include <stdio.h>
#include "matriz.h"

int main() {
  /* CRIANDO O TAMANHO DA MATRIZ */
  int vet[tamanho], vet2[tamanho], vet3[tamanho];

  /* TIRANDO O "LIXO" */
  ZerarMatriz(vet);
  ZerarMatriz(vet2);

  /* IMPRIMINDO MATRIZ ZERADA */
  printf("Imprimindo a matriz zerada...\n");
  ImprimeMatriz(vet, linha, coluna);

  /* ADICIONANDO ELEMENTOS NA PRIMEIRA MATRIZ */
  AdicionaElemento(vet, 10, 1, 1);
  AdicionaElemento(vet, 15, 2, 2);
  AdicionaElemento(vet, 20, 3, 3);

  /* IMPRIMINDO MATRIZ */
  printf("Imprimindo a matriz 1...\n");
  ImprimeMatriz(vet, linha, coluna);

  /* ADICIONANDO ELEMENTOS NA SEGUNDA MATRIZ */
  AdicionaElemento(vet2, 1, 1, 1);
  AdicionaElemento(vet2, 1, 1, 2);
  AdicionaElemento(vet2, 1, 1, 3);
  AdicionaElemento(vet2, 2, 2, 1);
  AdicionaElemento(vet2, 2, 2, 2);
  AdicionaElemento(vet2, 2, 2, 3);
  AdicionaElemento(vet2, 3, 3, 1);
  AdicionaElemento(vet2, 3, 3, 2);
  AdicionaElemento(vet2, 3, 3, 1);
  AdicionaElemento(vet2, 3, 3, 3);

  /* IMPRIMINDO MATRIZ */
  printf("Imprimindo a matriz 2...\n");
  ImprimeMatriz(vet2, linha, coluna);

  /* SOMANDO AS DUAS MATRIZES */
  printf("Olhe o resultado da sua matriz somada com uma já formulada:\n");
  SomarMatriz(vet, vet2, vet3);
  ImprimeMatriz(vet3, linha, coluna);

  return 0;
}