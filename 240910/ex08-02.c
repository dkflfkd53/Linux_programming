#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	int status;

	pid = fork();

	if (pid > 0) {
		printf("parent: waiting..\n");
		wait(&status);
		printf("parent: status is %d\n", status >> 8);
	} else if(pid == 0) {
		sleep(3);
		printf("child: bye!\n");
		exit(2);
	} else {
		printf("fail to fork\n");

	}

	printf("bye!\n");
}
