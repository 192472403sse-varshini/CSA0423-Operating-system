#include <stdio.h>
#include <dirent.h>
int main() {
    DIR *d = opendir(".");
    struct dirent *f;

    if(!d){ printf("Error"); return 0; }

    printf("Directory Files:\n");
    while((f = readdir(d)) != NULL)
        printf("%s\n", f->d_name);

    closedir(d);
}
