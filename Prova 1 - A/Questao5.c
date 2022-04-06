#include <stdio.h>

/* Desenvolva um algoritmo que desenhe um retângulo, onde o usuário deve 
informar a altura e comprimento.

Exemplo:
Altura = 7
Comprimento = 7 */


int width;
int heigth;
char character = '#';

void draw() {
    int i;
    for(i = 0; i < heigth; i++) {
        int j;
        for(j = 0; j < width; j++) {
            if(i == 0 || i == (heigth - 1) || j == 0 || j == (width - 1))
                printf("%c", character);
            else
                printf(" ");
        }
        printf("\n");
    }
}

void main() {
    printf("Width: ");
    scanf("%d", &width);

    printf("Heigth: ");
    scanf("%d", &heigth);

    draw();
}