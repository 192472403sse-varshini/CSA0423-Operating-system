#include <stdio.h>
int main() {
    int n, bt[20], p[20], wt[20], tat[20], i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        p[i] = i;
        printf("Burst time P%d: ", i+1);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(bt[j] < bt[i]){
                int t=bt[i]; bt[i]=bt[j]; bt[j]=t;
                t=p[i]; p[i]=p[j]; p[j]=t;
            }
    wt[0] = 0;
    for(i=1;i<n;i++) wt[i] = wt[i-1] + bt[i-1];
    for(i=0;i<n;i++) tat[i] = wt[i] + bt[i];

    printf("Process BT  WT  TAT\n");
    for(i=0;i<n;i++)
        printf("P%d      %d   %d   %d\n", p[i]+1, bt[i], wt[i], tat[i]);
}
