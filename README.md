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