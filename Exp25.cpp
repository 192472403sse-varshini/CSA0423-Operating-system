#include <stdio.h>
#include <dirent.h>
int main() {
    char path[20];
    printf("Enter directory name: ");
    scanf("%s", path);

    DIR *d = opendir(path);
    if(!d) { printf("Cannot open directory\n"); return 0; }

    struct dirent *f;
    printf("Files:\n");
    while((f = readdir(d)) != NULL)
        printf("%s\n", f->d_name);

    closedir(d);
    return 0;
}
