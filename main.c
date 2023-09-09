#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 4
#define M 4
#define MAX_CNAKE_SIZE 10

unsigned int done = 0;
int position[MAX_CNAKE_SIZE][2] = {{0, 0}};

int board[N][M] = {
    { 0, 0, 0, 0},
    { 0, 0, 0, 0},
    { 0, 0, 0, 0},
    { 0, 0, 0, 0}
};

void moveUp() {
    position[0][0]--;
}

void moveDown() {
    position[0][0]++;
}

void moveLeft() {
    position[0][1]--;
}

void moveRight() {
    position[0][1]++;
}

void separate() {
    printf("===========\n");
}

void updateBoard() {
    int i = 0;

    // M+1 cause we need the \n at the end
    char buff[N * (M+1)] = "0000\n0000\n0000\n0000\n";
    buff[position[0][0] * N + position[0][1]] = '>';
    printf("\r%s", buff);
    fflush(stdout);
}

void runGame() {
    updateBoard();
    moveRight();
    updateBoard();
    done = 1;
    separate();
    printf("Game Over\n");
}

int main(int argc, char* argv) {
    int i = 0;
    while (!done) {
        runGame();
    }
    return 0;
}

