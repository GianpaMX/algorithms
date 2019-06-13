#include <stdio.h>

#include "bits_insertion.h"

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

int main() {
    int N = 0b10000000000;
    int M = 0b10011;
    int i = 2;
    int j = 6;

    bits_insertion(&N, M, i, j);

    printf("N = "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN"\n",
           BYTE_TO_BINARY(N >> 24), BYTE_TO_BINARY(N >> 16),
           BYTE_TO_BINARY(N >> 8), BYTE_TO_BINARY(N));

    return 0;
}
