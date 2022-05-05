#include <stdio.h>
#include <time.h>

#define MATRIX_WIDTH 20
#define MATRIX_HEIGTH 20
#define MAX_DROPS_MOVING 6
#define MAX_DROPS 15

char dropChar = '.';
char seedChar = '*';
char generalChar = '-';
char matrix[MATRIX_HEIGTH][MATRIX_WIDTH];
char matrixCopy[MATRIX_HEIGTH][MATRIX_WIDTH];

int quantityDropsMoving = 0;
int quantityDrops = 0;

int gameOver = 0;

void spawnDrop() {
    if(quantityDrops >= MAX_DROPS && quantityDropsMoving == 0) {
        printf("\n\nThe fractal is complete!\n");
        gameOver = 1;
        return;
    }
    else if(quantityDrops >= MAX_DROPS && quantityDropsMoving >= 0) {
        return;
    }
    else if(quantityDropsMoving >= MAX_DROPS_MOVING) {
        return;
    }

    int x = rand() % MATRIX_WIDTH;
    int y = 0;

    if (matrix[y][x] != generalChar) {
        spawnDrop();
    } else {
        matrix[y][x] = dropChar;
        quantityDropsMoving++;
        quantityDrops++;
    }
}

int move() {
    // 0 = UP
    // 1 = DOWN
    // 2 = LEFT
    // 3 = RIGHT
    return rand() % 4;
}

void checkWhatsOnNextMove(int y, int x) {
    int previousY = y;
    int previousX = x;
    int nextY;
    int nextX;
    int nextMove = move();

    if (nextMove == 0) {
        nextY = previousY - 1;
    } else if (nextMove == 1) {
        nextY = previousY + 1;
    } else if (nextMove == 2) {
        nextX = previousX - 1;
    } else if (nextMove == 3) {
        nextX = previousX + 1;
    }

    if(matrix[nextY][nextX] == seedChar) {
        matrixCopy[previousY][previousX] = seedChar;
        //matrix[previousY][previousX] = seedChar;
        quantityDropsMoving--;
    }
    else if(nextY < 0 || nextY >= MATRIX_HEIGTH || nextX < 0 || nextX >= MATRIX_WIDTH) {
        matrixCopy[previousY][previousX] = generalChar;
        //matrix[previousY][previousX] = generalChar;
        quantityDropsMoving--;
    }
    else if(matrix[nextY][nextX] == generalChar) {
        matrixCopy[previousY][previousX] = generalChar;
        //matrix[previousY][previousX] = generalChar;
        matrixCopy[nextY][nextX] = dropChar;
        //matrix[nextY][nextX] = dropChar;
    }
}

void dropsMoving() {
    int i, j;
    for(i = 0; i < MATRIX_HEIGTH; i++) {
        for(j = 0; j < MATRIX_WIDTH; j++) {
            if (matrix[i][j] == dropChar) {
                checkWhatsOnNextMove(i, j);
            }
        }
    }
}

void generateFixedSeedsOnMatrix() {
    int possibleWidth = MATRIX_WIDTH - 2;
    int seedsQuantity = MATRIX_WIDTH * 0.1;

    quantityDrops += seedsQuantity;

    matrix[MATRIX_HEIGTH - 1][1] = seedChar;

    int spaceToNextDrop = seedsQuantity > 1 ? (possibleWidth / (seedsQuantity - 1)) - 2 : 1;
    int nextDropPosition = rand() % spaceToNextDrop + 2;

    int i;
    for(i = 0; i < seedsQuantity-1; i++) {
        matrix[MATRIX_HEIGTH - 1][nextDropPosition + 1] = seedChar;
        nextDropPosition += nextDropPosition;
    }
}

void generateMatrix() {
    int i, j;
    for(i = 0; i < MATRIX_HEIGTH; i++) {
        for(j = 0; j < MATRIX_WIDTH; j++) {
            matrix[i][j] = generalChar;
        }
    }
}

void printMatrix() {
    int i;
    for(i = 0; i < MATRIX_HEIGTH; i++) {
        int j;
        for(j = 0; j < MATRIX_WIDTH; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}

void copyTheMatrix() {
    int i, j;
    for(i = 0; i < MATRIX_HEIGTH; i++) {
        for(j = 0; j < MATRIX_WIDTH; j++) {
            matrixCopy[i][j] = matrix[i][j];
        }
    }
}

void copyBackToMainMatrix() {
    int i, j;
    for(i = 0; i < MATRIX_HEIGTH; i++) {
        for(j = 0; j < MATRIX_WIDTH; j++) {
            matrix[i][j] = matrixCopy[i][j];
        }
    }
}

void main() {
    srand(time(0));

    generateMatrix();
    generateFixedSeedsOnMatrix();
    spawnDrop();
    printMatrix();
    copyTheMatrix();

    while(!gameOver) {
        spawnDrop();
        copyTheMatrix();
        dropsMoving();
        copyBackToMainMatrix();
        printMatrix();
    }
}













