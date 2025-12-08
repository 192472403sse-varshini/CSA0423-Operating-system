#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, head;
    printf("Enter number of requests: "); scanf("%d",&n);
    int req[n], i;
    printf("Enter requests:\n");
    for(i=0;i<n;i++) scanf("%d",&req[i]);
    printf("Enter initial head position: "); scanf("%d",&head);

    int movement = 0;
    printf("Order served: ");
    for(i=0;i<n;i++){
        printf("%d ", req[i]);
        movement += abs(req[i] - head);
        head = req[i];
    }
    printf("\nTotal head movement = %d\n", movement);
    return 0;
}
