#include <stdio.h>
int empty, full = 0, mutex = 1;
void wait(int *s) { (*s)--; }
void signal(int *s) { (*s)++; }
int main() {
    printf("Enter buffer size: ");
    scanf("%d", &empty);

    printf("\n1. Produce\n2. Consume\nEnter choice: ");
    int ch;
    scanf("%d", &ch);

    if(ch == 1) {
        if(empty > 0) {
            wait(&empty); wait(&mutex);
            printf("Item Produced\n");
            signal(&mutex); signal(&full);
        } else printf("Buffer Full\n");
    }
    else if(ch == 2) {
        if(full > 0) {
            wait(&full); wait(&mutex);
            printf("Item Consumed\n");
            signal(&mutex); signal(&empty);
        } else printf("Buffer Empty\n");
    }
    return 0;
}
