#include <stdio.h>
void verifica(int n);

void main() 
{
	float n;
	
	printf("Digite um numero de 4 alagismos: ");
	scanf("%f", &n);
	
	if(n>1000 && n<9999)
	{
		printf("Executando o comando\n");
	}
	else
	{
		printf("Numero invalido\n");
		system("PAUSE");
	}
	for (n=1000; n<=9999; n++)
	  verifica(n);
}

void verifica(int n)
{
	int num1 = n / 100;
	int num2 = n % 100;
	int soma = num1 + num2;
	int prod = soma * soma;
	
	if(prod == n)
	{
		printf("%d\n", n);
		printf("%2d + %2d = %d * %d = %d. \n\n", num1, num2, soma, soma, prod);
	}
}
