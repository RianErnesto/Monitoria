#include <stdio.h>
#include <math.h>

void main() {
    int number, first2Numbers, last2Numbers, sum, sumSquare;

    printf("Number: ");
    scanf("%d", &number);

    if(number > 9999 || number < 1000)
        return;


    first2Numbers = number / 100;
    last2Numbers = (number % 1000) % 100;

    sum = first2Numbers + last2Numbers;
    sumSquare = pow(sum, 2);

    if(sumSquare == number)
        printf("\n\nThe number has the characteristic");
    else
        printf("\n\nThe number doesn't have the characteristic");

}