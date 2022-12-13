#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocarMatriz(int **, int);
void sortearMatriz(int *, int, int);
void somarDiagonalPrincipal(int *, int *, int);
void parOuImpar(char **, int);
void imprimirMatriz(int *, int);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("ERRO: Digite %s <tamanho da matriz> <valor máximo para sortear>\n", argv[0]);
    exit(1);
  }

  int *m = NULL;
  char *resultado = NULL;
  int n = atoi(argv[1]);
  int max = atoi(argv[2]);
  int soma = 0;

  srand(time(NULL));

  alocarMatriz(&m, n * n);
  sortearMatriz(m, n * n, max);
  somarDiagonalPrincipal(&soma, m, n);
  parOuImpar(&resultado, soma);

  printf("Matriz sorteada:\n");
  imprimirMatriz(m, n);
  printf("A soma da diagonal principal vale %d (%s)\n", soma, resultado);

  free(m);

  return 0;
}

void alocarMatriz(int **pMatriz, int tam)
{
  *pMatriz = malloc(tam * sizeof(int));
  if (!(*pMatriz))
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

void somarDiagonalPrincipal(int *soma, int *matriz, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    *soma += *(matriz + i + tam * i);
  }
}

void parOuImpar(char **resultado, int soma)
{
  *resultado = (soma % 2) ? "Ímpar" : "Par";
}

void imprimirMatriz(int *matriz, int tam)
{
  for (int i = 0; i < tam * tam; i++)
  {
    if (!(i % tam))
    {
      printf("|");
    }
    printf(" %d ", *(matriz + i));
    if (!((i + 1) % tam))
    {
      printf("|\n");
    }
  }
}