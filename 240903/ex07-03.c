#include <unistd.h>
#include <stdio.h>

int main() {
	printf("beford executing ls-l\n");
	execl("/bin/ls", "ls", "-l", (char *)0);
	printf("after executing ls -l\n");
}
