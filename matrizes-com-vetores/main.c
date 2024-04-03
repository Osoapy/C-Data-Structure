#include <stdio.h>
int tamanho = 0, coluna = 3, linha = 3;

void DimensionaMatriz(int linha, int coluna) { 
  tamanho = linha * coluna; 
}

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
  int k = 0, tamanho = coluna * linha;
  while (k < tamanho) {
    vet3[k] = vet[k] + vet2[k];
    k++;
  }
}

int main() {
  /* CRIANDO O TAMANHO DA MATRIZ */
  DimensionaMatriz(linha,coluna);
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
  printf("Olhe o resultado da sua matriz somada com a ja formulada:\n");
  SomarMatriz(vet, vet2, vet3);
  ImprimeMatriz(vet3, linha, coluna);

  return 0;
}
