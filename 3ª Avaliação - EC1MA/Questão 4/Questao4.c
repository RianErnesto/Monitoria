#include <stdio.h>
#include <locale.h>
#include <math.h>

/* 
    Uma estrutura chamada circulo รฉ definida abaixo. A estrutura consiste no raio da
    cรญrculo e as coordenadas (x,y) do seu centro.

    ๐ฌ๐ญ๐ซ๐ฎ๐๐ญ ๐๐ข๐ซ๐๐ฎ๐ฅ๐จ {
        ๐๐จ๐ฎ๐๐ฅ๐ ๐ซ๐๐ข๐จ;
        ๐๐จ๐ฎ๐๐ฅ๐ ๐ฑ;
        ๐๐จ๐ฎ๐๐ฅ๐ ๐ฒ;
    };

    Implemente a funรงรฃo cruzar() que retorna 1 se dois cรญrculos se cruzam e 0 caso contrรกrio. 
    O protรณtipo da funรงรฃo รฉ dado abaixo:
    ๐ข๐ง๐ญ ๐๐ซ๐ฎ๐ณ๐๐ซ(๐ฌ๐ญ๐ซ๐ฎ๐๐ญ ๐๐ข๐ซ๐๐ฎ๐ฅ๐จ ๐๐, ๐ฌ๐ญ๐ซ๐ฎ๐๐ญ ๐๐ข๐ซ๐๐ฎ๐ฅ๐จ ๐๐);  
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
