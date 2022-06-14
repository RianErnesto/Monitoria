#include <stdio.h>
#include <locale.h>

/* 
    Desenvolva um algoritmo que recebe uma mensagem e faz a criptografia dela com a seguinte regra:

    A -> X;
    E -> Y;
    I -> W;
    O -> K;
    U -> Z;

    Para facilitar o processo, trabalhe somente com texto mai√∫sculo.  
*/

void criptografia(char *mensagem) {
    int i;
    for (i = 0; mensagem[i] != '\0'; i++) {
        if (mensagem[i] == 'A') {
            mensagem[i] = 'X';
        } else if (mensagem[i] == 'E') {
            mensagem[i] = 'Y';
        } else if (mensagem[i] == 'I') {
            mensagem[i] = 'W';
        } else if (mensagem[i] == 'O') {
            mensagem[i] = 'K';
        } else if (mensagem[i] == 'U') {
            mensagem[i] = 'Z';
        }
    }
}

void main() {
    setlocale(LC_ALL, "Portuguese");
    char mensagem[100];
    int i;

    printf("Digite a mensagem: ");
    scanf("%s", mensagem);

    printf("Mensagem n„o criptografada: %s\n", mensagem);
    criptografia(mensagem);
    printf("Mensagem criptografada: %s\n", mensagem);
}
