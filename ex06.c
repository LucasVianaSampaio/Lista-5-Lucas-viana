#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocar(int **, int);
void sortear(int *, int, int);
void ordenar(int *, int);
void calc_media(float *, int *, int);
void calc_mediana(float *, int *, int);
void ocorrencia(int *, int *, int);
void maior_ocorrencia(int *, int *, int);
void contarTamanhoModa(int *, int *, int, int);
void preencherModa(int *, int *, int, int, int);
void imprimirVetor(int *, int);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Digite:\n\t %s <TamanhoDoVetor> <ValorMáximoparaSorteio>\n", argv[0]);
    exit(1);
  }

  float media, mediana;
  int *moda = NULL;
  int *contagem = NULL;
  int *vetor = NULL;
  int tamVetor = atoi(argv[1]);
  int max = atoi(argv[2]);
  int tamModa = 0;
  int maiorCont;

  srand(time(NULL));

  alocar(&vetor, tamVetor);
  alocar(&contagem, max);
  sortear(vetor, tamVetor, max);
  ordenar(vetor, tamVetor);
  calc_media(&media, vetor, tamVetor);
  calc_mediana(&mediana, vetor, tamVetor);
  ocorrencia(contagem, vetor, tamVetor);
  maior_ocorrencia(&maiorCont, contagem, max);
  contarTamanhoModa(&tamModa, contagem, max, maiorCont);
  alocar(&moda, tamModa);
  preencherModa(contagem, moda, max, tamModa, maiorCont);

  printf("\nVetor sorteado:\n");
  imprimirVetor(vetor, tamVetor);

  printf("\n=======RESULTADOS=========\n");
  printf("Média = %.2f\n", media);
  printf("Mediana = %.2f\n", mediana);
  printf("Moda = ");
  imprimirVetor(moda, tamModa);

  free(vetor);
  free(moda);
  free(contagem);

  return 0;
}

void alocar(int **pVetor, int tam)
{
  *pVetor = calloc(tam, sizeof(int));
  if (!*pVetor)
  {
    printf("ERRO: Memória insuficiente para alocação do ponteiro!\n");
    exit(2);
  }
}

void sortear(int *ptr, int tam, int max)
{
  for (int i = 0; i < tam; i++)
  {
    *(ptr + i) = rand() % max;
  }
}

void ordenar(int *vetor, int tam)
{
  for (int i = 0; i < tam - 1; i++)
  {
    for (int j = i + 1; j < tam; j++)
    {
      if (*(vetor + i) > *(vetor + j))
      {
        *(vetor + i) ^= *(vetor + j);
        *(vetor + j) ^= *(vetor + i);
        *(vetor + i) ^= *(vetor + j);
      }
    }
  }
}

void calc_media(float *media, int *vetor, int tam)
{
  int soma = 0;
  for (int i = 0; i < tam; i++)
  {
    soma += *(vetor + i);
  }
  *media = (float)soma / tam;
}

void calc_mediana(float *mediana, int *vetor, int tam)
{
  int metade = tam / 2;
  *mediana = (tam % 2) ? *(vetor + metade) : (float)(*(vetor + metade) + *(vetor + metade - 1)) / 2;
}

void ocorrencia(int *contagem, int *vetor, int tamVetor)
{
  for (int i = 0; i < tamVetor; i++)
  {
    *(contagem + *(vetor + i)) += 1;
  }
}

void maior_ocorrencia(int *maiorCont, int *contagem, int tamContagem)
{
  for (int i = 0; i < tamContagem; i++)
  {
    *maiorCont = (*(contagem + i) > *maiorCont) ? *(contagem + i) : *maiorCont;
  }
}

void contarTamanhoModa(int *tamModa, int *contagem, int tamContagen, int maiorCont)
{
  for (int i = 0; i < tamContagen; i++)
  {
    if (*(contagem + i) == maiorCont)
    {
      *tamModa += 1;
    }
  }
}

void preencherModa(int *contagem, int *moda, int tamContagen, int tamModa, int maiorCont)
{
  int posicao = 0;
  for (int valor = 0; valor < tamContagen; valor++)
  {
    if (*(contagem + valor) == maiorCont)
    {
      *(moda + posicao) = valor;
      posicao++;
    }
  }
}

void imprimirVetor(int *ptr, int tam)
{
  printf("[");
  for (int i = 0; i < tam; i++)
  {
    printf(" %d ", *(ptr + i));
  }
  printf("]\n");
}