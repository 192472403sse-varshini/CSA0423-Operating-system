#include <stdio.h>
int mutex = 1;
void wait(int *s){ (*s)--; }
void signal(int *s){ (*s)++; }
int main() {
    int choice;
    printf("1. Enter Critical Section\n2. Exit\nChoice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        if(mutex == 1) {
            wait(&mutex);
            printf("Process Entered Critical Section\n");
        } else printf("Critical Section Busy\n");
    } else {
        signal(&mutex);
        printf("Process Exited\n");
    }
}
