#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int check_directory_exists(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

int main(int argc, char **argv) {
    DIR *dirp;
    struct dirent *dentry;

    if (!check_directory_exists(argv[1])) {
        printf("지정된 경로가 존재하지 않거나 디렉터리가 아닙니다: %s\n", argv[1]);
        exit(1);
    } else {
        printf("지정된 경로는 존재하는 디렉터리입니다: %s\n", argv[1]);
    }

    if ((dirp = opendir(argv[1])) == NULL) {
        perror("디렉터리 열기 실패");
        exit(1);
    }

    while ((dentry = readdir(dirp))) {
        if (dentry->d_ino != 0) {
            printf("%s\n", dentry->d_name);
        }
    }

    closedir(dirp);

    return 0;
}

