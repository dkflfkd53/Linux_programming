#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file1 [file2 ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
            return 1;
        } else if (pid == 0) {
            execlp("wc", "wc", argv[i], (char *)NULL);
            perror("execlp failed");
            return 1;
        }
    }

    for (int i = 1; i < argc; i++) {
        wait(NULL);
    }

    return 0;
}

