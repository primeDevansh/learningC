#include <stdio.h>

int main() {
    char strv1[][5] = {"Devansh", "hii", "mjj"};
    char* strv2[3] = {"Devansh", "hii", "mjj"};

    for(int i = 0; i < 3; i++) {
        printf("%s\n", strv1[i]);
    }
    for(int i = 0; i < 3; i++) {
        printf("%s\n", strv2[i]);
    }
}