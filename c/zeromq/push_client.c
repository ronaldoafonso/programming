
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <zmq.h>


int main(int argc, char *argv[])
{
    void *context;
    void *sock;
    int rc, i, hwm = 10;
    char message[16];
   
    context = zmq_ctx_new();
    if (!context) goto error;

    sock = zmq_socket(context, ZMQ_PUSH);
    if (!sock) goto error;

    rc = zmq_setsockopt(sock, ZMQ_SNDHWM, &hwm, sizeof(hwm));
    if (rc == -1) goto error;

    rc = zmq_connect(sock, "tcp://zmq.ronaldoafonso.com.br:5555");
    if (rc == -1) goto error;    

    for (i = 0; i < 20; i++) {
        memset(message, '\0', 16);
        sprintf(message, "Message %d", i);
        printf("Sending [%s].\n", message);
        zmq_send(sock, message, strlen(message), 0); 
    }

    zmq_close(sock);
    zmq_ctx_destroy(context);
    exit(EXIT_SUCCESS);

error:
    perror("Error: ");
    if (sock) zmq_close(sock);
    if (context)   zmq_ctx_destroy(context);
    exit(EXIT_FAILURE);
}
