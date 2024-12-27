#include <stdio.h>
#include <stdbool.h>
bool is_prime(int num);
int main(){
        int number;
        printf("请输入一个正数：");
        scanf("%d", &number);
        if (is_prime(number)) {
                printf("yes\n");
        } else {
                printf("no\n");
        }
        return 0;
}
bool is_prime(int num){
        if (num <= 1) {
                return false;
        }
        for (int i = 2; i * i <= num; i++) {
                if (num % i == 0)
                        return false;
        }
        return true;
}
