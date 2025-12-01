#include <stdio.h>
int main(){
    int n,q; scanf("%d %d",&n,&q);
    int bt[n], rt[n];
    for(int i=0;i<n;i++){ scanf("%d",&bt[i]); rt[i]=bt[i]; }
    int time=0, done=0, wt[n];
    for(int i=0;i<n;i++) wt[i]=0;
    while(done < n){
        int progress = 0;
        for(int i=0;i<n;i++){
            if(rt[i] > 0){
                progress = 1;
                int t = rt[i] < q ? rt[i] : q;
                rt[i] -= t; time += t;
                if(rt[i] == 0){ done++; wt[i] = time - bt[i]; }
            }
        }
        if(!progress) break;
    }
    for(int i=0;i<n;i++) printf("P%d WT=%d TAT=%d\n", i+1, wt[i], wt[i]+bt[i]);
    return 0;
}
