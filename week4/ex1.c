#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid;
    pid = fork();
    int n = 10;
    for (int i = 0; i < n; ++i){
        if (pid > 0){
            printf("Hello from parent [%d - %d]\n", pid, i);
        }
        else if (pid == 0){
            printf("Hello from child [%d - %d]\n", pid, i);
        }
        else{
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }
}

/* calling fork() function we create a new process which is a child process. it runs consequently
with the parent process. that's why the program runs twice: for parent process and child one.
at first we have parent process running (that means pid is greater than 0, and we can see this in the output, and 
pid is the same at every stage of the cycle, because it relates to the same process).

then, after parent process stops running, child process starts. it's pid is equal to 0, and the next 10 lines 
we have this output:
    Hello from child [0 - i], where i = [0, 10)
*/