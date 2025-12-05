#include <stdio.h>
int main() {
    int nb, np;
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    int b[nb];
    printf("Enter block sizes: ");
    for(int i=0;i<nb;i++) scanf("%d",&b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);
    int p[np];
    printf("Enter process sizes: ");
    for(int i=0;i<np;i++) scanf("%d",&p[i]);

    for(int i=0;i<np;i++) {
        int worst = -1;
        for(int j=0;j<nb;j++)
            if(b[j] >= p[i] && (worst == -1 || b[j] > b[worst]))
                worst = j;

        if(worst != -1) {
            printf("Process %d allocated to Block %d\n", i+1, worst+1);
            b[worst] -= p[i];
        } else printf("Process %d Not Allocated\n", i+1);
    }
}
