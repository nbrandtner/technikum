#include <stdio.h>

#define SIZE 10

void initializeArray(char array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = '.';
        }
    }
}

void printArray(char array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int x, int y, char array[SIZE][SIZE], char step) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || array[x][y] != '.') {
        return 0;
    }
    return 1;
}

int main() {
    char array[SIZE][SIZE];
    char step = 'A';
    int x = 0, y = 0;

    initializeArray(array);

    while (1) {
        if (step > 'Z') {
            step = 'A';
        }

        array[x][y] = step;

        printArray(array);
        int corr=0;
        while(corr==0){
            char move;
            printf("walk to:\n");
            scanf(" %c", &move);

            if (move == 'x') {
                return 0;
            }

            int newX = x, newY = y;

            switch (move) {
                case 'n':
                    newX--;
                    break;
                case 'e':
                    newY++;
                    break;
                case 's':
                    newX++;
                    break;
                case 'w':
                    newY--;
                    break;
                default:
                    printf("Ungültige Eingabe! Gültige Eingaben sind 'n', 'e', 's', 'w' oder 'x'.\n");
                    continue;
            }

            if (isValidMove(newX, newY, array, step + 1)) {
                x = newX;
                y = newY;
                step++;
                corr=1;
            } else {
                printf("not possible\n");
            }
        }
    }

    return 0;
}
