#include <stdio.h>
#include <unistd.h>

int main () {
    setvbuf(stdout, NULL, _IOLBF, 1024);

    printf("H");
    sleep(1);

    printf("e");
    sleep(1);

    printf("l");
    sleep(1);

    printf("l");
    sleep(1);

    printf("o");
    sleep(1);

    return(0);
}
