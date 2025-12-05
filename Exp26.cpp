#include <stdio.h>
int main() {
    FILE *fp;
    char fname[20], text[50];

    printf("Enter file name: ");
    scanf("%s", fname);

    fp = fopen(fname, "w");
    printf("Enter content: ");
    scanf(" %[^\n]", text);
    fprintf(fp, "%s", text);
    fclose(fp);

    fp = fopen(fname, "r");
    fscanf(fp, "%[^\n]", text);
    printf("\nFile Read: %s\n", text);
    fclose(fp);
}
