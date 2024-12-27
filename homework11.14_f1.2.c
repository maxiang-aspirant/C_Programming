#include<stdio.h>
void bubble_sort(int arr[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				int tmp = arr[j];
				// use tmp to exchange element and store up value
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
                        }
                }   
        }   
}
int main(){
	int i;
	int arr[] = {11,17,20,68,25,89};
	int n = sizeof(arr)/sizeof(arr[0]);
        // to figure out elements'numbers of an array by bites
	printf("Sorted array:\n");
	bubble_sort(arr,n);
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);// use "for" to traverse an array and print
        }
        return 0;
}
