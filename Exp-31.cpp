#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, frames, i, j, k=0, faults=0;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    int pages[n];
    printf("Enter page reference string:\n");
    for(i=0;i<n;i++) scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&frames);
    int frame[frames];
    for(i=0;i<frames;i++) frame[i] = -1;

    for(i=0;i<n;i++){
        int found=0;
        for(j=0;j<frames;j++) if(frame[j]==pages[i]) found=1;
        if(!found){
            frame[k] = pages[i];
            k = (k+1) % frames;
            faults++;
        }
        for(j=0;j<frames;j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Total page faults = %d\n", faults);
    return 0;
}
