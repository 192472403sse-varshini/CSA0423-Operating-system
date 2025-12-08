#include <stdio.h>
int main(){
    int n;
    printf("Enter number of blocks in file: "); scanf("%d",&n);
    int blocks[n], next[n];
    printf("Enter block numbers in order:\n");
    for(int i=0;i<n;i++) scanf("%d",&blocks[i]);
    // build next pointers
    for(int i=0;i<n-1;i++) next[i]=blocks[i+1];
    next[n-1] = -1;

    printf("Linked list of blocks:\n");
    for(int i=0;i<n;i++){
        printf("%d -> ", blocks[i]);
        if(next[i]==-1) printf("NULL\n"); else printf("%d\n", next[i]);
    }

    printf("Traverse file from first block:\n");
    int cur = blocks[0];
    int idx = 0;
    while(cur != -1){
        printf("Access block %d\n", cur);
        cur = (idx < n-1) ? blocks[++idx] : -1;
    }
    return 0;
}
