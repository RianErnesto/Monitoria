#include <stdio.h>

/*
Criar um algoritmo que entre com valores inteiros para uma matriz m 3x3 e
imprimir a matriz final, conforme mostrado a seguir (a matriz gira 90°):

[1 2 3
 4 5 6
 7 8 9] 
 ⇒ 
[7 4 1
 8 5 2
 9 6 3]

*/

void main() {
    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int matrix90[3][3];

    int i, j, h;
    for(i = 0; i < 3; i++) {
        for(j = 0, h = 2; j < 3; j++, h--) {
            matrix90[i][j] = matrix[h][i];
            printf("%d\t", matrix90[i][j]);
        }
        printf("\n");
    }
}