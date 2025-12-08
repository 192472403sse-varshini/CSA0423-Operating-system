#include <stdio.h>
void printPerm(int val){
    printf("%c", (val & 4) ? 'r' : '-');
    printf("%c", (val & 2) ? 'w' : '-');
    printf("%c", (val & 1) ? 'x' : '-');
}
int main(){
    int mode;
    printf("Enter file mode (octal) e.g. 754: ");
    scanf("%o", &mode); // read as octal

    int u = (mode >> 6) & 7;
    int g = (mode >> 3) & 7;
    int o = mode & 7;

    printf("Owner: "); printPerm(u); printf("\n");
    printf("Group: "); printPerm(g); printf("\n");
    printf("Others: "); printPerm(o); printf("\n");

    printf("\nUser types explained:\nOwner - file creator\nGroup - users in same group\nOthers - everyone else\n");
    return 0;
}
