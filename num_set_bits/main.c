#include <stdio.h>

#include "num_set_bits.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

#define UNSIGNED_INT_TO_BINARY_PATTERN BYTE_TO_BINARY_PATTERN BYTE_TO_BINARY_PATTERN BYTE_TO_BINARY_PATTERN BYTE_TO_BINARY_PATTERN

int main() {
    unsigned int a = 11;

    printf(UNSIGNED_INT_TO_BINARY_PATTERN"\n",
           BYTE_TO_BINARY(a >> 24),
           BYTE_TO_BINARY(a >> 16),
           BYTE_TO_BINARY(a >> 8),
           BYTE_TO_BINARY(a));

    int set_bits = num_set_bits(a);

    printf("%d", set_bits);

    return 0;
}
