#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[100] = "alphabet.txt";
    char ch;

    file = fopen(filename, *argv);
    if (file == NULL) {
        perror("파일을 열 수 없습니다.");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (islower(ch)) {
            long pos = ftell(file);
            fseek(file, pos - 1, SEEK_SET);
            fputc(toupper(ch), file);
            fseek(file, pos, SEEK_SET);
        }
    }

  
    fclose(file);

    printf("변환이 완료되었습니다. '%s' 파일이 수정되었습니다.\n", filename);

    return 0;
}

