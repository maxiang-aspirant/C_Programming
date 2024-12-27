#include <stdio.h>
int main(){
    int array[3][4]; 
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 4;j++){
            array[i][j] = i * 4 + j; 
        }
    }
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 4;j++){
            printf("array[%d][%d] = %d\n", i, j, array[i][j]);
        }
    }
    // to figure out difference
    // to print  difference
    printf("\nVerification of row-major order by element differences within rows:\n");
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            int diff = array[i][j + 1] - array[i][j];
            printf("Difference between array[%d][%d] and array[%d][%d] = %d (expected 1)\n",i, j, i, j + 1, diff);
        }
    }

    // print adjacent difference to two lines
    printf("\nVerification of row-major order by element differences between rows:\n");
    for(int j = 0;j < 4;j++){
        int diff = array[1][j] - array[0][j];
        printf("Difference between array[1][%d] and array[0][%d] = %d (expected 4)\n",j, j, diff);
    }
    return 0;
}
