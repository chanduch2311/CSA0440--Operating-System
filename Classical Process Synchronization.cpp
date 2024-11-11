#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full;
pthread_mutex_t mutex;

int buffer[5];
int count = 0;

void *producer(void *arg) {
    int item = *(int *)arg;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    buffer[count++] = item;
    printf("Produced item: %d\n", item);

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void *consumer(void *arg) {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    int item = buffer[--count];
    printf("Consumed item: %d\n", item);

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main() {
    pthread_t prod[3], cons[3];
    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    int items[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        pthread_create(&prod[i], NULL, producer, &items[i]);
        pthread_create(&cons[i], NULL, consumer, NULL);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(prod[i], NULL);
        pthread_join(cons[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}

