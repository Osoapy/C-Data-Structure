#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_STRING 100

// ESTRUTURA QUE VAI SER AS COLUNAS DO MEU CSV
typedef struct CSVRow {
  char nome[TAMANHO_STRING];
  char cpf[TAMANHO_STRING];
  char cargo[TAMANHO_STRING];
  char estado_civil[TAMANHO_STRING];
  float salario;
} CSV_Colunas;

void preencherRegistro(CSV_Colunas dados[], int quantidade) {
  // INICIANDO VARIÁVEL
  int i = 0;
  // LIMPANDO O BUFFER DO TECLADO
  fflush(stdin);
  // USANDO O FOR PRA PREENCHER TODOS OS DADOS EM QUANTIDADE
  for(i = 0; i < quantidade; i++) {
    // RECEBENDO E PREENCHENDO OS CAMPOS
    printf("Ficha %d\n", i + 1);
    printf("Insira o nome: ");
    scanf("%s", dados[i].nome); fflush(stdin);
    printf("Insira o cpf: ");
    scanf("%s", dados[i].cpf); fflush(stdin);
    printf("Insira cargo: ");
    scanf("%s", dados[i].cargo); fflush(stdin);
    printf("Insira o estado civil: ");
    scanf("%s", dados[i].estado_civil); fflush(stdin);
    printf("Insira o salario: ");
    scanf("%f", &dados[i].salario); fflush(stdin);
  }
}

void lerCSV(const char *nomeArquivo) {
  // INICIANDO CONTADOR E STRING DE ESCAPE
  int i = 0; char tag_coluna[TAMANHO_STRING];
  // ABRE O ARQUIVO
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
    return;
  }
  // VARIAVEL DO TIPO CSV_COLUNAS QUE RECEBE AS RESPOSTAS DE CADA LINHA DO CSV
  CSV_Colunas linha;
  // "ENQUANTO TIVER VALORES PARA LER, LEIA-OS E PRINTE-OS"
  fscanf(arquivo, "%[^,],%[^,],%[^,],%[^,],%s\n", tag_coluna, tag_coluna, tag_coluna, tag_coluna, tag_coluna);
  for (i = 0; fscanf(arquivo, "%[^,],%[^,],%[^,],%[^,],%f\n", linha.nome, linha.cpf, linha.cargo, linha.estado_civil, &linha.salario) == 5; i++) {
    // PRINTANDO
    printf("\nLINHA %d\n\nCampo 1 (nome): %s;\nCampo 2 (cpf): %s;\nCampo 3 (cargo): %s;\nCampo 4 (estado civil): %s;\nCampo 5 (salario em R$): %.2f.\n", i + 1, linha.nome, linha.cpf, linha.cargo, linha.estado_civil, linha.salario);
  }
  // FECHANDO O ARQUIVO
  fclose(arquivo);
}

void escreverCSV(const char *nomeArquivo, CSV_Colunas dados[], int quantidade) {
  // ABRINDO O ARQUIVO
  FILE *arquivo = fopen(nomeArquivo, "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
    return;
  }
  // ESCREVENDO VÁRIAS LINHAS
  for (int i = 0; i < quantidade; i++) {
    // ESCREVENDO NO CSV
    fprintf(arquivo, "%s,%s,%s,%s,%f\n", dados[i].nome, dados[i].cpf, dados[i].cargo, dados[i].estado_civil, dados[i].salario);
  }  
  // FECHANDO O ARQUIVO
  fclose(arquivo);
}

  void removerCSV(const char *nomeArquivo, int quantidade) {
  int k = 0;
  // REPETINDO TOOODO O PROCESSO ATÉ CHEGAR NO FINAL DA QUANTIDADE A SER EXCLUIDA
  for(k = 0; k < quantidade; k++){
    // DESCOBRINDO QUAL LINHA APAGAR
    char nome_a_remover[TAMANHO_STRING];
    printf("Insira o nome a ser apagado da lista: ");
    scanf("%s", nome_a_remover);
    fflush(stdin);
    // ABRINDO O ARQUIVO ORIGINAL
    FILE *arquivoEntrada = fopen(nomeArquivo, "r");
    if (arquivoEntrada == NULL) {
      printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
      return;
    }
    // CRIANDO O ARQUIVO TEMPORÁRIO
    FILE *arquivoTemporario = fopen("temporario.csv", "w");
    if (arquivoTemporario == NULL) {
      printf("Erro ao criar o arquivo temporário.\n");
      fclose(arquivoEntrada);
      return;
    }
    // STRING DE ESCAPE
    char string_escape[TAMANHO_STRING];
    // VARIAVEL DO TIPO CSV_COLUNAS QUE RECEBE AS RESPOSTAS DE CADA LINHA DO CSV 
    CSV_Colunas linha;
    // CONTA-LINHAS PARA DESCOBRIR QUAL LINHA DEVE SER APAGADA
    int conta_linha = 0;
    // COLOCANDO O NOME DAS COLUNAS NO ARQUIVO TEMPORÁRIO
    fprintf(arquivoTemporario, "%s,%s,%s,%s,%s\n", "NOME", "CPF", "CARGO", "ESTADO_CIVIL", "SALARIO");
    // LENDO ATÉ ENCONTRAR O BANDIDO ENQUANTO ESCREVEMOS OS OUTROS NO ARQUIVO TEMPORÁRIO
    fscanf(arquivoEntrada, "%[^,],%[^,],%[^,],%[^,],%s\n", string_escape, string_escape, string_escape, string_escape, string_escape);
    while (fscanf(arquivoEntrada, "%[^,],%[^,],%[^,],%[^,],%f\n", linha.nome, linha.cpf, linha.cargo, linha.estado_civil, &linha.salario) == 5) {
      if (strcmp(nome_a_remover, linha.nome) != 0) {
        fprintf(arquivoTemporario, "%s,%s,%s,%s,%f\n", linha.nome, linha.cpf, linha.cargo, linha.estado_civil, linha.salario);
      }
      conta_linha++;

    }
    // FECHANDO OS ARQUIVOS
    fclose(arquivoEntrada);
    fclose(arquivoTemporario);
    // REMOVENDO O ORIGINAL
    remove(nomeArquivo);
    // RENOMEANDO O TEMPORÁRIO PARA O ORIGINAL
    rename("temporario.csv", nomeArquivo);
  }
}

int main() {
  int quantidade_criar = 0, quantidade_remover = 0;
  // RECEBENDO A QUANTIDADE A SER ADICIONADA
  printf("Insira a quantidade de fichas a serem acrescentadas: ");
  scanf("%d", &quantidade_criar);

  // CRIANDO / PREENCHENDO OS REGISTROS
  CSV_Colunas dados[quantidade_criar];
  preencherRegistro(dados, quantidade_criar);

  // RECEBENDO A QUANTIDADE A SER REMOVIDA DO CSV
  printf("Insira a quantidade de fichas a serem removidas: ");
  scanf("%d", &quantidade_remover);

  // REMOVENDO ALGUMAS LINHAS DADO O INPUT DO USUÁRIO
  removerCSV("exemplo.csv", quantidade_remover);

  // ESCREVENDO NO ARQUIVO CSV
  escreverCSV("exemplo.csv", dados, quantidade_criar);

  // LENDO O ARQUIVO CSV
  lerCSV("exemplo.csv");

  return 0;
}
