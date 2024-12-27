#include <stdio.h>
const char* bit_names[] = {"eighth", "seventh", "sixth", "fifth", "fourth", "third", "second", "first"};
int main(){
        char input_char;
        printf("请输入一个字符：");
        scanf("%c", &input_char);
        unsigned char byte = (unsigned char)input_char;
        for (int i = 7; i >= 0; i--){
                int bit_value = (byte >> i) & 1;
                printf("The %s bit is %d\n", bit_names[7 - i], bit_value);
        }
        return 0;
}
