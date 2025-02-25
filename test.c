#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    printf("Hello World!\n");

    DIR *dir_stream;

    struct dirent *dir_read;

    dir_stream = opendir(argv[1]);

    if (dir_stream == NULL) {
        perror("Error while trying to open directory \n");
        return 1;
    }

    while ((dir_read = readdir(dir_stream)) != NULL) {
        printf("%s\t%d bytes\n", dir_read->d_name, dir_read->d_reclen);
    }

    if (closedir(dir_stream) == -1) {
        perror("KO");
        return -1;
    }

    return 0;
}