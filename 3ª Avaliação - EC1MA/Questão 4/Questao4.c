#include <stdio.h>
#include <locale.h>
#include <math.h>

/* 
    Uma estrutura chamada circulo é definida abaixo. A estrutura consiste no raio da
    círculo e as coordenadas (x,y) do seu centro.

    𝐬𝐭𝐫𝐮𝐜𝐭 𝐜𝐢𝐫𝐜𝐮𝐥𝐨 {
        𝐝𝐨𝐮𝐛𝐥𝐞 𝐫𝐚𝐢𝐨;
        𝐝𝐨𝐮𝐛𝐥𝐞 𝐱;
        𝐝𝐨𝐮𝐛𝐥𝐞 𝐲;
    };

    Implemente a função cruzar() que retorna 1 se dois círculos se cruzam e 0 caso contrário. 
    O protótipo da função é dado abaixo:
    𝐢𝐧𝐭 𝐜𝐫𝐮𝐳𝐚𝐫(𝐬𝐭𝐫𝐮𝐜𝐭 𝐜𝐢𝐫𝐜𝐮𝐥𝐨 𝐜𝟏, 𝐬𝐭𝐫𝐮𝐜𝐭 𝐜𝐢𝐫𝐜𝐮𝐥𝐨 𝐜𝟐);  
*/

typedef struct Circulo {
    double raio;
    double x;
    double y;
} Circulo;

int cruzar(Circulo c1, Circulo c2) {
    double distancia = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    if (distancia < c1.raio + c2.raio) {
        return 1;
    }
    return 0;
}

void main() {
    setlocale(LC_ALL, "Portuguese");

    Circulo c1;
    Circulo c2;

    c1.raio = 4;
    c1.x = 5;
    c1.y = 3;

    c2.raio = 5;
    c2.x = 10;
    c2.y = 10;

    printf("%d\n", cruzar(c1, c2));
}
