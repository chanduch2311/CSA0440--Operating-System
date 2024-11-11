#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

void fileOperations() {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    lseek(fd, 0, SEEK_END);
    struct stat fileStat;
    stat("test.txt", &fileStat);

    printf("File size: %ld bytes\n", fileStat.st_size);
    close(fd);
}

void directoryOperations() {
    DIR *dir = opendir(".");
    struct dirent *entry;

    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

int main() {
    fileOperations();
    directoryOperations();
    return 0;
}

