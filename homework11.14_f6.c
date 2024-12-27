#include<stdio.h>
int two_dim_array_access(int *x,int i,int j,int m,int n,int C){

	int off_set1 =i*C+j;//to figure out difference about original element
       	int off_set2 =m*C+n;//to figure out objective` of  difference
	return *(x+(off_set2-off_set1));
}
int main(){
	int A[2][3] = {{1,2,3},{4,5,6}};
	int result1,result2;
	result1 = two_dim_array_access(&A[0][0],0,0,1,2,3);
	result2 = two_dim_array_access(&A[0][1],0,1,1,2,3);
	printf("%d\n",result1);
	printf("%d\n",result2);
	return 0;
}
