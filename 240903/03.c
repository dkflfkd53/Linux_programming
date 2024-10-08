#include <unistd.h>

int main() {
    execl("/usr/bin/head", "head", "a.txt", "b.txt", "c.txt", (char *)NULL);
    execlp("head", "head", "a.txt", "b.txt", "c.txt", (char *)NULL);

    execv("/usr/bin/head", (char *[]){"head", "a.txt", "b.txt", "c.txt", NULL});

    execvp("head", (char *[]){"head", "a.txt", "b.txt", "c.txt", NULL});

    return 0;
}

