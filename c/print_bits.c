#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


int print_bits(const unsigned n) {
    size_t bits;
    char *buf;
    int rc, i;
    
    bits = (sizeof n) * CHAR_BIT;
    buf = malloc(bits + 1);
    if (!buf) return -1;

    for (i = 0; i < bits; i++)
        buf[i] = (n & (1 << (bits - i - 1))) ? '1' : '0';

    rc = printf("0b%s\n", buf);
    free(buf);
    return rc;
}
