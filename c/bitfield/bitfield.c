
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>


typedef struct {
    uint8_t one;
    uint8_t two;
    uint8_t three;
    uint8_t four;
} header1_t;

typedef struct {
    uint8_t one:2;
    uint8_t two:2;
    uint8_t three:4;
} header2_t;


int main(int argc, char *argv[])
{
    header1_t h1;
    header2_t h2;

    printf("size of h1: %lu.\n", sizeof(h1));
    printf("size of h2: %lu.\n", sizeof(h2));

    exit(EXIT_SUCCESS);
}
