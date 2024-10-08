#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	printf("[ex08-06.c] PPID:%d, PID:%d\n", getppid(), getpid());
}
