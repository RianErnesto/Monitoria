#include <stdio.h>
#include <locale.h>

#define TAMANHO 5
/* 
    Desenvolva um algoritmo que possui uma 𝗳𝘂𝗻𝗰̧𝗮̃𝗼 chamada 𝗼𝗿𝗱𝗲𝗺. Essa função recebe como 𝗽𝗮𝗿𝗮̂𝗺𝗲𝘁𝗿𝗼 𝗱𝗲 
    𝗲𝗻𝘁𝗿𝗮𝗱𝗮 um vetor e escreve como resultado se o vetor está ordenado na ordem 𝗰𝗿𝗲𝘀𝗰𝗲𝗻𝘁𝗲, 𝗱𝗲𝗰𝗿𝗲𝘀𝗰𝗲𝗻𝘁𝗲 
    ou 𝗻𝗮̃𝗼 𝗼𝗿𝗱𝗲𝗻𝗮𝗱𝗼.

    𝙊 𝙫𝙚𝙩𝙤𝙧 𝙚́ 𝙙𝙤 𝙩𝙞𝙥𝙤 𝙞𝙣𝙩𝙚𝙞𝙧𝙤 𝙚 𝙙𝙚𝙫𝙚 𝙩𝙚𝙧 𝟱 𝙚𝙡𝙚𝙢𝙚𝙣𝙩𝙤𝙨, 𝙤𝙣𝙙𝙚 𝙚𝙨𝙨𝙚𝙨 𝙚𝙡𝙚𝙢𝙚𝙣𝙩𝙤𝙨 𝙨𝙖̃𝙤 𝙞𝙣𝙨𝙚𝙧𝙞𝙙𝙤𝙨 𝙥𝙚𝙡𝙤 𝙪𝙨𝙪𝙖́𝙧𝙞𝙤. 
*/

void ordem(int vetor[]) {
    if(crescente(vetor)) {
        printf("Crescente\n");
    }
    else if(decrescente(vetor)) {
        printf("Decrescente\n");
    }
    else {
        printf("Não ordenado\n");
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
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    ordem(vetor);
}