#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Criar uma função que receba uma mensagem, 
seu tamanho e um caractere e retire todas as ocorr?ncias desse caractere na mensagem, 
colocando * em seu lugar.
A função deve retornar o total de caracteres retirados.
 */

void removeChar(char *message, int size, char character) {
    int i, count = 0;
    for (i = 0; i < size; i++) {
        if (message[i] == character) {
            count++;
        }
    }
    for (i = 0; i < size; i++) {
        if (message[i] == character) {
            message[i] = '*';
        }
    }
    printf("\n%s\n", message);
    printf("\n%d", count);
}

void main() {
    char message[100];
    int size;
    char character;

    printf("\nMessage: ");
    scanf("%s", message);
    fflush(stdin);
    size = strlen(message);

    printf("\nCharacter: ");
    scanf("%c", &character);
    fflush(stdin);

    removeChar(message, size, character);
}

