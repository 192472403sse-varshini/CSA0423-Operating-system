#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    char fname[20], text[100];
    printf("Enter file name: ");
    scanf("%s", fname);

    int fd = open(fname, O_CREAT | O_WRONLY, 0644);
    if(fd < 0) { printf("Error opening\n"); return 0; }

    printf("Enter text to write: ");
    scanf(" %[^\n]", text);

    write(fd, text, strlen(text));
    close(fd);

    fd = open(fname, O_RDONLY);
    read(fd, text, sizeof(text));

    printf("\nFile Content: %s\n", text);
    close(fd);
}
