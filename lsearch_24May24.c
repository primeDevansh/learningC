#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* lsearch(void*, void*, int, int);

int main(int argc, char* argv[]) {
    //for int array
    int arr[] = {10, 20, 30, 40, 50};
    int key = atoi(argv[1]);
    int* pos = lsearch(&key, arr, (sizeof(arr) / sizeof(int)), sizeof(int));

    printf("Element %d found at position %d\n", key, *pos);

    return 0;
}

void* lsearch(void* key, void* base, int n, int elemSize) {
    for(int i = 0; i < n; i++) {
        void* elemAddr = (char*)base + i * elemSize;
        if(memcmp(key, elemAddr, elemSize) == 0) {
            return elemAddr;
        }
    }
    return NULL;
}