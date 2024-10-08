#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            execlp("wc", "wc", argv[i], (char *)NULL);;
        }
    }

    return 0;
}

