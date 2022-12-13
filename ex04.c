#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define MX 100

void preenche_vetor(int *);
void imprime_vetor(int *);
void menor_maior(int *);

int main()
{

  int x[TAM];
  preenche_vetor(x);
  imprime_vetor(x);
  menor_maior(x);

  return 0;
}

void preenche_vetor(int *px)
{
  srand(time(NULL));
  for (int i = 0; i < TAM; i++)
  {
    *(px + i) = rand() % MX;
  }
}

void imprime_vetor(int *px)
{
  for (int i = 0; i < TAM; i++)
  {
    printf("%d\n", *(px + i));
  }
}

void menor_maior(int *px)
{
  int menor = *px;
  int maior = *px;
  for (int i = 1; i <= TAM; i++)
  {
    *(px + i) < menor ? menor = *(px + i) : menor;
  }
  for (int i = 1; i <= TAM; i++)
  {
    *(px + i) > maior ? maior = *(px + i) : maior;
  }
  printf("O menor número é: %d\n", menor);
  printf("O maior número é: %d", maior);
}