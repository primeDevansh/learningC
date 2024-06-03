/*
 * Program to copy Input to Output (I to O)
 */

// #include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>  //for BUFSIZE

#undef BUFSIZ
#define BUFSIZ 1

int main() {
    char buf[BUFSIZ];
    int n;

    printf("%d\n", BUFSIZ);
    while((n = read(0, buf, BUFSIZ)) > 0) {
        write(1, buf, n);
    }
    return 0;
}
