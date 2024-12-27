#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PLAYER1 'X'
#define PLAYER2 'O'
#define EMPTY ' '
#define SIZE 3
char board[SIZE][SIZE];
void initialise_board(){
        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                        board[i][j] = EMPTY;
                }
        }
}
void playing_board() {
        printf("\n");
        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                        printf("%c | ", board[i][j]);
                }
                printf("\n");
        }
}
int check_win(char player) {
        for (int i = 0; i < SIZE; i++) {
                if (board[i][0] == player && board[i][0] == board[i][1] && board[i][0] == board[i][2])
                return 1;
                if (board[0][i] == player && board[0][i] == board[1][i] && board[0][i] == board[2][i])
                return 1;
        }
        if (board[0][0] == player && board[0][0] == board[1][1] && board[0][0] == board[2][2])
                return 1;
        if (board[2][0] == player && board[2][0] == board[1][1] && board[2][0] == board[0][2])
                return 1;
        return 0;
}
 
int get_random_move() {
        int count = 0;
        int moves[SIZE * SIZE][2];
        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                        if (board[i][j] == EMPTY) {
                        moves[count][0] = i;
                        moves[count][1] = j;
                        count++;
                        }
                }
        }
        srand(time(NULL));
        int random_index = rand() % count;
        return (moves[random_index][0] * SIZE) + moves[random_index][1];
}
int get_best_move(char player) {
        int best_move = -1;
	char opponent;
        int score = -1000;  // Low score for a move that doesn't lead to a win or block
        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                        if (board[i][j] == EMPTY) {
                                board[i][j] = player;
                        if (check_win(player)) {
                                best_move = (i * SIZE) + j;
                                score = 1000;  // High score for a winning move
                                goto end;  // Exit nested loops
                        }
                // Check if the move blocks the opponent from winning
                        if (player == PLAYER1) {
                                char opponent = PLAYER2;
                        } else {
                                char opponent = PLAYER1;
                        }
                        int block_score = 0;
                        for (int k = 0; k < SIZE; k++) {
                                for (int l = 0; l < SIZE; l++) {
                                        if (board[k][l] == EMPTY) {
                                                board[k][l] = opponent;
                                                if (check_win(opponent)) {
                                                        block_score++;
                                                }
                                        board[k][l] = EMPTY;  // Undo the move
                                        }
                                }
                        }
                        if (block_score > 0) {
                                if (score < 0) {  // Prefer blocking over random if no winning move
                                        best_move = (i * SIZE) + j;
                                        score = 0;  // Neutral score for a blocking move
                                }
                        }
                        board[i][j] = EMPTY;  // Undo the move
                        }
                }
        }
        if (best_move == -1) {  // If no winning or blocking move, return a random move
                best_move = get_random_move();
        }
end:
        return best_move;
}
int board_is_full() {
        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                        if (board[i][j] == EMPTY)
                                return 0;
                }
        }
        return 1;
}
int main() {
        int row, col;
        initialise_board();
        int player = 1;
        int ai_move;
        char ai_player = PLAYER2; 
        while (1) {
                playing_board(); 
                if (player == 1) {  // Human player
                        printf("Player %d make a move: ", player);
                        scanf("%d %d", &row, &col);
                        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != EMPTY) {
                                printf("Wrong! Re-enter\n");
                                continue;
                        }
                        board[row][col] = (player == 1) ? PLAYER1 : PLAYER2;
                } else {  // AI player
                        ai_move = get_best_move(ai_player);
                        row = ai_move / SIZE;
                        col = ai_move % SIZE;
                        board[row][col] = ai_player;
                        printf("AI (Player %d) makes a move at (%d, %d)\n", player, row, col);
                }
                if (check_win((player == 1) ? PLAYER1 : PLAYER2)) {
                printf("Congratulations! Player %d, you win!\n", player);
                break;
                }
                if (board_is_full()) {
                        printf("Drawing game!\n");
                        break;
                }
                player = (player == 1) ? 2 : 1;
        }
        return 0;
}
