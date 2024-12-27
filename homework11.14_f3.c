#include<stdio.h>
#include<stdlib.h>
int is_safe(int board[8][8],int row,int col){
	int i,j;
	// check if Queens are  in columns
	for(i=0;i<8;i++){
		if(board[i][col]== 1)
			return 0;
		}
	//check if Queens are in top left diagonal 
	i= row-1;
	j= col-1;
	while(i>=0 && j>=0){
		if(board[i][j]== 1)
			return 0;
		i--;
		j--;
	}
	//check if Queens are in top right diagonal
	i = row-1;
	j = col+1;
	while(i>=0 && j<8){
		if(board[i][j]== 1)
			return 0;
		i--;
		j++;
	}
	return 1;
}
int solve_Queens(int board[8][8],int row){
        int i,j;
	if(row == 8){
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				printf("%d",board[i][j]);
			}
			printf("\n");
		}
		return 1;
	}
	int col;
	int count = 0;
	for(col=0;col<8;col++){
		if(is_safe(board,row,col)){
			board[row][col] = 1;
			// to store up results
			count += solve_Queens(board,row+1);
			board[row][col] = 0;
		}
	}
	return count;
}
int main(){
	int board[8][8] = {0};
	int solutions = solve_Queens(board,0);
	printf("Total solutions:%d\n",solutions);
	return 0;
}





