#include <stdio.h>
void select_sort(int arr[],int n){  //define function
	int i,min_idx,j,tmp;
	    for(i=0;i<n-1;i++){
		    min_idx = i;
	            for(j=i+1;j<n;j++){
			    if(arr[j]<arr[min_idx])
				    min_idx = j;
                    }
		    if(min_idx!=i){
			    tmp = arr[i];  //use a variable to  exchange store up value
		            arr[i] = arr[min_idx];
			    arr[min_idx] = tmp;
                    }
            }
}
int main(){
	int i;
	int arr[] = {65,56,88,12,17,11};
	int n = sizeof(arr)/sizeof(arr[0]);  //to figure out numbers of an  array
	printf("Sorted array:\n");
	select_sort(arr,n);
	for(i=0;i<n;i++)  //use "for" to traverse an array
		printf("%d\n",arr[i]);
}
		    
