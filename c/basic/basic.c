
#include "basic.h"


int main(int argc, char *argv[])
{
    u_int8_t i8;
    u_int8_t *pi8;

    i8 = 0x81;
    pi8 = &i8;

    printf("%x\n", *pi8);

    exit(EXIT_SUCCESS);
}
