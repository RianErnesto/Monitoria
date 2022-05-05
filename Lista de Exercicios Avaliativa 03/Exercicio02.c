#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
    Escreva um programa para gerenciar 100 contas banc?rias. 
    As contas t?m n?meros que variam de 1001 a 1100 (decimal). 
    Existem v?rios tipos de transa??es, que o programa pode ler. 
    Se permitido, o programa pode modificar o saldo da conta. 
    Caso contr?rio, uma mensagem de erro ser? impressa.
    O di?logo para as transa??es s?o apresentados na Tabela 01.
    A seguir, o tipo em negrito representa as perguntas que o programa digita para o usu?rio. 
    Cada resposta ? pergunta do tipo de transa??o ? um ?nico caractere. 
    Qualquer tentativa de transa??o ilegal causa uma mensagem de erro. 
    Os valores est?o em d?lares e podem ter 0, 1 ou 2 d?gitos ap?s o ponto: 2765 ou 123,4 ou 8864,57:
 */

int currentAccountNumber = 1001;
int currentAccount = 0;

typedef struct Account {
    int number;
    float balance;
} Account;

Account accounts[100];

void inicialDeposit() {
    accounts[currentAccount].number = currentAccountNumber;
    printf("\nInitial deposit: ");
    scanf("%f", &accounts[currentAccount].balance);
    fflush(stdin);
    currentAccountNumber++;
    currentAccount++;
}

void accountBalance() {
    int accountNumber;
    printf("\nAccount number: ");
    scanf("%d", &accountNumber);
    fflush(stdin);
    int i;
    for (i = 0; i < currentAccount; i++) {
        if (accounts[i].number == accountNumber) {
            printf("\nAccount balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("\nAccount not found.\n");
}

void deposit() {
    int accountNumber;
    float value;
    printf("\nAccount number: ");
    scanf("%d", &accountNumber);
    fflush(stdin);
    int i;
    for (i = 0; i < currentAccount; i++) {
        if (accounts[i].number == accountNumber) {
            printf("\nDeposit: ");
            scanf("%f", &value);
            fflush(stdin);
            accounts[i].balance += value;
            printf("\nAccount Number: %d\n", accounts[i].number);
            printf("\nAccount balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("\nAccount not found.\n");
}

void withdraw() {
    int accountNumber;
    float value;
    printf("\nAccount number: ");
    scanf("%d", &accountNumber);
    fflush(stdin);
    int i;
    for (i = 0; i < currentAccount; i++) {
        if (accounts[i].number == accountNumber) {
            printf("\nWithdraw: ");
            scanf("%f", &value);
            fflush(stdin);
            if (accounts[i].balance >= value) {
                accounts[i].balance -= value;
                printf("\nAccount Number: %d\nAccount balance: %.2f\n", accounts[i].number, accounts[i].balance);
            } else {
                printf("\nInsufficient funds.\n");
            }
            return;
        }
    }
    printf("\nAccount not found.\n");
}

void closeAccount() {
    int accountNumber;
    printf("\nAccount number: ");
    scanf("%d", &accountNumber);
    fflush(stdin);
    int i;
    for (i = 0; i < currentAccount; i++) {
        if (accounts[i].number == accountNumber) {
            int j;
            for (j = i; j < currentAccount - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            currentAccount--;
            return;
        }
    }
}

void printAllAccounts() {
    int i;
    for (i = 0; i < currentAccount; i++) {
        if (accounts[i].number != 0) {
            printf("\nAccount Number: %d\nAccount balance: %.2f\n", accounts[i].number, accounts[i].balance);
        }
    }
}

void menu() {
    printf("\nO - Inicial Deposit\n");
    printf("B - Account Balance\n");
    printf("D - Deposit\n");
    printf("W - Withdraw\n");
    printf("C - Close Account\n");
    printf("P - Print All Accounts\n");
    printf("E - Exit\n\n");
}

char typeOfTransaction() {
    menu();
    char transactionType;
    printf("\nType of transaction: ");
    scanf("%c", &transactionType);
    fflush(stdin);
    system("cls");
    
    switch (transactionType) {
        case 'O':
            inicialDeposit();
            break;
        case 'B':
            accountBalance();
            break;
        case 'D':
            deposit();
            break;
        case 'W':
            withdraw();
            break;
        case 'C':
            closeAccount();
            break;
        case 'P':
            printAllAccounts();
            break;
        case 'E':
            printf("\nExiting...\n");
            break;
    }
    
    return transactionType;
}

void main() {
    while (typeOfTransaction() != 'E');
}