#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void alocarVetorInt(int **, int);
void alocarVetorFloat(float **, int);
void sortearVetor(int *, int);
void procurarMaiorValor(int *, int *, int);
void procurarMenorValor(int *, int *, int);
void normalizarVetor(float *, int *, int, int, int);
void imprimirVetorInt(int *, int);
void imprimirVetorFloat(float *, int);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("ERRO: Digite %s <tamanho do vetor>\n", argv[0]);
    exit(1);
  }

  int *x = NULL;
  float *xNormalizado = NULL;
  int tam = atoi(argv[1]);
  int maior, menor;

  srand(time(NULL));

  alocarVetorInt(&x, tam);
  alocarVetorFloat(&xNormalizado, tam);

  sortearVetor(x, tam);
  procurarMaiorValor(&maior, x, tam);
  procurarMenorValor(&menor, x, tam);
  normalizarVetor(xNormalizado, x, tam, maior, menor);

  printf("\nVetor sorteado:\n");
  imprimirVetorInt(x, tam);

  printf("\nVetor normalizado:\n");
  imprimirVetorFloat(xNormalizado, tam);

  free(x);
  free(xNormalizado);

  return 0;
}

void alocarVetorInt(int **pVetor, int tam)
{
  *pVetor = malloc(tam * sizeof(int));
  if (!*pVetor)
  {
    printf("ERRO: Memória insuficiente para alocação do vetor inteiro!\n");
    exit(2);
  }
}

void alocarVetorFloat(float **pVetor, int tam)
{
  *pVetor = malloc(tam * sizeof(float));
  if (!*pVetor)
  {
    printf("ERRO: Memória insuficiente para alocação do vetor float!\n");
    exit(3);
  }
}

void sortearVetor(int *vetor, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    *(vetor + i) = rand() % MAX;
  }
}

void procurarMaiorValor(int *maior, int *vetor, int tam)
{
  *maior = *vetor;
  for (int i = 1; i < tam; i++)
  {
    *maior = (*(vetor + i) > *maior) ? *(vetor + i) : *maior;
  }
}

void procurarMenorValor(int *menor, int *vetor, int tam)
{
  *menor = *vetor;
  for (int i = 1; i < tam; i++)
  {
    *menor = (*(vetor + i) < *menor) ? *(vetor + i) : *menor;
  }
}

void normalizarVetor(float *xNormalizado, int *x, int tam, int maior, int menor)
{
  for (int i = 0; i < tam; i++)
  {
    *(xNormalizado + i) = (float)(*(x + i) - menor) / (maior - menor);
  }
}

void imprimirVetorInt(int *vetor, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("[%p] %d\n", (vetor + i), *(vetor + i));
  }
}

void imprimirVetorFloat(float *vetor, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("[%p] %.2f\n", (vetor + i), *(vetor + i));
  }
}