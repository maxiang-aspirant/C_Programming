#include <stdio.h>
#include <stdlib.h>
void print_char_A();
void print_char_E();
void print_char_F();
void print_char_pattern(char input);
int main() {
        char input;
        printf("请输入一个大写英文字符（A, E, F之一）：");
        scanf(" %c", &input);
        switch (input) {
            case 'A':
                print_char_A();
                break;
            case 'E':
                print_char_E();
                break;
            case 'F':
                print_char_F();
                break;
            default:
                printf("不支持的字符！\n");
                break;
        }
        return 0;
}
void print_char_A() {
        printf("  **  \n");
        printf(" *  * \n");
        printf("**  **\n");
        printf("*******\n");
        printf("*     *\n");
        printf("*     *\n");
}
void print_char_E() {
        printf("*******\n");
        printf("*      \n");
        printf("*      \n");
        printf("*******\n");
        printf("*      \n");
        printf("*      \n");
        printf("*******\n");
}
void print_char_F() {
        printf("*******\n");
        printf("*      \n");
        printf("*      \n");
        printf("*******\n");
        printf("*      \n");
        printf("*      \n");
}
