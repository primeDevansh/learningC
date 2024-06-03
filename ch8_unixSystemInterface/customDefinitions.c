#include <unistd.h>
#include <stdio.h>  //for EOF

#undef getchar

/*Unbuffered getchar*/
int getchar(void) {
    char c;
    return (read(0, &c, 1) > 0) ? (unsigned char) c : EOF;
}