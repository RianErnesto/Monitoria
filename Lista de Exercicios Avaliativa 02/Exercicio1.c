#include <stdio.h>

void main() {
    char name[100];
    int age;

    printf("Nome: ");
    gets(name);

    printf("Idade: ");
    scanf("%d", &age);

    printf("\n%s\n", name);

    if(age <= 10) {
        printf("Valor a pagar: R$30,00");
    }
    else if(age > 10 && age <= 29) {
        printf("Valor a pagar: R$60,00");
    }
    else if(age > 29 && age <= 45) {
        printf("Valor a pagar: R$120,00");
    }
    else if(age > 45 && age <= 59) {
        printf("Valor a pagar: R$150,00");
    }
    else if(age > 59 && age <= 65) {
        printf("Valor a pagar: R$250,00");
    }
    else {
        printf("Valor a pagar: R$400,00");
    }
}
