/*
 * To use custom definitions of getchar in customDefinitions.c
 */
#include "customDefinitions.c"

int main() {
    char ch = getchar();
    printf("Character received = %c\n", ch);
    return 0;
}