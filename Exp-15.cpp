#include <stdio.h>
int main() {
    char user1[][20] = {"a.txt", "b.txt"};
    char user2[][20] = {"c.txt", "d.txt"};
    printf("User1 files:\n");
    for(int i = 0; i < 2; i++)
        printf("%s\n", user1[i]);
    printf("User2 files:\n");
    for(int i = 0; i < 2; i++)
        printf("%s\n", user2[i]);

    return 0;
}
