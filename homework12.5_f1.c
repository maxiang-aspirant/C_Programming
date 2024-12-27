#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h> //to use function usleep()
#define Height 24
#define Width 200
#define Rain_count 1500
typedef struct{
	int x;
	int y;
	int speed;
	char display_char;
}Rain;
int main(){
	int i;
	srand(time(NULL));
	Rain rain[Rain_count];
	for(i=0;i<Rain_count;i++){
		rain[i].x = rand()%Width;
		rain[i].y = rand()%Height;
		rain[i].speed = rand()%6+3;
		rain[i].display_char = 32+rand()%95;
	}
	while(1){  //to keep showing
		printf("\033[2J");  // to clear screen
		for(i=0;i<Rain_count;i++){
		        printf("\033[%d;%dH",rain[i].x,rain[i].y); 
			//to move the cursor
                        printf("\033[32m%c\033[0m",rain[i].display_char);
			// to print character 'rain' and set to green
                        rain[i].y += rain[i].speed;
                        if(rain[i].y>=Height){
                                rain[i].y = 0;
                                rain[i].x = rand()%Width;
			}
		}
		fflush(stdout);
		usleep(100000);
	}
	return 0;
}


