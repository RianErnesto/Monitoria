#include <stdio.h>

/* Criar um algoritmo que a partir da idade e peso do paciente calcule a dosagem de determinado medicamento
e imprima a receita informando quantas gotas do medicamento o paciente deve tomar por dose.
Considerando que o medicamento em questão possui 500 mg por ml, e que cada ml corresponde a 20 gotas.

* Adultos ou adolescentes desde 12 anos, inclusivo, se tiverem peso igual ou acima de 60 Kg devem
tomar 1000 mg; Com peso abaixo de 60 Kg devem tomar 875 mg.

* Para crianças e adolescentes abaixo de 12 anos a dosagem é calculada pelo peso corpóreo conforme a
tabela a seguir: */

int age, quantity;
float weigth;

void weigthGreaterThan()
{
    if (weigth >= 60)
        quantity = 1000;
    else
        quantity = 875;
}

void weigthLesserThan()
{
    if (weigth >= 5 && weigth < 9)
        quantity = 125;
    else if (weigth >= 9 && weigth < 16)
        quantity = 250;
    else if (weigth >= 16 && weigth < 24)
        quantity = 375;
    else if (weigth >= 24 && weigth < 30)
        quantity = 500;
    else
        quantity = 750;
}

void checkAge()
{
    if (age >= 12)
        weigthGreaterThan();
    else
        weigthLesserThan();
}

float calculatingMedicine() {
    float medicine = (quantity / 500.0) * 20;
    return medicine;
}

void main()
{
    printf("Age: ");
    scanf("%d", &age);

    printf("Weigth: ");
    scanf("%f", &weigth);

    checkAge();
    printf("Quantity: %.2f drops" ,calculatingMedicine());
}