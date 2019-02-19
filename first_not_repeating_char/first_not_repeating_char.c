#include <string.h>
#include "first_not_repeating_char.h"

static const int ALPHABET_SIZE = 26;

/**
 * This solution iterates over the string once and uses O(1) additional memory.
 *
 * Since we are only receiving chars from 'a' to 'z', we declare an array for
 * counting instances of each character in the alphabet. We also save first position
 * in the string.
 *
 * By the end we just iterate over the positions array searching for the smallest one.
 *
 * @param s
 * @return
 */
char first_not_repeating_char(char *s) {
    char instances[ALPHABET_SIZE];
    int positions[ALPHABET_SIZE];

    int s_len = (int) strlen(s);

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        instances[i] = 0;
        positions[i] = s_len;
    }

    for (int i = 0; i < s_len; i++) {
        int index = s[i] - 97;  // ASCII for 'a'
        instances[index] += 1;
        if (i < positions[index]) {
            positions[index] = i;
        }
    }

    int first_no_repeating = s_len;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (instances[i] == 1 && positions[i] < first_no_repeating) {
            first_no_repeating = positions[i];
        }
    }

    return first_no_repeating == s_len ? '_' : s[first_no_repeating];
}
