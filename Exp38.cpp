#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, head, disk_size = 199, i, j;
    printf("Enter number of requests: "); scanf("%d",&n);
    int req[n];
    printf("Enter requests:\n");
    for(i=0;i<n;i++) scanf("%d",&req[i]);
    printf("Enter head pos: "); scanf("%d",&head);

    // sort requests
    for(i=0;i<n;i++) for(j=i+1;j<n;j++) if(req[i]>req[j]){ int t=req[i]; req[i]=req[j]; req[j]=t; }

    int pos=0;
    while(pos<n && req[pos] < head) pos++;

    int movement=0, cur=head;
    printf("Service order: ");
    for(i=pos;i<n;i++){ printf("%d ", req[i]); movement += abs(req[i]-cur); cur=req[i]; }
    // go to end
    movement += abs(disk_size - 1 - cur);
    cur = disk_size - 1;
    for(i=pos-1;i>=0;i--){ printf("%d ", req[i]); movement += abs(req[i]-cur); cur=req[i]; }

    printf("\nTotal head movement = %d\n", movement);
    return 0;
}
