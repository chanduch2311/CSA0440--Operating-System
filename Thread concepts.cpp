#include <stdio.h>
#include <pthread.h>

void *printMessage(void *arg) {
    printf("Thread ID: %ld says hello!\n", pthread_self());
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

 
    pthread_create(&thread1, NULL, printMessage, NULL);
    pthread_create(&thread2, NULL, printMessage, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    if (pthread_equal(thread1, thread2)) {
        printf("Threads are equal\n");
    } else {
        printf("Threads are not equal\n");
    }

    return 0;
}

