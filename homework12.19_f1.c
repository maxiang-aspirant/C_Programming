#include <stdio.h>
#include <time.h>
#define LED_WIDTH 8   // the width of the LED
#define LED_HEIGHT 8  // the height of the LED
// to define the LED matrix
unsigned char led_matrix[LED_WIDTH][LED_HEIGHT] = {0};
void set_led(int row, int col, int state) {
        led_matrix[row][col] = state;  // make the LED in set condition and 1 represents light and 0 represents dark
}
void clear_screen(){
	int i,j;
        for(i=0;i<LED_HEIGHT;i++){
                for(j=0;j<LED_WIDTH;j++){
                        led_matrix[i][j] = 0;
                }
        }  
}
void show_matrix(){
	int i,j;
        for(i=0;i<LED_HEIGHT;i++){
                for(j=0;j<LED_WIDTH;j++){
                        printf("%d ", led_matrix[i][j]);
                }
                printf("\n");
        }
}
void delay_ms(int ms){
	clock_t start_time = clock();
	while(clock() - start_time < ms * CLOCKS_PER_SEC / 1000.0);
}
int main(){
	int i;
        clear_screen();	
        for(i=0; ;i++){
                set_led(3, i % LED_WIDTH, 1);  
                show_matrix();
                delay_ms(500);  
                set_led(3, i % LED_WIDTH, 0);  
                delay_ms(500);  
		char c = getchar();
		if(c == 'q'||c == 'Q')
			break;
        }
        return 0;
}
