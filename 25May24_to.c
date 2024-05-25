#include <stdio.h>

int main() {
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        // int t = getchar();
        sum += getchar();
    }
    printf("Sum of Numbers Received Is: %d\n", sum);
    return 0;
}