#include <stdio.h>
#include <string.h>

/*
Palíndromo, segundo o dicionário Houaiss, “diz-se de ou frase ou palavra
que se pode ler, indiferentemente, da esquerda para direita ou vice-versa”:
osso, Ana, radar, Renner, Roma é amor, orava o avaro, socorram-me subi no
ônibus em Marrocos...
Desenvolva um algoritmo que consegue identificar se a palavra inserida pelo
usuário é palíndromo.
*/

void main() {
    char word[100];
    int isPalindrom = 0;

    printf("Insert a word: ");
    gets(word);

    int i, j;
    for(i = 0, j = strlen(word) - 1; i < j; i++, j--) {
        if(i != j) 
            break;
    }

    if(i > j) 
        printf("\n\nThe number inserted is a palindrom");
    else   
        printf("\n\nThe number inserted is not a palindrom");
}