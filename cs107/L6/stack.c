#include "stack.h"
#include <stdlib.h>     //for using free(), malloc, realloc, NULL
#include <stdio.h>      //for printf()

void StackNew(stack *s) {
    s -> logicalLen = 0;
    s -> allocLen = 4;
    s -> elems = malloc(s -> allocLen * sizeof(int));
}

void StackDispose(stack *s) {
    free(s -> elems);
}

void StackPush(stack *s, int value) {
    if(s -> logicalLen == s -> allocLen) {
        s -> allocLen *= 2;
        int *copy_elems = s -> elems;
        s -> elems = realloc(s -> elems, s -> allocLen);
        if(s -> elems == NULL) {
            s -> elems = copy_elems;
            printf("StackPush() -> Cannot extend the stack this time.\n");
        }
    }
    s -> elems[(s -> logicalLen)++] = value;
}

int StackPop(stack *s) {
    assert(s -> logicalLen > 0);
    return s -> elems[--(s -> logicalLen)];
}