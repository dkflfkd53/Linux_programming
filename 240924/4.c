#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	pid_t pid = fork();

	if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

	if (setsid() < 0) {
        perror("setsid failed");
        exit(EXIT_FAILURE);
    }

	int fd = open("/dev/null", O_RDWR);

	while (1) {
        time_t now = time(NULL);
        char buffer[100];
        struct tm *tm_info = localtime(&now);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);

        FILE *file = fopen("curtime.txt", "a");
        if (file == NULL) {
            exit(EXIT_FAILURE);
        }
        fprintf(file, "%s\n", buffer);
        fclose(file);

        sleep(10);
    }
}
