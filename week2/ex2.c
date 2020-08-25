#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    printf("Enter a string:\n");
    scanf("%s", &string);
    for (int i = strlen(string) - 1; i > -1; i--){
        printf("%c", string[i]);
    }
    return 0;
}
