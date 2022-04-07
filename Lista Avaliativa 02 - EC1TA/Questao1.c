#include <stdio.h>

void main() {
    char name[100];
    int age;

    printf("Name: ");
    gets(name);

    printf("Age: ");
    scanf("%d", &age);

    printf("\n\n%s - ", name);

    if(age <= 10)
        printf("R$30,00");
    else if(age > 10 && age <= 29)
        printf("R$60,00");
    else if(age > 29 && age <= 45)
        printf("R$120,00");
    else if(age > 45 && age <= 59)
        printf("R$150,00");
    else if(age > 59 && age <= 65)
        printf("R$250,00");
    else
        printf("R$400,00");
}