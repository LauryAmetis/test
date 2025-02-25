#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    printf("Hello World!\n");

    DIR *dir_stream;

    // reading files froim current directory (name, size in bytes, etc)
    struct dirent *dir_read;
    // reading permissions on each files
    struct stat fileStat;    
    if(stat(argv[1], &fileStat) < 0) {
        return 1;
    }

    // reading the selected directory with argv[1]
    dir_stream = opendir(argv[1]);

    if (dir_stream == NULL) {
        perror("Error while trying to open directory \n");
        return 1;
    }
    printf("Information for %s\n", argv[1]);

    while ((dir_read = readdir(dir_stream)) != NULL) {
        printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
        printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
        printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
        printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (fileStat.st_mode & S_IXOTH) ? "x\t" : "-\t");
        printf("%s\t%d bytes\n", dir_read->d_name, dir_read->d_reclen);
    }

    if (closedir(dir_stream) == -1) {
        perror("KO");
        return -1;
    }

    return 0;
}