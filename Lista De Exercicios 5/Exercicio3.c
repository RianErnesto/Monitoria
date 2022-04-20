#include <stdio.h>

/*
Apresentar todos os valores numéricos inteiros PARES situados na faixa de
100 a 200. Depois dos valores serem impressos, mostre a soma desses
valores.
*/

void main() {
    int i, soma = 0;
    for(i = 100; i < 200; i = i + 2) {
        //i = 100
        //soma = 0
        printf("%d\n", i);
        soma = soma + i;
        //soma = 100
    }
    
    printf("Soma = %d", soma);
}
