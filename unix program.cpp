#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (file == -1) {
        perror("Error opening file");
        return 1;
    }

    const char *text = "Hello, UNIX system calls!";
    write(file, text, sizeof(text));

    close(file);
    return 0;
}

