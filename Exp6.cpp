#include <stdio.h>
int main() {
    int n, bt[20], pr[20], rt[20], time = 0, count = 0, smallest;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Burst time P%d: ", i+1); scanf("%d",&bt[i]);
        printf("Priority  P%d: ", i+1); scanf("%d",&pr[i]);
        rt[i] = bt[i];
    }
    pr[19] = 9999; 
    while(count != n){
        smallest = 19;
        for(int i=0;i<n;i++)
            if(pr[i] < pr[smallest] && rt[i] > 0)
                smallest = i;
        rt[smallest]--;
        if(rt[smallest] == 0) count++;

        time++;
    }
    printf("Preemptive Priority Scheduling Completed.");
}


