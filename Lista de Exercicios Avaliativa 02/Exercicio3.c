#include <stdio.h>
#include <math.h>

void main() {
    int number, firstNumbers, lastNumbers, sum;

    printf("Coloque um numero para saber se ele possui a caracteristica: ");
    scanf("%d", &number);

    firstNumbers = number / 100;
    lastNumbers = number % 1000;
    lastNumbers = lastNumbers % 100;

    sum = firstNumbers + lastNumbers;

    if(pow(sum, 2) == number) 
		printf("O numero possui a caracteristica");
    else 
		printf("O numero nao possui a caracteristica");
}
