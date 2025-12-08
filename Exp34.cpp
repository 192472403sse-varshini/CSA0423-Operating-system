#include <stdio.h>
int main(){
    int totalBlocks, start, len, i;
    printf("Enter total disk blocks: "); scanf("%d",&totalBlocks);
    printf("Enter file start block and length: "); scanf("%d %d",&start,&len);

    if(start + len > totalBlocks){ printf("Allocation failed: out of disk\n"); return 0; }

    printf("Allocated blocks: ");
    for(i=start;i<start+len;i++) printf("%d ", i);
    printf("\n");

    // Simulate access to record k (0-based)
    int k;
    printf("Enter record index to access (0-based): "); scanf("%d",&k);
    if(k<0 || k>=len){ printf("Invalid record\n"); return 0; }

    printf("Reading records sequentially up to index %d:\n", k);
    for(i=0;i<=k;i++) printf("Read record at block %d\n", start + i);
    return 0;
}
