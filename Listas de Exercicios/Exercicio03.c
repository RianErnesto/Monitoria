#include <stdio.h>

/*
Suponha três vetores de 10 elementos cada, contendo: nome, endereço,
telefone. Fazer um trecho que se possa buscar pelo nome e imprimir todos
os dados.
*/

void main() {
    char name[10][100] = {"Rian", "Renan", "Teste", "Teste3", "Teste4", "Teste5", "Teste6", "Teste7", "Teste8", "Teste9"};
    char address[10][100] = {"Rian", "Renan", "Teste", "Teste3", "Teste4", "Teste5", "Teste6", "Teste7", "Teste8", "Teste9"};
    char number[10][100] = {"Rian", "Renan", "Teste", "Teste3", "Teste4", "Teste5", "Teste6", "Teste7", "Teste8", "Teste9"};

    char userName[100];

    printf("Insert the name you are looking for: ");
    gets(userName);

    int i;
    for(i = 0; i < 10; i++) {
        if(name[i] == userName)
            break;
    }

    if(i == 10)    
        printf("Name not found.");
    else {
        printf("Name: %s\n", name[i]);
        printf("Address: %s\n", address[i]);
        printf("Number: %s", number[i]);
    }
}