#include<stdio.h>
#include<stdlib.h>
#define PLAYER1 'X'
#define PLAYER2 'O'
char board[15][15];// to initialise a chess board
void initialise_board(){
	int i,j;
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			board[i][j] = '.';
		}
	}
}
void playing_board(){
	printf("\n");
	int i,j;
        for(i=0;i<15;i++){
		printf("   ");
	       	for(j=0;j<15;j++){
                        printf("%2c",board[i][j]);
                }
        printf("\n");
	}
	printf("   ");
	for(i=0;i<15;i++){
		printf("%2d",i);
	}
	printf("\n");
}
int check_win(int row,int col){  // to check which one will win by checking 
        int i,j,count;
        char player = board[row][col];
        count = 0;
        for(j=0;j<15;j++){
                if(board[row][j] == player)
		        count++;
                else count = 0;
                if(count == 5) 
		        return 1;
        }
        count = 0;
        for(i=0;i<15;i++){
                if(board[i][col] == player) 
		        count++;
                else count = 0;
                if(count == 5) 
		        return 1;
        }
        count = 0;
        for(i=1;row - i >= 0 && col - i >= 0;i++){
                if(board[row - i][col - i] == player) 
		        count++;
                else count = 0;
                if(count == 4)
			return 1;
        }
        count = 0;
        for(i=1;row - i >= 0 && col + i<15;i++){
                if(board[row - i][col + i] == player) 
		    count++;
                else count = 0;
                if(count == 4)
		       	return 1;
                break;
        }
        return 0;
}
int board_is_full(){
	int i,j;
        for(i=0;i<15;i++){
                for(j=0;j<15;j++){
                        if(board[i][j] == '.')
                                return 0;
        }
    }
    return 1;
}

int main(){	
        int row, col;
        char input[10];
        initialise_board();
        int player = 1;
        while (1){
                playing_board();
                printf("Player%d make a move: ",player);
                if(scanf("%9s",input) != 1){
                         while (getchar() != '\n');
                         printf("Invalid input. Please enter row and column numbers.\n");
                         continue;
                }
                if(sscanf(input, "%d %d",&row,&col) != 2 || row < 0 || row >=15 || col < 0 || col >= 15 || board[row][col] != '.'){
                         printf("Wrong! Re-enter\n");
                         continue;
                }
                board[row][col] = (player == 1) ? PLAYER1 : PLAYER2;
                if(check_win(row, col)){
                         playing_board();
                         printf("Congratulations! Player%d, you win!\n",player);
                         break;
                }
                if(board_is_full()){
                         playing_board();
                         printf("Drawing game!\n");
                         break;
                }
        player = (player == 1) ? 2 : 1;
        }
        return 0;
}
