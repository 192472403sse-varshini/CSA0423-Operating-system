#include <stdio.h>
#include <string.h>
int main() {
    char word[20], line[100];
    printf("Enter search word: ");
    scanf("%s", word);

    FILE *fp = fopen("input.txt", "r");
    if(!fp){ printf("File not found"); return 0; }

    printf("Matching Lines:\n");
    while(fgets(line, sizeof(line), fp))
        if(strstr(line, word))
            printf("%s", line);

    fclose(fp);
}
