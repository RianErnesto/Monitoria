#include <stdio.h>

/*
Criar um algoritmo que leia os elementos de um vetor com 20 posições e
escreva-o. Em seguida, troque o primeiro elemento pelo último, o segundo
pelo penúltimo, o terceiro pelo antepenúltimo, e assim sucessivamente.
Mostre o vetor depois da troca.
*/

void main() {
    int array[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    printf("=====Before de Change=========\n\n");
    int i;
    for(i = 0; i < 20; i++) {
        printf("%d\n", array[i]);
    }

    int j;
    for(i = 0, j = 19; i < j; i++, j--) {
        int saveNumber = array[i];
        array[i] = array[j];
        array[j] = saveNumber;
    }
    
    printf("\n\n=============After the Change================");
    for(i = 0; i < 20; i++) {
        printf("%d\n", array[i]);
    }
}