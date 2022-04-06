#include <stdio.h>

void main() {
    int iterator = 1, number;

    printf("Digite um numero para saber se ele eh triangular: ");
    scanf("%d", &number);

    while(iterator < (number / 2)) {
        if(iterator * (iterator + 1) * (iterator + 2) == number) {
            printf("O numero eh triangular");
            break;
        }

        iterator++;
    }

    if(iterator == number / 2) printf("O numero nao eh triangular");
}
