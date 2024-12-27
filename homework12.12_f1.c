#include<stdio.h>
#include<stdlib.h>
#define PLAYER1 'X'
#define PLAYER2 'O'
char board[3][3];// to initialise a chess board
void initialise_board(){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			board[i][j] = ' ';
		}
	}
}
void playing_board(){
	printf("\n");
	printf("%c | %c | %c |\n",board[0][0],board[0][1],board[0][2]);
	printf("%c | %c | %c |\n",board[1][0],board[1][1],board[1][2]);
	printf("%c | %c | %c |\n",board[2][0],board[2][1],board[2][2]);
}
int check_win(){ // to check which one will win by checking in every diretion
	int i,j;
	for(i=0;i<3;i++){
		if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return 1;
	}
	for(j=0;j<3;j++){
		if(board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j])
			return 1;
	}
	if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return 1;
	if(board[2][0] != ' ' && board[2][0] == board[1][1] && board[2][0] == board[0][2])
		return 1;
	return 0;
}
int board_is_full(){  // to check if the chess board is full
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
int main(){
	int row,col;
	initialise_board();
        int player = 1;
	while(1){
		playing_board();
		printf("Player%d make a move",player);
		scanf("%d %d",&row,&col);
		if(row<0||row>2||col<0||col>2 || board[row][col] != ' '){
			printf("Wrong!Re_enter\n");
			continue;
		}
		board[row][col] = (player==1)? PLAYER1 : PLAYER2;
		if(check_win()){
			printf("Congratulation! Player%d,you win!\n",player);
			break;
		}
		if(board_is_full()){
			printf("Drawning game!\n");
			break;
		}
		player = (player==1)? 2:1;
	}
	return 0;
}

