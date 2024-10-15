#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
	sigset_t set1, set2;
	int count = 5;

	sigemptyset(&set1);
	sigemptyset(&set2);
	
	sigaddset(&set1, SIGABRT);
	sigaddset(&set1, SIGALRM);
   	sigaddset(&set1, SIGBUS);
    	sigaddset(&set1, SIGCHLD);
    	sigaddset(&set1, SIGCONT);
    	sigaddset(&set1, SIGFPE);
    	sigaddset(&set1, SIGHUP);
    	sigaddset(&set1, SIGILL);
    	sigaddset(&set1, SIGINT);
    	sigaddset(&set1, SIGKILL);
    	sigaddset(&set1, SIGPIPE);
    	sigaddset(&set1, SIGQUIT);
    	sigaddset(&set1, SIGSEGV);
    	sigaddset(&set1, SIGSTOP);
    	sigaddset(&set1, SIGSYS);
    	sigaddset(&set1, SIGTERM);

	sigaddset(&set2, SIGINT);

	sigprocmask(SIG_BLOCK, &set1, NULL);

	while(count) {
		printf("don't disturb me");
		count--;
		sleep(1);
	}
	
	printf("disturb me");	
	sigprocmask(SIG_UNBLOCK, &set2, NULL);
}
