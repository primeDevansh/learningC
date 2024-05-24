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