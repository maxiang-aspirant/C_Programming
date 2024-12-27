#include <stdio.h>
void print_word(char input){
	//define a function to print patterns about every letter
	switch(input){
		case 'A':
			printf("   *   \n");
			printf("  * *  \n");
			printf(" ***** \n");
			printf("*     *\n");
			break;
	        case 'B':
			printf("******\n");
			printf("*    *\n");
			printf("******\n");
			printf("*    *\n");
			printf("******\n");
			break;
		case 'C':
			printf("******\n");
			printf("*     \n");
			printf("*     \n");
			printf("*     \n");
			printf("******\n");
			break;
		case 'D':
			printf("******\n");
			printf("*    *\n");
			printf("*    *\n");
			printf("*    *\n");
			printf("******\n");
			break;
		case 'E':
			printf("******\n");
			printf("*     \n");
			printf("******\n");
			printf("*     \n");
			printf("******\n");
			break;
		}
}
int main(){
	char input[5];
	int i;
	scanf("%4s",input);
	printf("Letters:\n");
	for(i=0;i<5;i++){
		print_word(input[i]);
	        printf("\n");
	}
	return 0;
}

