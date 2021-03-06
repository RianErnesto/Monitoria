#include <stdio.h>
#include <locale.h>

#define TAMANHO 5
/* 
    Desenvolva um algoritmo que possui uma ๐ณ๐๐ป๐ฐฬง๐ฎฬ๐ผ chamada ๐ผ๐ฟ๐ฑ๐ฒ๐บ. Essa funรงรฃo recebe como ๐ฝ๐ฎ๐ฟ๐ฎฬ๐บ๐ฒ๐๐ฟ๐ผ ๐ฑ๐ฒ 
    ๐ฒ๐ป๐๐ฟ๐ฎ๐ฑ๐ฎ um vetor e escreve como resultado se o vetor estรก ordenado na ordem ๐ฐ๐ฟ๐ฒ๐๐ฐ๐ฒ๐ป๐๐ฒ, ๐ฑ๐ฒ๐ฐ๐ฟ๐ฒ๐๐ฐ๐ฒ๐ป๐๐ฒ 
    ou ๐ป๐ฎฬ๐ผ ๐ผ๐ฟ๐ฑ๐ฒ๐ป๐ฎ๐ฑ๐ผ.

    ๐ ๐ซ๐๐ฉ๐ค๐ง ๐ฬ ๐๐ค ๐ฉ๐๐ฅ๐ค ๐๐ฃ๐ฉ๐๐๐ง๐ค ๐ ๐๐๐ซ๐ ๐ฉ๐๐ง ๐ฑ ๐๐ก๐๐ข๐๐ฃ๐ฉ๐ค๐จ, ๐ค๐ฃ๐๐ ๐๐จ๐จ๐๐จ ๐๐ก๐๐ข๐๐ฃ๐ฉ๐ค๐จ ๐จ๐ฬ๐ค ๐๐ฃ๐จ๐๐ง๐๐๐ค๐จ ๐ฅ๐๐ก๐ค ๐ช๐จ๐ช๐ฬ๐ง๐๐ค. 
*/

void ordem(int vetor[]) {
    if(crescente(vetor)) {
        printf("Crescente\n");
    }
    else if(decrescente(vetor)) {
        printf("Decrescente\n");
    }
    else {
        printf("Nรฃo ordenado\n");
    }
}

int crescente(int vetor[]) {
    int i;
    for (i = 0; i < TAMANHO - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int decrescente(int vetor[]) {
    int i;
    for (i = 0; i < TAMANHO - 1; i++) {
        if (vetor[i] < vetor[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void main() {
    setlocale(LC_ALL, "Portuguese");

    int vetor[TAMANHO];

    int i;
    for (i = 0; i < TAMANHO; i++) {
        printf("Digite o %dยบ nรบmero: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    ordem(vetor);
}