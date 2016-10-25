
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int i;

    printf("Testing for loop: ...\n");

    for (i = 0; i < 5; i++) {
        printf("Value of i: %d.\n", i);
    }

    exit(EXIT_SUCCESS);
}
