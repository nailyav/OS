#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    struct rusage *usage = malloc(sizeof(struct rusage));
    for (int i = 0; i < 10; i++) {
        memset(malloc(10 * 1024 * 1024), 0, 10 * 1024 * 1024);
        getrusage(RUSAGE_SELF, usage);
        printf("ru_maxrss = %ld\n", (*usage).ru_maxrss);

        sleep(1);
    }
    return 0;
}
