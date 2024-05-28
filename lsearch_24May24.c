#include <stdio.h>

int lsearch(void *, void *, int, int);
int my_memcmp(void *, void *, int);

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int key = 7;
    int pos = lsearch(&key, arr, sizeof(arr) / sizeof(int), sizeof(int));
    printf("Element found at position: %d\n\n", pos);
    return 0;
}

int lsearch(void *key, void *base, int n, int elemSize) {
    for(int i = 0; i < n; i++) {
        void *elemAddr = (char*)base + i * elemSize;
        if(my_memcmp(key, elemAddr, elemSize) == 0)
            return i + 1;
    }
    return -1;
}

int my_memcmp(void *elem1, void *elem2, int bytes) {
    char *e1 = (char *)elem1;
    char *e2 = (char *)elem2;

    while(bytes--) {
        if(*e1++ != *e2++)
            return -1;
    }
    return 0;
}


//VERSION 1
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void* lsearch(void*, void*, int, int);

// int main(int argc, char* argv[]) {
//     //for int array
//     int arr[] = {10, 20, 30, 40, 50};
//     int key = atoi(argv[1]);
//     int* elemAddr = lsearch(&key, arr, (sizeof(arr) / sizeof(int)), sizeof(int));

//     //calculate position
//     // int pos = (arr - elemAddr) / sizeof(int);

//     // printf("%d %d \n", &arr[0], &arr[4]);

//     printf("Element %d found at position %d\n", key, 1);

//     return 0;
// }

// void* lsearch(void* key, void* base, int n, int elemSize) {
//     for(int i = 0; i < n; i++) {
//         void* elemAddr = (char*)base + i * elemSize;
//         if(memcmp(key, elemAddr, elemSize) == 0) {
//             return elemAddr;
//         }
//     }
//     return NULL;
// }