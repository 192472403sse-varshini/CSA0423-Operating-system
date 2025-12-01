#include <stdio.h>
#include <limits.h>
int main(){
    int n; scanf("%d",&n);
    int at[n], bt[n], rt[n];
    for(int i=0;i<n;i++){ scanf("%d %d",&at[i], &bt[i]); rt[i]=bt[i]; }
    int done=0, time=0, wt[n];
    for(int i=0;i<n;i++) wt[i]=0;
    while(done < n){
        int idx=-1, best=INT_MAX;
        for(int i=0;i<n;i++) if(at[i]<=time && rt[i]>0 && rt[i]<best){ best=rt[i]; idx=i; }
        if(idx==-1){ time++; continue; }
        time += rt[idx]; rt[idx]=0; done++;
        wt[idx] = time - at[idx] - bt[idx];
    }
    for(int i=0;i<n;i++) printf("P%d WT=%d TAT=%d\n", i+1, wt[i], wt[i]+bt[i]);
    return 0;
}
