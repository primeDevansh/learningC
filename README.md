# learningC
Let's explore and experiment with low-level 'C' stuff.

### ch7pg152custExp01.c - 23 May 2024

Description: Take input from infile and give output to outfile. All through command line.

```console
./ch7pg152custExp01 <infile_ch7pg152custExp01 >outfile_ch7pg152custExp01
```

### Generic Swap Function - 24 May 2024

Description: A swap function to swap any **type**. [swap_24May24.c](./swap_24May24.c)

NOTE:

```C
#include <stdio.h>

int main() {
    printf("%d\n", sizeof(int));
    return 0;
}
```

Console:

![sizeof returns unisgned long](./Screenshot%202024-05-24%20at%2011.20.19%20AM.png)

NOTE:

![memcpy](./Screenshot%202024-05-24%20at%2011.31.35%20AM.png)

BINGO!!!!

```C
void my_memcpy(void* dest, const void* src, unsigned long bytes) {
    char* t1 = (char*)dest;
    char* t2 = (char*)src;
    for(int i = 0; i < bytes; i++) {
        t1[i] = t2[i];
    }
}
```

MY GENERIC SWAP!!!!

```C
#include <stdio.h>
// #include <string.h>

void swap(void*, void*, long);
void my_memcpy(void*, const void*, unsigned long);

int main() {
    // int x = 5, y = 7;
    float x = 5.35, y = 7.12;
    printf("Before Swap: x = %f, y = %f\n", x, y);
    // printf("\n%d\n", (&x)[-1]);
    swap(&x, &y, sizeof(int));
    printf("After Swap: x = %f, y = %f\n", x, y);
    return 0;
}

void swap(void* vp1, void* vp2, long size) {
    char buffer[size];
    my_memcpy(buffer, vp1, size);
    my_memcpy(vp1, vp2, size);
    my_memcpy(vp2, buffer, size);
}

void my_memcpy(void* dest, const void* src, unsigned long bytes) {
    char* t1 = (char*)dest;
    char* t2 = (char*)src;
    for(int i = 0; i < bytes; i++) {
        *(t1 + i) = t2[i];
    }
}
```

### Command-Line Input Redirection From 25May24_from.c to 25May24_to.c

In this experiment we will try and redirect standard output of former program into the standard input of latter. 

Let first program give 10 integers, second program will receive them and print their sum.

That's how to do it:

```console
./25May24_from | ./25May24_to
```

### ch7pg153_exercise7-1.c

To write a program that converts upper case to lower or lower to upper, depending on the name it is invoked with, as found in argv[0].

### Implicit pointer cast

from lsearch_24May24.c
```C
int my_memcmp(void *elem1, void *elem2, int bytes) {
    // char *e1 = (char *)elem1;
    // char *e2 = (char *)elem2;

    //what about removing the cast to char* !? Lecture 5, Su Notes Pg 3
    char *e1 = elem1;
    char *e2 = elem2;
```

### Accessing a local variable from outside its scope

Can we access a local variable by passing its address? Let's see: [code](./exp1_05June24.c).

```C
#include <stdio.h>

int *myVar() {
    int localVar = 5;
    return &localVar;
}

int main() {
    int *notMyVar = myVar();
    printf("Out of scope Var accessible: %d\n", *notMyVar);
    return 0;
}
```

Conclusion: Was able to access it; but don't know what'd happen if somehow the memory originally associcated with localVar gets used up by someone else after it is free'd up.

Here's the output:

![Output](./Screenshot%202024-06-05%20at%201.05.02%20PM.png)

Trying to take up original localVar's memory space by declaring more vars: -

```C
#include <stdio.h>

int *myVar() {
    int localVar = 5;
    int localVar3 = 7;   //trying to take up space of localVar in the activation record.
    return &localVar;
}

int main() {
    int *notMyVar = myVar();
    int localVar2 = 3; //trying to take up space of localVar in the activation record.
    printf("Out of scope Var accessible: %d\n", *notMyVar);
    return 0;
}
```

Output: - Unaffected!