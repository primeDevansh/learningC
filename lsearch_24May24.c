#include <stdio.h>
#include <string.h>

void *lsearch(void *, void *, int, int, int (*)(void *, void *));
int StrCmp(void *, void *);
int IntCmp(void *, void *);

int main() {
    //for integer array LS
    // int arr[] = {5, 4, 3, 2, 1};
    // int key = 1;

    // int *elemAddr = lsearch(&key, arr, sizeof(arr) / sizeof(int), sizeof(int), IntCmp);

    // printf("Element %d found at address %p found!\n", *elemAddr, elemAddr);

    // return 0;

    //for character array linear search
    char *notes[] = {"Ab", "F#", "B", "Gb", "D"};
    char *key = "F#";

    char **elemAddr = lsearch(&key, notes, sizeof(notes) / sizeof(char *), sizeof(char *), StrCmp);

    printf("Element %s found!\n", *elemAddr);
    return 0;
}

void *lsearch(void *key, void *base, int n, int elemSize, int (*cmpfn)(void *, void *)) {
    for(int i = 0; i < n; i++) {
        void *elemAddr = (char *)base + i * elemSize;
        if(cmpfn(key, elemAddr) == 0)
            return elemAddr;
    }
    return NULL;
}

int StrCmp(void *elem1, void *elem2) {
    char *str1 = *(char **)elem1;
    char *str2 = *(char **)elem2;

    return strcmp(str1, str2);
}

int IntCmp(void *vp1, void *vp2) {
    int *ip1 = vp1;
    int *ip2 = vp2;
    
    return *ip1 - *ip2;
}

//VERSION 2
// #include <stdio.h>

// int lsearch(void *, void *, int, int);
// int my_memcmp(void *, void *, int);

// int main() {
//     int arr[] = {5, 4, 3, 2, 1};
//     int key = 2;
//     int pos = lsearch(&key, arr, sizeof(arr) / sizeof(int), sizeof(int));
//     printf("Element found at position: %d\n\n", pos);
//     return 0;
// }

// int lsearch(void *key, void *base, int n, int elemSize) {
//     for(int i = 0; i < n; i++) {
//         void *elemAddr = (char*)base + i * elemSize;
//         if(my_memcmp(key, elemAddr, elemSize) == 0)
//             return i + 1;
//     }
//     return -1;
// }

// int my_memcmp(void *elem1, void *elem2, int bytes) {
//     // char *e1 = (char *)elem1;
//     // char *e2 = (char *)elem2;

//     //what about removing the cast to char* !? Lecture 5 - SUCS107, My Notes Pg 3
//     char *e1 = elem1;
//     char *e2 = elem2;

//     while(bytes--) {
//         if(*e1++ != *e2++)
//             return -1;
//     }
//     return 0;
// }


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