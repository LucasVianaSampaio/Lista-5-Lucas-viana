#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 100

void preenchevetor(int *, int);
void imprimirvetor(int *, int);
void menorvetor(int *, int);

int main(int argc, char **argv)
{

  if (argc != 2)
  {
    printf("Use:\n\n %s <qtdElementos>", argv[0]);
    exit(1);
  }

  int qtd = atoi(argv[1]);
  int vetor[qtd];

  preenchevetor(vetor, qtd);
  imprimirvetor(vetor, qtd);
  menorvetor(vetor, qtd);

  return 0;
}

void preenchevetor(int *p, int qtd)
{
  srand(time(NULL));
  for (int i = 0; i < qtd; i++)
  {
    *(p + i) = rand() % MX;
  }
}

void imprimirvetor(int *p, int qtd)
{
  for (int i = 0; i < qtd; i++)
  {
    printf("[%p]%d\n", (p + i), *(p + i));
  }
}

void menorvetor(int *p, int qtd)
{
  int menor = *p;
  for (int i = 1; i <= qtd; i++)
  {
    *(p + i) < menor ? menor = *(p + i) : menor;
  }
  printf("O menor número é: %d", menor);
}