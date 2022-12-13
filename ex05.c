#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void alocarVetor(float **, int);
void sortearVetor(float *, int);
void somarValoresDoVetor(float *, float *, int);
void imprimirVetor(float *, int);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("ERRO: Digite %s <tamanho do vetor>\n", argv[0]);
    exit(1);
  }

  float soma = 0;
  float *vetor = NULL;
  int tam = atoi(argv[1]);

  srand(time(NULL));

  alocarVetor(&vetor, tam);
  sortearVetor(vetor, tam);
  somarValoresDoVetor(&soma, vetor, tam);

  printf("Vetor sorteado:\n");
  imprimirVetor(vetor, tam);
  printf("A soma dos valores do vetor vale %.2f\n", soma);

  free(vetor);

  return 0;
}

void alocarVetor(float **pVetor, int tam)
{
  *pVetor = malloc(tam * sizeof(float));
  if (!*pVetor)
  {
    printf("ERRO: Memória insuficiente para alocação do vetor!\n");
    exit(2);
  }
}

void sortearVetor(float *vetor, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    *(vetor + i) = rand() / (float)RAND_MAX * MAX;
  }
}

void somarValoresDoVetor(float *soma, float *vetor, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    *soma += *(vetor + i);
  }
}

void imprimirVetor(float *vetor, int tam)
{
  printf("[");
  for (int i = 0; i < tam; i++)
  {
    printf(" %.1f ", *(vetor + i));
  }
  printf("]\n");
}