#include<stdio.h>
void matrix_multi(double A[3][4],double B[4][5],double C[3][5]){
	int i,j,k;
	for(i=0;i<3;i++){  //traverse columns and rows in C
		for(j=0;j<5;j++){
			C[i][j] = 0;
			for(k=0;k<4;k++){  //multiply i row with j column
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}
int main(){
        double A[3][4]={{1,2,3,6},
	           	{4,5,6,7},
			{7,6,10,10}
	               };	
	double B[4][5]={{3,4,5,6,1},
		        {6,5,4,7,1},
			{7,6,7,8,1},
			{2,0,0,4,7}
	               };
	double C[3][5];
	int i,j;
        matrix_multi(A,B,C);
	printf("RESULT:\n");
	for(i=0;i<3;i++){
		for(j=0;j<5;j++){  //traverse and print
			printf("%.0f,",C[i][j]);
		}
		printf("\n");
	}
	return 0;
}

