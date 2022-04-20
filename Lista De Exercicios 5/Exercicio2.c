#include <stdio.h>

/*
Desenvolva um código onde o usuário deve inserir dois números e depois o
código deve retornar a multiplicação desse produto (O calculo deve ser
efetuado sem utilizar o operador de multiplicação *)
*/ 


int main() {
    int num1, num2, agregador = 0;
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    //int i;
    //num1 = 3
    //num2 = 2

    //i = 0
    //i = 1
    //i = 2
    //i = 3 Não faz
    /*
    for(i = 0; i < num1; i++) {
    	printf("Agregador antes: %d\n", agregador);
        //i = 0
        //agregador = 0
        agregador  = agregador + num2;
        //agregador = 0
        printf("Agregador depois: %d\n\n", agregador);
    }
    */

   int i = 0;
    while(i < num1) {
        printf("Agregador antes: %d\n", agregador);
        //i = 0
        //agregador = 0
        agregador  = agregador + num2;
        //agregador = 0
        printf("Agregador depois: %d\n\n", agregador);
        i++;
    };

    
    printf("Resultado = %d", agregador);
    
    return 1;
}
