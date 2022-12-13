#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocarMatriz(int **, int);
void sortearMatriz(int *, int, int);
void binarizarMatriz(int *, int *, int, int);
void imprimirMatriz(int *, int, int);

int main(int argc, char *argv[])
{
  if (argc != 5)
  {
    printf("ERRO: Digite %s <nº de linhas> <nº de colunas> <valor máximo para sortear> <limiar t>\n", argv[0]);
    exit(1);
  }

  int *m = NULL;
  int *s = NULL;
  int linhas = atoi(argv[1]);
  int colunas = atoi(argv[2]);
  int max = atoi(argv[3]);
  int t = atoi(argv[4]);

  srand(time(NULL));

  alocarMatriz(&m, linhas * colunas);
  alocarMatriz(&s, linhas * colunas);

  sortearMatriz(m, linhas * colunas, max);
  binarizarMatriz(s, m, linhas * colunas, t);

  printf("Matriz M:\n");
  imprimirMatriz(m, linhas, colunas);

  printf("Matriz S:\n");
  imprimirMatriz(s, linhas, colunas);

  free(m);
  free(s);

  return 0;
}

void alocarMatriz(int **pMatriz, int tam)
{
  *pMatriz = malloc(tam * sizeof(int));
  if (!*pMatriz)
  {
    printf("ERRO: Memória insuficiente para alocação do ponteiro!\n");
    exit(2);
  }
}

void sortearMatriz(int *matriz, int tam, int max)
{
  for (int i = 0; i < tam; i++)
  {
    *(matriz + i) = rand() % max;
  }
}

void binarizarMatriz(int *s, int *m, int tam, int t)
{
  for (int i = 0; i < tam; i++)
  {
    *(s + i) = (*(m + i) > t) ? 1 : 0;
  }
}

void imprimirMatriz(int *matriz, int linhas, int colunas)
{
  for (int i = 0; i < linhas * colunas; i++)
  {
    if (!(i % colunas))
    {
      printf("|");
    }
    printf(" %d ", *(matriz + i));
    if (!((i + 1) % colunas))
    {
      printf("|\n");
    }
  }
}