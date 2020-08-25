#include <stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a, b;
    printf("Enter a first number:\n");
    scanf("%d", &a);

    printf("Enter a second number:\n");
    scanf(" %d", &b);

    printf("Before: %d", a);
    printf(" %d\n", b);

    swap(&a, &b);

    printf("After: %d", a);
    printf(" %d", b);
    return 0;
}