#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

void signal_handler(int signum) {
    int fd = open("message.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    
    const char *message = "프로그램이 SIGINT 신호로 종료되었습니다.\n";
    write(fd, message, sizeof(char) * 36);
    close(fd);
    
    printf("SIGINT 신호를 받았으며, 종료 메시지를 파일에 기록했습니다.\n");
    
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction 오류");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("프로그램 실행 중... Ctrl + C로 종료하세요.\n");
        sleep(1);
    }

    return 0;
}

