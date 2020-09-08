#include<unistd.h>
int main(void){
	for (int i = 0; i < 5; i++){
		fork();
	}
	sleep(5);
	return 0;
}


/* if cycle iterates 3 times, we have in summary 2^3 = 8 processes. each of them have two child processes (except last ones)
the same for 5 iterations: 2^5 = 32 processes in summary
*/