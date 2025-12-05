#include <stdio.h>
int main() {
    int nb, np;
    printf("Enter number of blocks: ");
    scanf("%d",&nb);
    int b[nb];
    printf("Enter block sizes: ");
    for(int i=0;i<nb;i++) scanf("%d",&b[i]);

    printf("Enter number of processes: ");
    scanf("%d",&np);
    int p[np];
    printf("Enter process sizes: ");
    for(int i=0;i<np;i++) scanf("%d",&p[i]);

    for(int i=0;i<np;i++) {
        int allocated = 0;
        for(int j=0;j<nb;j++) {
            if(b[j] >= p[i]) {
                printf("Process %d allocated to Block %d\n", i+1, j+1);
                b[j] -= p[i];
                allocated = 1;
                break;
            }
        }
        if(!allocated)
            printf("Process %d Not Allocated\n", i+1);
    }
}
