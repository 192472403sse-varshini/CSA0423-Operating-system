#include <stdio.h>
#include <limits.h>
int main(){
    int n, frames, i,j;
    printf("Enter number of pages: "); scanf("%d",&n);
    int pages[n]; printf("Enter pages:\n");
    for(i=0;i<n;i++) scanf("%d",&pages[i]);
    printf("Enter number of frames: "); scanf("%d",&frames);

    int frame[frames], used[frames];
    for(i=0;i<frames;i++){ frame[i]=-1; used[i]=0; }
    int time=0, faults=0;

    for(i=0;i<n;i++){
        time++;
        int hit=-1;
        for(j=0;j<frames;j++) if(frame[j]==pages[i]) { hit=j; break; }
        if(hit!=-1){
            used[hit]=time;
        } else {
            int idx=-1, min=INT_MAX;
            for(j=0;j<frames;j++){
                if(frame[j]==-1){ idx=j; break; }
                if(used[j]<min){ min=used[j]; idx=j; }
            }
            frame[idx]=pages[i]; used[idx]=time; faults++;
        }
        for(j=0;j<frames;j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Total page faults = %d\n", faults);
    return 0;
}
