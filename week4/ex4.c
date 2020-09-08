#include<stdio.h>
#include<stdlib.h>

void read(char *command){
	fgets(command, 10, stdin);
};

int main(void){
	char command[100];
	while(1){
		printf("> ");
		read(command);
		system(command);
	}
}
