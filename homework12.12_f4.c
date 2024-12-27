#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15
char board[SIZE][SIZE];
int player = 1; // 1 for human, 2 for AI
// Initialize the board
void initializeBoard(){
	int i,j;
        for (i = 0; i < SIZE; i++) {
                for (j = 0; j < SIZE; j++) {
                        board[i][j] = '.';
                }
        }
}
// Print the board
void printBoard() {
	int i,j;
        for (i = 0; i < SIZE; i++) {
                for (j = 0; j < SIZE; j++) {
                        printf("%c ", board[i][j]);
                }
                printf("\n");
        }
}
// Check if a move is valid
int isValidMove(int x, int y) {
        return board[x][y] == '.';
}
// Make a move
void makeMove(int x, int y, int currentPlayer) {
        board[x][y] = (currentPlayer == 1) ? 'X' : 'O';
}
// Check if someone wins (simple 5-in-a-row check)
int checkWin(int x, int y, int currentPlayer) {
        char symbol = (currentPlayer == 1) ? 'X' : 'O';
        int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
        for (int i = 0; i < 4; i++) {
                int count = 1;
                for (int j = 1; j < 5; j++) {
                        int newX = x + j * directions[i][0];
                        int newY = y + j * directions[i][1];
                        if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && board[newX][newY] == symbol) {
                        count++;
                        } else {
                                break;
                        }
                }
                for (int j = 1; j < 5; j++) {
                        int newX = x - j * directions[i][0];
                        int newY = y - j * directions[i][1];
                        if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && board[newX][newY] == symbol) {
                                count++;
                        } else {
                                break;
                        }
                }
                if (count >= 5) {
                        return 1;
                }
        }
        return 0;
}
// AI's random move
void aiMove(int *x,int *y) {
        do {
                *x = rand() % SIZE;
                *y = rand() % SIZE;
        } while (!isValidMove(*x,*y));
        makeMove(*x,*y,2);
}
int main(){
        srand(time(NULL));
        initializeBoard();
        int gameOver = 0;
        while (!gameOver) {
                printBoard();
                if (player == 1) {
                        int input_x,input_y;
                        printf("Enter your move (row and column): ");
                        scanf("%d %d", &input_x, &input_y);
                        while (!isValidMove(input_x,input_y)) {
                                printf("Invalid move. Try again: ");
                                scanf("%d %d", &input_x, &input_y);
                        }
                        makeMove(input_x,input_y,1);
                        if (checkWin(input_x,input_y,1)) {
                                printBoard();
                                printf("You win!\n");
                                gameOver = 1;
                        }
                        player = 2;
                } else {
			int ai_x,ai_y;
                        aiMove(&ai_x,&ai_y);
                        if (checkWin(ai_x,ai_y,2)) {
                                printBoard();
                                printf("AI wins!\n");
                                gameOver = 1;
                        }
                        player = 1;
                }
        }
        return 0;
}
