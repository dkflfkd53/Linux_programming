#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int x, y;
	pid_t pid;
	int status;

	scanf("%d %d", &x, &y);

	pid = fork();

	if(pid > 1) {
		int pow = 1;
		for(int i=0;i<y;i++) {
			pow *= x;
		}
		printf("parent: pow = %d\n", pow);
		
		printf("parent: waiting..\n");
		wait(&status);

		printf("parent: %d\n", (status >> 8) + pow);
	} else if(pid == 0) {
		int sum = 0;
		for (int i=x;i<=y;i++) {
			sum += i;
		}
		printf("child: sum = %d\n", sum);
		exit(sum);
	} else {
		printf("fail to fork\n");
	}
}
