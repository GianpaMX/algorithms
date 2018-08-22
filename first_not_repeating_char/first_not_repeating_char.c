#include <memory.h>
#include <btree.h>

#include "first_not_repeating_char.h"

struct counter {
    char val;
    int count;
};

int counter_hash(const void *c);

char first_not_repeating_char(char *s) {
    int i = 0;
    int j = 1;

    btree *duplicates = btree_init(&counter_hash);

    size_t length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (duplicates->contains(duplicates, s[i])) {

        }
    }
}

int counter_hash(const void *c) {
    return (int) ((struct counter *) c)->val;
}
