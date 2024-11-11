#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;
int read_count = 0;
int shared_data = 0;

void *writer(void *wno) {
    sem_wait(&wrt);  
    shared_data += 1;
    printf("Writer %d wrote data: %d\n", *((int *)wno), shared_data);

    sem_post(&wrt);  
}

void *reader(void *rno) {
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1)
        sem_wait(&wrt);  
    sem_post(&mutex);

    // Reading section
    printf("Reader %d read data: %d\n", *((int *)rno), shared_data);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0)
        sem_post(&wrt);  
    sem_post(&mutex);
}

int main() {
    pthread_t read[5], write[3];
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    int reader_nums[5] = {1, 2, 3, 4, 5};
    int writer_nums[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        pthread_create(&write[i], NULL, writer, &writer_nums[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_create(&read[i], NULL, reader, &reader_nums[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(write[i], NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(read[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}

