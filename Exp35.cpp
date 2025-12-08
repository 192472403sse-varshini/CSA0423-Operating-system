#include <stdio.h>
int main(){
    int nBlocks, idxBlock, n;
    printf("Enter total disk blocks: "); scanf("%d",&nBlocks);
    printf("Enter index block number: "); scanf("%d",&idxBlock);
    printf("Enter number of file blocks: "); scanf("%d",&n);
    int list[n], i;
    printf("Enter block numbers for file:\n");
    for(i=0;i<n;i++) scanf("%d",&list[i]);

    printf("Index Block %d points to: ", idxBlock);
    for(i=0;i<n;i++) printf("%d ", list[i]);
    printf("\nAccessing ith block example: Enter i (0-based): ");
    int k; scanf("%d",&k);
    if(k<0 || k>=n) printf("Invalid\n"); else printf("Block for i=%d is %d\n", k, list[k]);
    return 0;
}
