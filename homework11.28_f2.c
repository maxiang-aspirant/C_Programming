#ifndef MODULE_H
#define MODULE_H
int function1();
int function2();
extern int global_variable;
#endif
#include <stdio.h>
#include "module.h"
int main(){
    int result1 = function1();
    printf("function1() returned: %d\n", result1);
    int result2 = function2();
    printf("function2() returned: %d\n", result2);
    printf("global_variable: %d\n", global_variable);
    return 0;
}
