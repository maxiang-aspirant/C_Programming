#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for usleep
#define WIDTH 80
#define HEIGHT 24
#define FRAME_DELAY 100000 // 100ms
#define NUM_FRAMES 10
#define NUM_CHARS_PER_FRAME 1
typedef enum{
	COLOR_DEFAULT,
        COLOR_RED,
        COLOR_GREEN,
        COLOR_BLUE,
} Color;
typedef struct{
        char character;
        int x, y;
	Color color;
} Character;
typedef struct{
        Character* chars;
        int num_chars;
} Frame;
typedef struct{
        Frame* frames;
        int num_frames;
        int current_frame;
} Animation;
void init_animation(Animation* anim,int num_frames,int num_chars_per_frame){
        anim->num_frames = num_frames;
        anim->current_frame = 0;
        anim->frames = malloc(num_frames * sizeof(Frame));
	int i;
        for(i=0;i<num_frames;i++){
                anim->frames[i].num_chars = num_chars_per_frame;
                anim->frames[i].chars = malloc(num_chars_per_frame * sizeof(Character));
		anim->frames[i].chars[0].character = 'O';// to fill in the animation data
                anim->frames[i].chars[0].y = HEIGHT / 2;//level shift
                anim->frames[i].chars[0].x = i * (WIDTH / (num_frames - 1));
		anim->frames[i].chars[0].color = (Color)((i % 3) + COLOR_RED);// to set the color
        }
}
void clear_screen(){
        printf("\033[2J\033[H");
}
void draw_frame(Frame* frame){
        clear_screen();
	int i;
	const char*color_code;
	for(i=0;i<frame->num_chars;i++){
		Character* char_ptr = &frame->chars[i]; // Use a local pointer to access the character
	        switch (char_ptr->color){
                        case COLOR_RED:
                                color_code = "\033[31m";
                                break;
                        case COLOR_GREEN:
                                color_code = "\033[32m";
                                break;
                        case COLOR_BLUE:
                                color_code = "\033[34m";
                                break;
                        default:
                                color_code = "\033[0m";
	        }
	        printf("%s\033[%d;%dH%c\033[0m", color_code, char_ptr->y + 1, char_ptr->x + 1, char_ptr->character);
	}
        fflush(stdout); 
}
void play_animation(Animation* anim){
        while (1){ 
                draw_frame(&anim->frames[anim->current_frame]);
                usleep(FRAME_DELAY); 
                anim->current_frame = (anim->current_frame + 1) % anim->num_frames;
        }
}
void free_animation(Animation* anim){
	int i;
        for(i=0;i<anim->num_frames;i++){
                free(anim->frames[i].chars);
        }
        free(anim->frames);
}
int main(){
        Animation anim;
        init_animation(&anim,NUM_FRAMES,NUM_CHARS_PER_FRAME);
        play_animation(&anim);
        free_animation(&anim);
        return 0;
}
