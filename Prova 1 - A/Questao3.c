#include <stdio.h>

void true_false(int value) {
    value ? printf("True\n") : printf("False\n");
}

void main() {
    int x = 4, y = 6, z = -1;

    int first = x == 5;
    int second = (x == 5) || z < 0;
    int third = y - x + z - 1;
    int forth = x == 4 || y >= z && !z;

    true_false(first);
    true_false(second);
    true_false(third);
    true_false(forth);
}
