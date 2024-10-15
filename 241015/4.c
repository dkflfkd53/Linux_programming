#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void parent_handle(int);

int main() {
    pid_t pid;
    struct sigaction act;

    act.sa_handler = parent_handle;
    sigfillset(&(act.sa_mask));
    sigaction(SIGCHLD, &act, NULL);

    pid = fork();

    if (pid == 0) {
        printf("[child] I am a child\n");
        kill(getppid(), SIGCHLD);
    	printf("[child]bye~\n");
	}

    sleep(2);
    return 0;
}

void parent_handle(int sig) {
    printf("SIGCHLD: %d\n", sig);
    printf("[parent] Parent bye...\n");
}
