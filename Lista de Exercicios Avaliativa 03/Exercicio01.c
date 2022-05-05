#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Criar um algoritmo que funciona de acordo com o menu a seguir, sabendo-se que poder?o ser 
 cadastrado at? 10 clientes, onde o dado necess?rio para o cadastro ? o nome e a milhagem.

********************
*          MENU         *
********************
1- Cadastrar dados do cliente.
2- Listar milhagem do cliente.
3- Imprimir os nomes que t?m maior e menor milhagem.
4- Imprimir os nomes e as milhagens de todos os clientes cadastrados.
5- Sair.
ESCOLHAR:  
*/

int clientNumber = 0;

typedef struct Client{
    char name[50];
    int miles;
    char endereco;
    int telefone
} Client;

Client client[10];

void menu() {
    printf("********************\n");
    printf("*          MENU         *\n");
    printf("********************\n");
    printf("1- Register client data.\n");
    printf("2- List client miles.\n");
    printf("3- Print the names that have greatest and smallest miles.\n");
    printf("4- Print the names and miles from all registered clients.\n");
    printf("5- Quit.\n");
    printf("Choose: ");
}

void registerClientData() {
    if(clientNumber >= 10){
        printf("\nThe maximum number of clients has been reached.\n");
        return;
    }
    printf("\nEnter the client's name: ");
    scanf("%s", client[clientNumber].name);
    printf("Enter the client's miles: ");
    scanf("%d", &client[clientNumber].miles);
    clientNumber++;
}

void listClientMiles() {
    char clientName[100];
    printf("List client miles.\n");
    printf("Enter the client's name: ");
    scanf("%s", clientName);
    int i;
    for (i = 0; i < clientNumber; i++) {
        if (strcmp(clientName, client[i].name) == 0) {
            printf("%s has %d miles.\n", client[i].name, client[i].miles);
            break;
        }
    }
    printf("The client does not exist.\n");
}

void printMoreAndLessMiles() {
    int smallestMiles = client[0].miles;
    int greatestMiles = client[0].miles;
    char smallestMilesName[100];
    char greatestMilesName[100];
    
    strcpy(smallestMilesName, client[0].name);
    strcpy(greatestMilesName, client[0].name);
    
    int i;
    for (i = 0; i < clientNumber; i++) {
        if (client[i].miles < smallestMiles) {
            smallestMiles = client[i].miles;
            strcpy(smallestMilesName, client[i].name);
        }
        if (client[i].miles > greatestMiles) {
            greatestMiles = client[i].miles;
            strcpy(greatestMilesName, client[i].name);
        }
    }
    printf("%s has the smallest miles\n", smallestMilesName);
    printf("%s has the greatest miles\n", greatestMilesName);
}

void printAllClientData() {
    printf("Print all client data.\n");
    int i;
    for (i = 0; i < clientNumber; i++) {
        printf("%s has %d miles.\n", client[i].name, client[i].miles);
    }
}

int printSystem() {
    menu();
    int option;
    scanf("%d", &option);
    system("cls || clear");
    switch (option) {
        case 1:
            registerClientData();
            break;
        case 2:
            listClientMiles();
            break;
        case 3:
            printMoreAndLessMiles();
            break;
        case 4:
            printAllClientData();
            break;
        case 5:
            printf("\nGoodbye!\n");
            break;
        default:
            printf("\nInvalid option.\n");
            break;
    }

    return option;
}

void main() {
    while (printSystem() != 5);
}


