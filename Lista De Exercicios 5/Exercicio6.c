#include <stdio.h>

/* Escreva um programa que coloque na tela meia árvore de natal com
asteriscos. O número de ramos deverá ser inserido pelo usuário. (Para um
desafio maior, crie a árvore inteira).
Exemplo com 3, 4 e 5 ramos:
*/

void main() {
    int quantidadeRamos;

    printf("Digite a quantidade de ramos: ");
    scanf("%d", &quantidadeRamos);

    int i;
    for(i = 0; i < quantidadeRamos; i++) {
        int j;
        for(j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    } 
}
