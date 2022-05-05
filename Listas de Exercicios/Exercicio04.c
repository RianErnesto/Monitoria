#include <stdio.h>

/*
Entrar com uma matriz C3X2. Gerar e imprimir a Ct
*/

void main() {
    int matrix[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    int matrixT[2][3];

    int i, j;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            matrixT[i][j] = matrix[j][i];
            printf("%d\t", matrixT[i][j]);
        }
        printf("\n");
    }
}