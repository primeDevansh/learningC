/* 
 * Writing an integer-specific stack
 *      - Later on to be made generic
 */

typedef struct {
    int *elems;
    int logicalLen;
    int allocLen;
} stack;

void StackNew(stack *s);
void StackDispose(stack *s);
void StackPush(stack *s, int value);
int StackPop(stack *s);