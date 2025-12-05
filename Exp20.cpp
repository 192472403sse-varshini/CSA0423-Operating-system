#include <stdio.h>
int readcount = 0;
int mutex = 1, rw = 1;
void wait(int *s){ (*s)--; }
void signal(int *s){ (*s)++; }
int main() {
    int choice;
    printf("1. Reader\n2. Writer\nEnter choice: ");
    scanf("%d", &choice);
    if(choice == 1) {
        wait(&mutex);
        readcount++;
        if(readcount == 1) wait(&rw);
        signal(&mutex);

        printf("Reader is reading...\n");

        wait(&mutex);
        readcount--;
        if(readcount == 0) signal(&rw);
        signal(&mutex);

        printf("Reader exits.\n");
    }
    else {
        wait(&rw);
        printf("Writer is writing...\n");
        signal(&rw);
        printf("Writer exits.\n");
    }
    return 0;
}
