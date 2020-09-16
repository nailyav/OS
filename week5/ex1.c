#include <stdio.h>
#include <pthread.h>

int j = 1;
void *show_thread(void *vargp)
{
	sleep(1);
	printf("This is thread #%d\n", j);
	j++;
	return NULL;
}

int main(void){
	pthread_t thread;
	for (int i = 1; i <= 3; i++){
		printf("Thread #%d created\n", i);
		pthread_create(&thread, NULL, &show_thread, NULL);
		pthread_join(thread, NULL);
		printf("Exit thread #%d\n", i);
	}
	pthread_exit(NULL);

// pthread_join is used to wait for thread

	return 0;
}
