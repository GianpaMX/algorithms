#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "substring_permutations.h"

void print_chars(const char *c, size_t size);

int main() {
    const char *s = "abbc";
    const char *b = "cbabadcbbabbcbabaabccbabc";

    printf("%s\n", s);
    printf("%s\n", b);

    size_t s_len = strlen(s);
    size_t b_len = strlen(b);
    int *locations = malloc((b_len + 1 - s_len) * sizeof(int));

    int permutations = substring_permutations(s, b, locations);

    for (int i = 0; i < permutations; i++) {
        int location = locations[i];
        printf("%d ", location);
        print_chars(b + location, s_len);
        printf("\n");
    }

    free(locations);

    return 0;
}

void print_chars(const char *c, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%c", c[i]);
    }
}
