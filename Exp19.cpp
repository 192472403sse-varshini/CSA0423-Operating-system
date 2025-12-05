#include <stdio.h>
#include <pthread.h>
int counter = 0;
pthread_mutex_t lock;
void* run(void* arg) {
    int v = *(int*)arg;
    pthread_mutex_lock(&lock);
    counter += v;
    printf("Thread added %d ? Counter = %d\n", v, counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main() {
    pthread_t t1, t2;
    int a, b;

    pthread_mutex_init(&lock, NULL);

    printf("Enter value added by Thread 1: ");
    scanf("%d", &a);
    printf("Enter value added by Thread 2: ");
    scanf("%d", &b);

    pthread_create(&t1, NULL, run, &a);
    pthread_create(&t2, NULL, run, &b);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
