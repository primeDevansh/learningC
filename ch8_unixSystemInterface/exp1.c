/*Let's write EOF to 1(std output)*/
#include <unistd.h> //for read, write system calls
#include <stdio.h>  //for EOF

int main() {
    char ch[1] = {EOF};
    char *c = ch;
    int n_written = write(1, c, 1);
    printf("\nBytes requested = %d", BUFSIZ);
    printf("\nBytes written = %d\n", n_written);
    return 0;
}