#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char ch;
    int count = 0;

    file = fopen("alphabet.txt", "r");
    if (file == NULL) {
        perror("파일을 열 수 없습니다.");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            count++;
        }
    }

    fclose(file);

    printf("알파벳 개수: %d\n", count);

    return 0;
}
