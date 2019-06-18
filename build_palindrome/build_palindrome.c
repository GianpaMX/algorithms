#include <string.h>
#include <stdbool.h>
#include "build_palindrome.h"

bool is_palindrome(char *palindrome);

/**
 * Starts adding one by one reversed st characters to a copy of itself until
 * it's a palindrome
 *
 * @param st
 * @param palindrome
 */
void build_palindrome(const char *st, char *palindrome) {
    int i = 0, j;
    int len = (int) strlen(st);

    strcpy(palindrome, st);
    while (!is_palindrome(palindrome)) {
        for (j = 0; j < i + 1; j++) {
            palindrome[len + j] = st[i - j];
        }
        palindrome[len + j] = '\0';

        i++;
    }
}

bool is_palindrome(char *palindrome) {
    size_t l = strlen(palindrome);
    for (int i = 0; i < l / 2; i++) {
        if (palindrome[i] != palindrome[l - i - 1]) return false;
    }
    return true;
}
