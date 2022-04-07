#include <stdio.h>

void main() {
    int number;

    printf("Number: ");
    scanf("%d", &number);

    int i;
    for(i = 0; i < number / 3; i++) {
        if(i * (i + 1) * (i + 2) == number)
        {
            printf("\n\nThe number is triangular");
            break;
        }
    }

    if(i == number / 3)
        printf("\n\nThe number is not triangular");
}