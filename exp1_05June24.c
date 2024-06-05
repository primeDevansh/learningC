/* Accessing a local variable from outside its scope
 * Refer README.md with the same title.
 */
#include <stdio.h>

int *myVar() {
    int localVar = 5;
    int localVar3 = 7;   //trying to take up space of localVar in the activation record.
    return &localVar;
}

int main() {
    int *notMyVar = myVar();
    int localVar2 = 3; //trying to take up space of localVar in the activation record.
    printf("Out of scope Var accessible: %d\n", *notMyVar);
    return 0;
}