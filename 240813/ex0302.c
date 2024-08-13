#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int filedes;
	char pathname[] = "temp.txt";

	if((filedes = open(pathname, O_CREAT | O_RDWR, 0644))==-1) {
		printf("file open error!");
		exit(1);
	}

	close(filedes);
}
