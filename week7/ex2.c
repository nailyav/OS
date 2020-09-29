#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter the number of elements:");
    int n;
    scanf("%d", &n);
    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        array[i] = i;
    }

    printf("The array:\n");
    for (int i = 0; i < n; i++){
        printf("%d\n", array[i]);
    }
    free(array);
}
