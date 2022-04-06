#include <stdio.h>
#include <stdlib.h>

/* Criar um algoritmo que funcione atrav?s do menu a seguir:

####### MAQUINA ESPERTA #######
1 - Somar v?rios n?meros
2 - Multiplicar v?rios n?meros
3 - Sair

Ao escolher a op??o 1 ou 2, o usu?rio vai digitar quantos n?mero que ele
quiser e o resultado deve atualizar a cada novo valor.
Para voltar para o menu principal, o usu?rio deve digitar -0.0001. */

int checkIfLeave(float number) {
    if(number == (float)(-0.0001))
        return 1;
    return 0;
}

void printMenu()
{
    printf("####### SMART MACHINE #######\n");
    printf("1 - Sum multiple numbers\n");
    printf("2 - Multiply multiple numbers\n");
    printf("3 - Exit\n");
    printf("(Any moment you wanna back to main menu type -0.0001)\n\n");
    printf("Choice: ");
}

void sumValues(int length)
{
    int accumulator = 0;
    float number;
    int i = 0;
    while (i < length)
    {
        printf("\t\t\t\t\tResult: %d\n\n", accumulator);

        printf("Whats the Number? ");
        scanf("%f", &number);
        
        system("cls || clear");
        if(checkIfLeave(number))
            break;

        accumulator += (int)number;

        i++;
    }

    printf("Sum Result: %d\n\n", accumulator);
}

void multiplyNumbers(int length)
{
    int accumulator = 1;
    float number;
    int i = 0;
    while (i < length)
    {
        printf("\t\t\t\t\tResult: %d\n\n", accumulator);

        printf("Whats the Number? ");
        scanf("%f", &number);
        
        system("cls || clear");
        if(checkIfLeave(number))
            break;

        accumulator *= (int)number;

        i++;
    }

    printf("Multiply Result: %d\n\n", accumulator);
}

void main()
{
    int choice = 1;
    float lengthNumbers;

    while (choice == 1 || choice == 2)
    {
        printMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls || clear");
            printf("How many numbers will you sum? ");
            scanf("%f", &lengthNumbers);
            if(!checkIfLeave(lengthNumbers))
                sumValues(lengthNumbers);
            break;

        case 2:
            system("cls || clear");
            printf("How many numbers will you multiply? ");
            scanf("%f", &lengthNumbers);
            if(!checkIfLeave(lengthNumbers))
                multiplyNumbers(lengthNumbers);
            break;

        default:
            break;
        }
    }
}
















