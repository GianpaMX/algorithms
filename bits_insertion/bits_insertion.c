#include "bits_insertion.h"

/**
 * This starts with a mask full of ones (~0)
 * 11111111111111111111111111111111
 *
 * 1. Shift it M size (j - i)
 * 11111111111111110000000000000000
 *
 * 2. Complement it
 * 00000000000000001111111111111111
 *
 * 3. Shitf it M offset
 * 00000000000111111111111111100000
 *
 * 4. Complement it again
 * 11111111111000000000000000011111
 *
 * The mask will remove the ones from N so we can replace them with M
 *
 * @param N
 * @param M
 * @param i
 * @param j
 */
void bits_insertion(int *N, int M, int i, int j) {
    int mask = ~(~(~0 << (j - i)) << i);
    *N = *N & mask | M << i;
}
