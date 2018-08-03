#include <memory.h>
#include "first_not_repeating_char.h"

/**
 * Removes duplicates in-place. With teo pointers, i is pointing to our reference char,
 * j is looking duplicates. When it finds one, it replaces with a space char and continue
 * looking up to the end of the array.
 * Then move the char reference until the next valid char and look for duplicates again.
 *
 * When j reaches the end of the array and there were no duplicates; return chat at i
 *
 * Special case when length is 1, no room for duplicates
 *
 * @param s
 * @return
 */
char first_not_repeating_char(char *s) {
    int i = 0;
    int j = 1;

    int duplicates = 0;

    size_t length = strlen(s);
    while (i < length && j < length) {
        if (s[i] == s[j]) {
            s[j] = ' ';
            duplicates++;
        }

        if (++j >= length) {
            if (duplicates == 0) {
                return s[i];
            }
            do {
                j = ++i + 1;
            } while (i < length && s[i] == ' ');
            duplicates = 0;
        }
    }
    return length == 1 ? s[0] : '_';
}
