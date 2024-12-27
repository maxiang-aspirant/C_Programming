#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool is_prime(int num);
int main(){
        int x;
        printf("请输入一个比较大的正数x：");
	if (scanf("%d", &x) != 1 || x <= 0){
                printf("输入无效，请输入一个正整数。\n");
                return 1;
        }
        printf("范围 [1, %d] 内的所有素数为：\n", x);
        for (int i = 2; i <= x; i++){
                if (is_prime(i))
                        printf("%d ", i);
        }
        printf("\n");
        return 0;
}
bool is_prime(int num){
        if (num <= 1)
                return false;
        for (int i = 2; i <= sqrt(num); i++){
                if (num % i == 0)
                        return false;
        }
        return true;
}
