#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elemnts:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
