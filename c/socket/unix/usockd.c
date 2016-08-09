
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define BUF_SIZE 32


int main(int argc, char *argv[])
{
    struct sockaddr_un addr;
    const char *sockname = "/tmp/usock";
    int sfd, cfd, rc, nread;
    char buffer[BUF_SIZE];


    sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, sockname, sizeof(addr.sun_path));

    rc = bind(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un));
    if (rc == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    rc = listen(sfd, 5);
    if (rc == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        fprintf(stdout, "Waiting ...\n");
        cfd = accept(sfd, NULL, NULL);
        if (cfd == -1) {
            perror("accept");
            break;
        }

        memset(buffer, '\0', BUF_SIZE);
        nread = read(cfd, buffer, BUF_SIZE);

        rc = close(cfd);
        if (rc == -1) {
            perror("close");
        }

        if (nread > 1) {
            fprintf(stdout, "Read: %s", buffer);
        } else {
            break;
        }
    }

    rc = close(sfd);
    if (rc == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    rc = unlink(sockname);
    if (rc == -1) {
        perror("unlink");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
