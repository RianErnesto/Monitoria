#include <stdio.h>
#include <locale.h>
#include <time.h>

/* 
    Criar um algoritmo que armazene dados em uma matriz de ordem 5 e imprima:
    - Toda a matriz.
    - A matriz gerada só com números ímpares.

    O resultado impresso deve estar no formato de matriz. 
*/

void main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));

    int matriz[5][5];
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            matriz[i][j] = rand()%10;
        }
    }

    printf("Matriz:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz gerada s� com n�meros �mpares:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matriz[i][j] % 2 != 0) {
                printf("%d ", matriz[i][j]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
