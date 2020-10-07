#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 10; i++){
        memset(malloc(10 * 1024 * 1024), 0, 10 * 1024 * 1024);
        sleep(1);
    }
    return 0;
}

/*
comments for ex2:
si increases, whilst so stays the same (so is 0)

comments for ex3:
Physical memory increases in 100M (it becomes 100M from 0M)
Virtual memory also increases in ~100M
*/
