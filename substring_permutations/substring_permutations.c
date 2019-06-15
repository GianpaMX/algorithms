#include <memory.h>
#include <stdlib.h>

#include "substring_permutations.h"

void sort_string(const char *s, int s_len, char *sorted_s);

int chrcmp(const void *a, const void *b);

/**
 * Iterates over b finding permutations of s
 *
 * @param s
 * @param b
 * @param locations
 * @return
 */
int substring_permutations(const char *s, const char *b, int *locations) {
    int s_len = (int) strlen(s);

    char *sorted_sub_b = malloc(s_len * sizeof(char) + 1);
    sorted_sub_b[s_len] = '\0';

    char *sorted_s = malloc(s_len * sizeof(char) + 1);
    sorted_s[s_len] = '\0';
    sort_string(s, s_len, sorted_s);

    int l = 0;
    for (int i = 0; i < strlen(b) - s_len + 1; i++) {
        sort_string(b + i, s_len, sorted_sub_b);

        if (strcmp(sorted_s, sorted_sub_b) == 0) {
            locations[l++] = i;
        }
    }

    free(sorted_s);
    free(sorted_sub_b);

    return l;
}

void sort_string(const char *s, int s_len, char *sorted_s) {
    memcpy(sorted_s, s, s_len * sizeof(char));
    qsort(sorted_s, s_len, sizeof(char), chrcmp);
}

int chrcmp(const void *a, const void *b) {
    return *(char *) a - *(char *) b;
}

