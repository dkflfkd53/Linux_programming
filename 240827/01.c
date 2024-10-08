#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int main() {
    int n;
    printf("양의 정수 입력: ");
    scanf("%d", &n);

    pid_t pid = fork();
 
    if (pid == 0) {
        int product = 1;
        for (int i = 1; i <= n; i++) {
            product *= i;
        }
        printf("곱: %d\n", product);
    } 
    else if(pid > 0) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        printf("합: %d\n", sum);
        wait(NULL);
    }

    return 0;
}

