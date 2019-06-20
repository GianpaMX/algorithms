#include <memory.h>
#include <stdio.h>
#include "line_encoding.h"

void encode(char *r, int counter, const char *c);

/**
 * Iterate over s counting identical characters when we find a different one we
 * encode the characters we got so far and repeat the process
 *
 * @param s
 * @param result
 */
void line_encoding(const char *s, char *result) {
    *result = '\0';
    size_t s_len = strlen(s);

    int counter = 0;
    const char *c = s;
    char *r = result;
    for (int i = 0; i < s_len; i++) {
        if (*c == s[i]) {
            counter++;
        } else {
            encode(r, counter, c);
            c = s + i;
            counter = 1;
        }
    }
    encode(r, counter, c);
}

void encode(char *r, int counter, const char *c) {
    if (counter == 1) {
        sprintf(r + strlen(r), "%c", *c);
    } else {
        sprintf(r + strlen(r), "%d%c", counter, *c);
    }
}
