#include "stack.h"
#include <stdio.h>

int main() {
    stack stk;
    StackNew(&stk);
    for(int i = 0; i < 5; i++) {
        printf("Push Onto Stack: %d\n", i + 5);
        StackPush(&stk, i + 5);
    }
    for(int i = 0; i < 5; i++) {
        printf("Pop from stack: %d\n", StackPop(&stk));
    }
    return 0;
}