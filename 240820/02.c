#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char **argv) {
    DIR *dirp;
    struct dirent *dentry;
    int file_count = 0;
    int dir_count = 0;

    if ((dirp = opendir(argv[1])) == NULL) {
        perror("디렉터리 열기 실패");
        exit(1);
    }

    while ((dentry = readdir(dirp))) {
        if (dentry->d_ino != 0) {
            if (dentry->d_type == DT_DIR) {
                dir_count++;
            } else if (dentry->d_type == DT_REG) {
                file_count++;
            }
            printf("%s\n", dentry->d_name);
        }
    }

    closedir(dirp);

    printf("파일 개수: %d\n", file_count);
    printf("하위 디렉터리 개수: %d\n", dir_count);

    return 0;
}

