#include <stdio.h>
#include <limits.h>
int main(){
    int n, frames, i,j,k;
    printf("Enter number of pages: "); scanf("%d",&n);
    int pages[n]; printf("Enter pages:\n");
    for(i=0;i<n;i++) scanf("%d",&pages[i]);
    printf("Enter number of frames: "); scanf("%d",&frames);

    int frame[frames]; for(i=0;i<frames;i++) frame[i]=-1;
    int faults=0;

    for(i=0;i<n;i++){
        int hit=0;
        for(j=0;j<frames;j++) if(frame[j]==pages[i]) hit=1;
        if(!hit){
            // find replacement
            int pos=-1, far=-1;
            for(j=0;j<frames;j++){
                if(frame[j]==-1){ pos=j; break; }
                int nextpos = n;
                for(k=i+1;k<n;k++) if(pages[k]==frame[j]) { nextpos=k; break; }
                if(nextpos > far){ far = nextpos; pos=j; }
            }
            frame[pos]=pages[i];
            faults++;
        }
        for(j=0;j<frames;j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Total page faults = %d\n", faults);
    return 0;
}
