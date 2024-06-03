#include <stdio.h>

struct no{
    int no;
};

// void init_no(no *p) {
//     p -> no = 0;
// }

int main() {
    struct no t;
    struct no *p = &t;
    p -> no = 10;
    printf("p -> no++ = %d, current value of no = %d\n", p -> no++, p -> no);
    printf("p -> no-- = %d, current value of no = %d\n", p -> no--, p -> no);
    //focus below! :-
    printf("--p -> no = %d, current value of no = %d\n", --p -> no, p -> no);
    printf("--(p -> no) = %d, current value of no = %d\n", --(p -> no), p -> no);
    return 0;
}