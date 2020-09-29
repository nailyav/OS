#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* myrealloc(int*, size_t);

int main() {
    printf("Enter the initial number of elements:");
    int n1;
    scanf("%d", &n1);
    int *ptr = malloc(n1 * sizeof(int));
    printf("The initial array:\n");
    for (int i = 0; i < n1; i++){
        ptr[i] = i;
        printf("%d ", ptr[i]);
    }

    printf("\nEnter new size of the array:");
    int n2;
    scanf("%d", &n2);
    ptr = myrealloc(ptr, n2 * sizeof(int));
    printf("The new array:\n");
    for (int i = 0; i < n2; i++){
        printf("%d ", ptr[i]);
    }
    return 0;
}

void* myrealloc(int *ptr, size_t size){
    if (ptr == NULL){
        ptr = malloc(size);
        return ptr;
    }
    if (size == 0) {
        free(ptr);
        return ptr;
    }

    void* temp;
    temp = malloc(size);
    memcpy(temp, ptr, size);
    free(ptr);
    return temp;
}
