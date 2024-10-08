#include <stdio.h>
#include <sys/types.h>

main() {
	pid_t pid1, pid2;
	int num = 0;

	pid1 = fork();
	if(pid1 > 0)
		pid2 = fork();

	if(pid1 > 0 && pid2 < 0) {
		sleep(1);
		num++;
		printf("%d\n", num);
	}
	else if(pid1 == 0 || pid2 == 0) {
		num = num + 2;
		printf("%d\n", num);
	}

	return 0;
}
