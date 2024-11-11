#include <stdio.h>
#include <string.h>

void grep(const char *filename, const char *pattern) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);
}

int main() {
    char filename[] = "example.txt";
    char pattern[] = "search_term";
    grep(filename, pattern);
    return 0;
}

