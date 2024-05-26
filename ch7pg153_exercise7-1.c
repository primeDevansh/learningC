#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Please specify instruction! Exit\n");
        exit(1);
    }

    int ch, ch1;
    if(strcmp(argv[1], "tolower") == 0) 
        ch1 = 1;
    else if(strcmp(argv[1], "toupper") == 0) 
        ch1 = 2;
    else {
        printf("Please check instruction provided!\n");
        exit(1);
    }

    while((ch = getchar()) != EOF) {
        switch(ch1) {
            case 1:
                putchar(tolower(ch));
                break;
            case 2:
                putchar(toupper(ch));
                break;
        }
    }

    return 0;
}