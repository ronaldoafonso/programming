
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *
thread1(void *arg)
{
    int i;
    unsigned int *time = (unsigned int *)arg;

    for (i = 0; i < 5; i++) {
        if (pthread_mutex_lock(&mtx) == 0) {
            glob++;
            printf("From thread1 - (Glob %d) - Sleeping ...\n", glob);
            pthread_mutex_unlock(&mtx);
        }
        sleep(*time);
    }

    return (void *) time;
}

static void *
thread2(void *arg)
{
    int i;
    unsigned int *time = (unsigned int *)arg;

    for (i = 0; i < 5; i++) {
        if (pthread_mutex_lock(&mtx) == 0) {
            glob++;
            printf("From thread2 - (Glob %d) - Sleeping ...\n", glob);
            pthread_mutex_unlock(&mtx);
        }
        sleep(*time);
    }

    return (void *) time;
}

int main(int argc, char *argv[])
{
    pthread_t thr1, thr2;
    int rc;
    int time1 = 1, time2 = 2;
    void *thr1_rc = NULL, *thr2_rc = NULL;

    rc = pthread_create(&thr1, NULL, thread1, &time1);
    if (rc != 0) {
        perror("pthread_create 1");
        exit(EXIT_FAILURE);
    }

    rc = pthread_create(&thr2, NULL, thread2, &time2);
    if (rc != 0) {
        perror("pthread_create 2");
        exit(EXIT_FAILURE);
    }

    printf("Waiting threads  ...\n");

    rc = pthread_join(thr1, thr1_rc);
    if (rc != 0) {
        perror("pthread_join 1");
        exit(EXIT_FAILURE);
    }

    rc = pthread_join(thr2, thr2_rc);
    if (rc != 0) {
        perror("pthread_join 2");
        exit(EXIT_FAILURE);
    }

    printf("Thread 1 returned: %ld.\n", (long) thr1_rc);
    printf("Thread 2 returned: %ld.\n", (long) thr2_rc);
    exit(EXIT_SUCCESS);
}
