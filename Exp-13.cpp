#include <stdio.h>
int main() {
    int blocks[3] = {100, 500, 200};
    int process[3] = {120, 50, 80};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(blocks[j] >= process[i]){
                printf("Process %d allocated to Block %d\n", i+1, j+1);
                blocks[j] -= process[i];
                break;
            }
        }
    }
    return 0;
}
