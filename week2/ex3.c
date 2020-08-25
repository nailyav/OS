#include <stdio.h>
#include <stdlib.h>

void print(int line, int n){
    int before = (n - line - 1);
    for (int i = 0; i < before; i++)
        printf(" ");
    printf("*");
    for (int i = 0; i < line * 2; i++)
        printf("*");
    printf("\n");
}

int main(int argc, char const *argv[]) {
    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++){
        print(i, n);
    }
    return 0;
}
