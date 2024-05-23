/* 
 * Chapter 7 | The C Programming Language By Brian W. Kernighan and Dennis Ritchie
 * Page 152
 * Custom-devised Experiment No. 01
 *      To take input from a file instead of keyboard and print output to another file instead of monitor.
 *      Part 1: The program takes 5 numbers from infile and displays their sum on the monitor.
 * 
 * infile: infile_ch7pg152custExp01
 * outfile: outfile_ch7pg152custExp01
 * 
 * This file is without an extension. It is a PLAINTEXT
 * I fed it with 12345. It read each as character and outputted 49 for 1, 50 for 2 and so on. It even 
 * read 'enter' or '\n' as a character and outputtted 10 for each.
 * 
 * When I tried to output to another file using "./ch7pg152custExp01 <infile_ch7pg152custExp01 >outfile_ch7pg152custExp01"
 * it created a new file all by itself. And output to other file was successful using printf as well.
 * 
 * COPYING CONTENTS OF ONE FILE TO ANOTHER USING COMMAND LINE!
 */

#include <stdio.h>

// void error(int code) {
//     printf("\nError received. Error code: %d\n", code);
//     exit(1);
// }

int main() {
    int sum = 0;
    int ch;

    ch = getchar();
    while(ch != EOF) {
        putchar(ch);
        ch = getchar();
    }
    putchar(EOF);
    

    // while(1) {
    //     int k = getchar();
    //     if(k == 10) {   //EOF
    //         printf("Newline encountered!");
    //         continue;
    //     }
    //     if (k == EOF) {  //EOF
    //         printf("EOF encountered!");
    //         break;
    //     }
    //     printf("%d\n", k);
    //     sum += k;
    // }

    // printf("%d\n", sum);

    return 0;
}