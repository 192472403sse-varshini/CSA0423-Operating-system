#include <stdio.h>
int main() {
    char files[3][20] = {"file1.txt", "file2.txt", "file3.txt"};

    printf("Single Level Directory:\n");
    for(int i = 0; i < 3; i++)
        printf("%s\n", files[i]);
    return 0;
}
