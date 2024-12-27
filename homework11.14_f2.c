#include<stdio.h>
#include<string.h>
int sum_Asciirow(char row[],int len){
	int sum = 0;
	int i;
	for(i=0;i<len;i++){
	       sum += row[i];
	}
        return sum;
}
void swap_row(char arr[][6],int row1,int row2){
	char tmp[6];
	int i;
	for(i=0;i<6;i++){
	tmp[i] = arr[row1][i];
	arr[row1][i] = arr[row2][i];
	arr[row2][i] = tmp[i];
	}
}
void sort_row(char row[],int len){
	int i,j;
	for(i=0;i<len-1;i++){
		for(j=i+1;j<len;j++){
			if(row[j]<row[i]){
				char tmp = row[i];
			        row[i] = row[j];
			        row[j] = tmp;
			}	
		}
	}
}
void sort_2Darray(char arr[][6],int rows){
	int i,j;
	for(i=0;i<rows-1;i++){
		for(j=i+1;j<rows;j++){
	            if(sum_Asciirow(arr[i],6)>sum_Asciirow(arr[j],6)){
			    swap_row(arr,i,j);
	            }
		}
	}
	for(i=0;i<rows;i++){
		sort_row(arr[i],6);
	}

}
int main(){
	char A[][6] = {
        {'S', 'D', 'U', 'Y', 'E', 'S'},
        {'C', 'H', 'I', 'N', 'A', '!'},
        {'A', 'F', 'T', 'E', 'R', 'X'},
        {'h', 'e', 'r', 'o', 'a', 'b'},
        {'C', 'y', 'y', 'D', 'S', '!'}
        };
	int rows = sizeof(A)/sizeof(A[0]);
	int i,j;
	printf("Sorted 2Darray:\n");
	sort_2Darray(A,rows);
	for(i=0;i<rows;i++){
		for(j=0;j<6;j++){
			printf("%c",A[i][j]);
		}
		printf("\n");
	}
	return 0;
}
