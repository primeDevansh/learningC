#include <stdio.h>

int main(int argc, char* argv[]) {
    // for(int i = 0; i < argc; i++) {
    //     printf("%s%s", argv[i], (i < argc - 1) ? " " : "\n");
    // }
    // printf("\n");

    while(--argc > 0) {
        printf("%s%s", *++argv, (argc > 1) ? " " : "\n");
    }
    return 0;
}