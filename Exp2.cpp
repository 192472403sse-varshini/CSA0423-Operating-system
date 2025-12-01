#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int s = open("source.txt", O_RDONLY);
    if (s < 0) {
        perror("Error opening source.txt");
        return 1;
    }
    int d = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (d < 0) {
        perror("Error opening copy.txt");
        close(s);
        return 1;
    }
    char buf[1024];
    ssize_t n;
    while ((n = read(s, buf, sizeof(buf))) > 0) {
        write(d, buf, n);
    }
    close(s);
    close(d);
    printf("Copied successfully\n");
    return 0;
}


