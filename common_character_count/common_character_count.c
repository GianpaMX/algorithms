#include <memory.h>
#include <stdlib.h>
#include "common_character_count.h"

int charcmp(const void *a, const void *b);

char *copy_and_sort(const char *s);

/**
 * If we sort both strings we can have two pointers following
 * common characters in each string so i follows s1 characters
 * and j follows s2.
 *
 * "aabcc" is already sorted, "adcaa" becomes
 * "aaadc"
 *
 * i and j will move together until i points to 'b'
 *
 * Then the smaller character pointer will move forward until
 * it matches the other or become the the smallest character pointer
 *
 * This O(n) because we have to iterate over the input to copy and
 * with the pointers. qsort complexity is assumed to be O(n log n) so
 * we ignore it
 *
 * @param s1
 * @param s2
 * @return
 */
int common_character_count(const char *s1, const char *s2) {
    int counter = 0;

    char *ss1 = copy_and_sort(s1), *i = ss1;
    char *ss2 = copy_and_sort(s2), *j = ss2;

    while (*i != 0 && *j != 0) {
        if (*i == *j) {
            i++;
            j++;
            counter++;
        } else if (*i < *j) {
            i++;
        } else {
            j++;
        }
    }

    free(ss1);
    free(ss2);

    return counter;
}

char *copy_and_sort(const char *s) {
    char *ss = malloc(strlen(s) * sizeof(char));
    strcpy(ss, s);
    qsort(ss, strlen(ss), sizeof(char), charcmp);
    return ss;
}

int charcmp(const void *a, const void *b) {
    return (*(char *) a - *(char *) b);
}
