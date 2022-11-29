#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int x, y;

  if (argc != 4)
  {
    printf("Use:\n\n %s <PrimeiroNumero> <SegundoNumero> "
           "<SímboloDaOperaçãoDesejada>\n\n",
           argv[0]);
    exit(1);
  }

  x = atoi(argv[1]);
  y = atoi(argv[2]);

  char *operacao = argv[3];

  switch (*operacao)
  {
  case '+':
    printf("A soma dos números %d + %d é: %d", x, y, x + y);
    break;
  case '-':
    printf("A subtração dos números %d e %d é: %d", x, y, x - y);
    break;
  case 'x':
    printf("A multiplicação dos números %d e %d é: %d", x, y, x * y);
    break;
  case '/':
    printf("A divisão dos números %d e %d é: %.2f", x, y, (float)x / y);
    break;
  }
  return 0;
}