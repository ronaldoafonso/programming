
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>


static void hup_handler(int signum);

static volatile sig_atomic_t hup_received = 0;


static void hup_handler(int signum)
{
    hup_received = 1;
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    int unslept = 0;

    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = hup_handler;

    if (sigaction(SIGHUP, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {

        if (hup_received) {
            printf("HUP Received.\n");
        }

        if (unslept == 0) unslept = 10;

        printf("Sleeping ...\n");
        unslept = sleep(unslept);

        printf("Sleep: %d.\n", unslept);
    }
    exit(EXIT_SUCCESS);
}
