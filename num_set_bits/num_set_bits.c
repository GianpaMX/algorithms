#include "num_set_bits.h"

int num_set_bits(unsigned int a) {
    int set_bits = 0;
    while (a > 0) {
        set_bits += (a & 1);
        a >>= 1;
    }
    return set_bits;
}
