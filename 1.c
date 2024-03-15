#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function to be executed by each thread
void *printHello(void *threadID) {
    long tid;
    tid = (long)threadID;
    printf("Hello from thread %ld\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Create threads
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, printHello, (void *)t);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads completed.\n");

    pthread_exit(NULL);
}
