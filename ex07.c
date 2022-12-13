#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void alocarVetor(int **, int);
void sortearVetor(int *, int, int);
void calcularEQM(float *, int *, int *, int);
void imprimirVetor(int *, int);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("ERRO: Digite %s <tamanho do vetor> <valor máximo para sortear>\n", argv[0]);
    exit(1);
  }

  int *a = NULL;
  int *b = NULL;
  float eqm;
  int tam = atoi(argv[1]);
  int max = atoi(argv[2]);

  srand(time(NULL));

  alocarVetor(&a, tam);
  alocarVetor(&b, tam);

  sortearVetor(a, tam, max);
  sortearVetor(b, tam, max);
  calcularEQM(&eqm, a, b, tam);

  printf("Vetor A:\n");
  imprimirVetor(a, tam);
  printf("Vetor B:\n");
  imprimirVetor(b, tam);
  printf("Erro Quadrático Médio: %.2f\n", eqm);

  free(a);
  free(b);

  return 0;
}

void alocarVetor(int **pVetor, int tam)
{
  *pVetor = malloc(tam * sizeof(int));
  if (!*pVetor)
  {
    printf("ERRO: Memória insuficiente para alocação do vetor!\n");
    exit(2);
  }
}

void sortearVetor(int *vetor, int tam, int max)
{
  for (int i = 0; i < tam; i++)
  {
    *(vetor + i) = rand() % max;
  }
}

void calcularEQM(float *eqm, int *a, int *b, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    *eqm += pow((*(a + i) - *(b + i)), 2);
  }
  *eqm /= tam;
}

void imprimirVetor(int *ptr, int tam)
{
  printf("[");
  for (int i = 0; i < tam; i++)
  {
    printf(" %d ", *(ptr + i));
  }
  printf("]\n");
